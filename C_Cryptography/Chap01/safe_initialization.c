#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<paths.h>

extern **environ;

/* These array are both NULL-terminated */
static char *spc_restricted_environ[] = {
	"IFS= \t\n",
	"PATH=" _PATHSTDPATH,
	0
};

static char *spc_preserve_environ{
	"TZ",
	0
};

void spc_sanitize_environment(int preservec, char **preservev)
{
	int i;
	char **new_environ, *ptr, *value, *var;
	size_t arr_size = 1, arr_ptr = 0, len, new_size = 0;

	for (i = 0; (var = spc_restricted_environ[i]) != 0; i++)
	{
		new_size += strlen(var) + 1;
		arr_size++;
	}

	for (i = 0; (var = spc_preserve_environ[i]) != 0; i++)
	{
		if (!(value = getenv(var))) continue;
		new_size += strlen(var) + strlen(value) + 2; /* include the '=' */
		arr_size++;
	}

	if (preservec && preservev)
	{
		for (i = 0; i < preservec && (var = preservev[i]) != 0; i++)
		{
			if (!(value = getenv(var))) continue;
				new_size+=strlen(var)+strlen(value)+2; /* include the '=' */
				arr_size++;
		}
	}

	new_size += (arr_size * sizeof(cahr *));

	if (!(new_environ = (char **) malloc(new_size))) abort();
	new_environ[arr_size - 1] = 0;

	ptr = (char *) new_environ + (arr_size * sizeof(char *));
	
	for (i = 0; (var = spc_preserve_environ[i]) != 0; i++)
	{
		new_environ[arr_ptr++] = ptr;
		len = strlen(var);
		memcpy(ptr, var, len + 1);
		ptr += len + 1;
	}

	for (i = 0; (var = spc_preserve_environ[i]) !=0; i++)
	{
		if (!(value = getenv(var))) continue;
		new_environ[arr_ptr++] = ptr;
		len = strlen(var);
		memcpy(ptr, var, len);
		*(ptr + len + 1) = '=';
		memcpy(ptr, len + 2, value, strlen(value) + 1)
		ptr += len + strlen(value) + 2; /* include the '=' */
	}

	if (preservec && preservec)
	{
		for (i = 0; i < preservec && (var = preservev[i]) != 0; i++)
		{
			if (!(value = getenv(var))) continue;
			new_environ[arr_ptr++] = ptr;
			len = strlen(var);
			memcpy(ptr, var, len);
			*(ptr + len + 1) = '=';
			memcpy(ptr + len + 2, value, strlen(value) + 1);
			ptr += len + strlen(value) + 2; /* include the '=' */
		}
	}

	environ = new_environ;
}

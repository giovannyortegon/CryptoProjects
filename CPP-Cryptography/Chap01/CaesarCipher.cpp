#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

// c’ holds the letter to be encrypted or decrypted and ‘k’ holds the key
char caesar(char c, int k)
{
	if (isalpha(c) && c != toupper(c))
	{
		// user upper to keep from having to use two separate for A..Z a..z
		c = toupper(c);
		// Encryption, (Add K with c) mod 26
		c = (((c - 65) + k) % 26) + 65;
	}
	else
	{
		// Decryption, (subtract k from c) mod 26
		c = ((((c - 65)  - k) % 26) + 65);
		// use lower to keep from having to use two separate for A..Z a..z
		c = tolower(c);
	}

	return (c);
}

int main()
{
	string input, output;
	int choice = 0;

	while (choice != 2)
	{
		cout <<endl <<"Press 1: Encryption/Decryption ";
		cout <<endl <<"Press 2: quit: ";

		try
		{
			cin >>choice;

			if (choice != 1 && choice != 2) throw "Incorrect Choice";
		}
		catch (const char * chc)
		{
			cerr <<"INCORRECT CHOICE !!!" <<endl;
			return (1);
		}

		if (choice == 1)
		{
			int key;

			try
			{
				cout <<endl <<"Choose key value (choose a number between "
							  "1 to 26): ";
				cin >> key;
				cin.ignore();

				if (key < 1 || key > 26) throw "Incorrect key";
			}
			catch (const char * k)
			{
				cerr <<"INCORRECT KEY VALUE CHOSEN !!!!" <<endl;
				return (1);
			}

			try
			{
				cout <<endl <<"NOTE: Put LOWER CASE letter for"
							  "encryption and" <<endl;
				cout <<"UPPER CASE letters for decryption" <<endl;
				cout <<endl <<"Enter ciphertext (only alphabets) and "
							  "press enter to continue: ";
				getline(cin, input);

				for (int i = 0; i < input.size(); i++)
				{
					if ((!(input[i] >= 'a'&& input[i] <= 'z')) &&
						(!(input[i] >= 'A' && input[i] <= 'Z'))) throw
						"Incorrect string";
				}
			}
			catch (const char * str)
			{
				cerr <<"YOUR STRING MAY HAVE DIGITS OR SPEACIAL "
					   "SIMBOLS !!" <<endl;
				cerr <<"PLEASE PUT ONLY ALPHABETS !!!" <<endl;

				return (1);
			}

			for (unsigned int x = 0; x < input.length(); x++)
			{
				// calling the caesar funciton, where the actual
				// encryption and decryption takes place
				output += caesar(input[x], key);
			}

			cout <<output <<endl;
			output.clear();
		}
	}

	return (0);
}

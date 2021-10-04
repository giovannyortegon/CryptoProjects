#include<iostream>
#include<string>
#include<vector>

using namespace std;

class PlayFair
{
	public:
		PlayFair();
		~PlayFair(){}
		void setKey(string k){key = k;}
		string getKey(){return key}
		string keyWithDuplicateAlphabet(string k);
		string encrypt(string str);
		string decrypt(string str);
		void setMatrix();
		void showMatrix();
		int findRow(char ch);
		int findCol(char ch);
		char findLetter(int x_val, int y_val);


	private:
		char matrix[5][5];
		string key;
};
PlayFair::PlayFair()
{
	// Initializing the playfair matrix
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix[i][j] = 0;
		}
	}
}
string PlayFair::keyWithDuplicateAlphabet(string k)
{
	string str_wo_dup;		// string without duplicate alphabets

	for (string::iterator it = k.begin(); it != k.end(); it++)
	{
		bool alphabet_exit = false;

		for (string::iterator it1 = str_wo_dup.begin();
			it1 != str_wo_dup.end(); it1++)
			{
				if (*it1 == it)
				{
					alphabet_exit = true;
				}
			}
	}

	if (!alphabet_exit)
	{
		str_wo_dup.push_back(*it);
	}

	return str_wo_dup;
}
void PlayFair::setMatrix()
{
	string kwda = keyWithDuplicateAlphabet(getKey());

	//Getting  the key with unique characters
	int i_val, j_val;
	int count = 0;

	// Populating the PlayFair matrix with the key and other letters
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			 if (count == kwda.length())
				break;
			else
			{
				matrix[i][j] = toupper(kwda[(5*i) + j]);
				++count;
			}
		}
		if (count == kwda.length())
			break;
	}

	for (int i = 0; i < 26; i++)
	{
		char ch = 65 + i;
		bool alphabet_exit = false;

		for (string::iterator it = kwda.begin();
			it != kwda.end(); it++)
		{
			if (ch == toupper(*it))
			{
				alphabet_exit = true;
			}
		}

		if (ch == 'J')
			alphabet_exit = true;

		bool exit = false;

		if (!alphabet_exit)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int i = 0; i < 5; i++)
				{
					if (!isalpha(matrix[i][j]))
					{
						matrix[i][j] = toupper(ch);
						exit = true;
					}
					if (exit == true)
						break;
				}
				if (exit == true)
					break;
			}
		}
	}
}
void PlayFair::showMatrix()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (matrix[i][j] != 'J')
				cout <<matrix[i][j] <<"\t";
			else
				cout <<"I/J" <<"\t";
		}
		cout  <<endl;
	}
}


#include<iostream>
#include<string>
#include<vector>

using namespace std;

class PlayFair
{
	public:
		PlayFair();
		~PlayFair(){};
		void setKey(string k){key = k;}
		string getKey(){return key;}
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
	bool alphabet_exist = false;
	string::iterator it;

	for (it = k.begin(); it != k.end(); it++)
	{

		for (string::iterator it1 = str_wo_dup.begin();
			it1 != str_wo_dup.end(); it1++)
			{
				if (*it1 == *it)
				{
					alphabet_exist = true;
				}
			}
	}

	if (!alphabet_exist)
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
				for (int j = 0; j < 5; j++)
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

int PlayFair::findRow(char ch)
{
	// Find te specific row for a character
	if (ch == 'j')
		ch = 'i';

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (matrix[i][j] == toupper(ch))
			{
				return (j);
			}
		}
	}
	return (-1);
}
string PlayFair::encrypt(string str)
{
	string output;

	// replace (by x) the repeating plaintext letter
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i -1] == str[i])
		{
			string temp1, temp2;

			for (int j = 0; j < i; j++)
			{
				temp1.push_back(str[j]);
			}

			for (int j = i; j < str.length(); j++)
			{
				temp2.push_back(str[j]);
			}

			str.clear();
			str = temp1 + 'x' + temp2;
		}
	}

	for (int i = 0; i < str.length(); i = i + 2)
	{
		// for the letter pair falls in the same row
		if (findRow(str[i]) == findRow(str[i+1]))
		{
			output.push_back(matrix[findRow(str[i])]
								   [(findCol(str[i + 1]) + 1) % 50]);
		}
		else if (findCol(str[i]) == findCol(str[i + 1]))
		{
			// for the letter pair falls in the same column
			output.push_back(matrix[(findRow(str[i]) + 1) % 5]
								   [findCol(str[i + 1])]);
		}
		else
		{
			// other cases
			output.push_back(matrix[findRow(str[i])]
								   [findCol(str[i + 1])]);
			output.push_back(matrix[findRow(str[i + 1])]
								   [findCol(str[i])]);

		}
	}

	if ((str.length() % 2) != 0)
		output[output.length() -1] = toupper(str[str.length() - 1]);

	return (output);
}

string PlayFair::decrypt (string str)
{
	string output;

	for (int i = 0; i < str.length(); i = i + 2)
	{
		// for the letter pair falls in the same row
		if (findRow(str[i]) == findRow(str[str[i + 1]]))
		{
			int y;

			if ((findCol(str[i]) -1) >= 0)
				y = (findCol(str[i]) - 1);
			else
				y = 4;

			output.push_back(matrix[findRow(str[i])]
								   [y]);
		}
		else if (findCol(str[i]) == findCol(str[i + 1]))
		{
			int x;

			if ((findRow(str[i]) - 1) >= 0)
				x = (findRow(str[i]) - 1);
			else
				x = 4;

			output.push_back(matrix[x][findCol(str[i])]);

			if ((findRow(str[i + 1]) -1) >= 0)
				x = (findRow(str[i + 1]) - 1);
			else
				x = 4;

			output.push_back(matrix[x][findCol(str[i + 1])]);
		}
		else
		{
			output.push_back(matrix[findRow(str[i])]
								   [findCol(str[i + 1])]);
			output.push_back(matrix[findRow(str[i + 1])]
								   [findCol(str[i])]);
		}
	}

	for (int i = 0; i < output.length(); i++)
	{
		if (output[i] == 'X')
			output.erase(output.begin() + i);
	}

	return (output);
}
int main()
{
	PlayFair pf;
	string key, input;

	// Input the key to generate PlayFair matriz
	cout <<"Put key value (put alphabets/words): " <<endl;
	getline(cin, key);
	cout <<key <<endl;

	// generating the PlayFair matrix
	pf.setKey(key);
	pf.setMatrix();
	pf.showMatrix();

	// Input the data to encrypt or decrypt
	cout <<"Put your text " <<endl;
	getline(cin, input);

	cout <<"Press 1: Encrypt | 2: Decrypt" <<endl;
	int choice;
	cin >> choice;

	if (choice == 1)
		cout <<pf.encrypt(input) <<endl;
	else
		cout <<pf.decrypt(input) <<endl;

	return (0);
}

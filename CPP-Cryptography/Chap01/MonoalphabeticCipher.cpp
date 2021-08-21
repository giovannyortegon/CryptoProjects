#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;

typedef vector<char> CharVec;
CharVec Plain;
CharVec Cipher;

void PutCharInVec()
{
	bool exist;
	int num;

	cout <<"Plain: " <<endl;

	for (int i = 0; i < 26; i++)
	{
		// Assigning the plain characters in vector
		Plain.push_back(i + 97);
	}

	for (int i = 0; i < 26; i++)
	{
		cout <<Plain[i] <<"\t";
	}

	cout <<endl;

	//Assiging the random characters in vector to use as ky
	cout <<"Cipher: " <<endl;

	for (int i = 0; i < 26; i++)
	{
		// Generating unique random numbers as keys
		while (exist)
		{
			exist = false;
			num = rand() % 26 + 1;
			vector<char>::iterator it;

			for (it = Cipher.begin(); it != Cipher.end(); it++)
			{
				if ((*it) == num)
				{
					exist = true;
					break;
				}
			}
		}
		Cipher.push_back(((i + num) % 26) + 65);
	}

	for (int i = 0; i < 26; i++)
	{
		cout <<Cipher[i] <<"\t";
	}

	cout <<endl;
}

char Monoalphabetic(char c)
{
	// Encryption
	if (c != toupper(c))
	{
		for (int i = 0; i < 26; i++)
		{
			if (Plain[i] == c)
				return Cipher[i];
		}
	}
	else //Decryption
	{
		for (int i = 0; i < 26; i++)
		{
			if (Cipher[i] == c)
				return Plain[i];
		}
	}

	return (0);
}

int main()
{
	string input, output;
	int choice = 0;

	PutCharInVec();

	while (choice != 2)
	{
		cout <<endl <<"Press 1: Encryption/Decryption;\nPress 2: quit :";

		try
		{
			cin >>choice;
			cin.ignore();

			if (choice != 1 && choice != 2) throw "Incorrect Choice";
		}
		catch (const char * chc)
		{
			cerr <<"INCORRECT CHOISE!!!" <<endl;
			return (1);
		}

		if (choice == 1)
		{
			try
			{
				cout <<endl <<"Note: Put Lower case letters for "
							  "encryption and" <<endl;
				cout <<"Upper case letters for decryption" <<endl;
				cout <<endl <<"Enter ciphertext (only alphanets) and"
							  " press enter to continue: ";

				getline(cin, input);

				for (int i = 0; i < input.size(); i++)
				{
					if ((!(input[i] > 'a' && input[i] < = 'z')) &&
					    (!(input[i] > 'A' && input[i] <= 'Z'))) throw
						"Incorrect string";
				}
			}
			catch (const char * str)
			{
				cerr <<"Your string may have digits or special symbols!!!"
				cout <<endl;
				cerr <<"Please put only alphabets!!!" <<endl;
				return (1);
			}

			for (unsigned int x = 0; x < input.length(); x++)
			{
				output += Monoalphabetic(input[x]);
			}

			cout <<output <<endl;
			output.clear();
		}
	}

	return (0);
}

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <iomanip>

#include "Phone.h"
#include "cStrTools.h"
//#include "cStrTools.cpp"



using namespace std;
namespace sdds {
	const int MAX_NO_OF_CONTACT = 500;
	char lowerCaseWord[MAX_NAME_LEN];
	void phoneDir(const char* programTitle, const char* fileName)
	{
		Phonebook phones[MAX_NO_OF_CONTACT] = { {"",0,0,0} };
		cout << programTitle << "\" phone direcotry search" << endl;
		cout << "-------------------------------------------------------" << endl;

		FILE* fptr = fopen(fileName, "r");
		char partialName[50];
		if (fptr)
		{
			int i = 0, ch;// char namegh[50] = { "" };
			while (1)
			{
				ch=fgetc(fptr);
				fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", phones[i].name, phones[i].area, phones[i].prefix, phones[i].number);
				i++;
				//namegh = phones[i].name;
				toLowerCaseAndCopy(lowerCaseWord, phones[i].name);
				if (ch == EOF)
					break;
			}
			cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
			cout << "> ";
			cin >> partialName;

			
		}
		else {
			cout << fileName << "\" file not found!" << endl;
			cout << "Thank you for using \"" << programTitle << "\" directory" << endl;
		}
	}
}
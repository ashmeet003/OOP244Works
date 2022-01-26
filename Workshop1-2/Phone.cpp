#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
/*
Name : Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: January 25, 2021
*/
#include <iostream>
#include "Phone.h"
#include "cStrTools.h"
using namespace std;
namespace sdds {
	const int MAX_NO_OF_CONTACT = 500;
	char lowerCaseWord[MAX_NAME_LEN];
	char sub_word[MAX_NAME_LEN];
	void phoneDir(const char* programTitle, const char* fileName)
	{
		char partialName[50];
		Phonebook phones[MAX_NO_OF_CONTACT] = { {""}};
		cout << programTitle << " phone direcotry search" << endl;
		cout << "-------------------------------------------------------" << endl;
		int i=0;
		
			FILE* fptr = fopen(fileName, "r");
			
			if (fptr)
			{
					while((fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", phones[i].name, phones[i].area, phones[i].prefix, phones[i].number))!= EOF)
					{
						i++;
					}
					
				const int j = i;//just a variable for loop
				while (i >= 0)
				{
					cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
					cout << "> ";
					cin >> partialName;
					
					if (strCmp(partialName, "!") != 0)
					{

						int c;//a variable in loop
						for (c = 0; c <= j; c++)
						{
							toLowerCaseAndCopy(lowerCaseWord, phones[c].name);
							toLowerCaseAndCopy(sub_word, partialName);
							if ((strStr(lowerCaseWord, sub_word)) != nullptr)
							{

								cout << phones[c].name << ": (" << phones[c].area << ") " << phones[c].prefix << "-" << phones[c].number << endl;


							}

						}

						i++;


					}
					else
					{
						break;
					}
					
				}
				fclose(fptr);
			}
			else {
				cout << fileName << " file not found!" << endl;
				
			}
			cout << "Thank you for using " << programTitle << " directory." << endl;
			
	}
}
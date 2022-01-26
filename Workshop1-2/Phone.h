/*
Name : Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: January 25, 2021
*/
#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H

namespace sdds
{
	const int MAX_NAME_LEN = 50;
	struct Phonebook {
		char name[MAX_NAME_LEN];
		char area[4];
		char prefix[4];
		char number[5];
	};
	void phoneDir(const char* programTitle, const char* fileName);
}
#endif
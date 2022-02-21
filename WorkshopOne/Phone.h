#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H

namespace sdds
{
	const int MAX_NAME_LEN = 50;
	struct Phonebook {
		char name[MAX_NAME_LEN];
		int area;
		int prefix;
		int number;
	};
	void phoneDir(const char* programTitle, const char* fileName);
}
#endif
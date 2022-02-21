/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: January 27, 2021
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/

#ifndef SDDS_DNA_H
#define SDDS_DNA_H
namespace sdds
{
	
	struct fileDNA {
		char digit[7] = "";
		char strand[1001]="";
	};
	struct findDNA {
		int ids=0;
		char* matched_strands = nullptr;
	};
	bool beginSearch(const char* filename);
	bool read(const char* subDNA);
	void sort();
	void displayMatches();
	void deallocate();
	void endSearch();
	void record(const fileDNA& f);
}
#endif
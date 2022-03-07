/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 06, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Name.h"
#include <cstring>
namespace sdds {

	void sdds::Name::setEmpty()
	{
		if (m_fname != nullptr) delete[] m_fname;
		if (m_mname != nullptr) delete[] m_mname;
		if (m_lname != nullptr) delete[] m_lname;
		char* m_fname = nullptr;
		char* m_mname = nullptr;
		char* m_lname = nullptr;
	}

	bool sdds::Name::isvalid(const char* name)//needs to be worked on
	{
		bool result= true;
		if (name == nullptr || name == " " || name == "") result = false;
		return result;
	}

	void Name::set(const char* fname, const char* lname, const char* mname)
	{
		if (isvalid(fname)) {
			m_fname = new char[strlen(fname) + 1];
			strcpy(m_fname, fname);
		}
		if (isvalid(lname)) {
			m_lname = new char[strlen(lname) + 1];
			strcpy(m_lname, lname);
		}
		if (isvalid(mname)) {
			m_mname = new char[strlen(mname) + 1];
			strcpy(m_mname, mname);
		}
	}

	sdds::Name::Name(const char* fname, const char* lname, const char* mname)
	{
		setEmpty();
			set(fname, lname, mname);
		
	}
	Name::Name(const Name& N)
	{
		setEmpty();
		set(N.m_fname, N.m_lname, N.m_mname);
	}
	Name& Name::operator=(const Name& N)
	{
		setEmpty();
		if (this != &N) {
			set(N.m_fname, N.m_lname, N.m_mname);			
		}
		return *this;
	}
	Name::~Name()
	{
		delete[] m_fname;
		delete[] m_lname;
		delete[] m_mname;
	}
}
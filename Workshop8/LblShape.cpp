/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 24, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <string>
#include <cstring>
using namespace std;
namespace sdds{
char* sdds::LblShape::label() const
{
	return m_label;
}

sdds::LblShape::LblShape()
{
	if (m_label != nullptr) m_label = nullptr;
}

sdds::LblShape::LblShape(const char* label)
{
	if (label != nullptr) {
		this->m_label = new char[strlen(label) + 1];
		strcpy(this->m_label, label);
	}
}

sdds::LblShape::~LblShape()
{
	delete[] m_label;
}

void LblShape::getSpecs(std::istream& istr)
{
    /*string s;
    getline(istr, s, ',');
    int len = s.length();
    if (m_label != nullptr)
        delete[] m_label;
    m_label = new char[len + 1];
    strcpy(m_label, s.c_str());
    m_label[len] = '\0';*/
    //
    char s[1001];
    istr.get(s, 1000, ',');
    if (istr.peek() == ',')
        istr.ignore();
    if (m_label != nullptr)
        delete[] m_label;
    if (strlen(s) > 0) {
        this->m_label = new char[strlen(s) + 1];
        strcpy(this->m_label, s);
    }
    //
    ///*int len = 10;
    //char* str = new char[len];
    //if (m_label != nullptr)
    //    delete[] m_label; int i = 0;
    //    while (i >= 0) {
    //        istr.get(str, len, ',');
    //        istr.ignore();
    //        if (istr.fail()) {
    //            len += 100;
    //            delete[] str;
    //            str = new char[len];
    //            cout << "enter again" << endl;
    //            istr.ignore(1000,'\n');
    //            continue;
    //        }
    //        else {
    //            cout << "here";
    //            
    //            i = -1;
    //        }
    //}
    //    this->m_label = new char[strlen(str) + 1];
    //    strcpy(this->m_label, str);*/
}
}



#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <iostream>
#include <string>
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
    string s;
    getline(istr, s, ',');
    int len = s.length();
    if (m_label != nullptr)
        delete[] m_label;
    m_label = new char[len + 1];
    m_label[len] = '\0';
    strcpy(m_label, s.c_str());
    if (istr.peek() == ',')
        istr.ignore();
}
}



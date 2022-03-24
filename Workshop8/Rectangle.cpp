/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 24, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#include "Rectangle.h"
#include <iomanip>
#include <cstring>
using namespace std;
using namespace sdds;
	sdds::Rectangle::Rectangle()
	{
		m_width = 0;
		m_height = 0;
	}

	sdds::Rectangle::Rectangle(const char* label, int width, int height) :LblShape(label)
	{
		m_width = width;
		m_height = height;
		if (m_height < 3 || m_width < ((int)strlen(LblShape::label()) + 2)) {
			m_width = 0;
			m_height = 0;
		}
	}

	void sdds::Rectangle::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore();
		istr >> m_height;
		istr.ignore(1000, '\n');
	}

	void sdds::Rectangle::draw(std::ostream& ostr)const
	{
		if (m_width > 0 && m_height > 0) {
			ostr << "+";
			ostr.fill('-');
			ostr << setw(m_width - 2) << "-";
			ostr << "+" << endl;
			ostr << "|";
			ostr.fill(' ');
			ostr << left << setw(m_width - 2) << LblShape::label();
			ostr << "|" << endl;
			for (int i = 0; i < m_height - 3; i++) {
				ostr << "|";
				ostr << setw(m_width - 2) << " ";
				ostr << "|"<<endl;
			}
			ostr << "+";
			ostr.fill('-');
			ostr << setw(m_width - 2) << "-";
			ostr << "+";
		}
	}

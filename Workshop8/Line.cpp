/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 24, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#include "Line.h"
using namespace std;
using namespace sdds;
	sdds::Line::Line()
	{
		m_length = 0;
	}

	sdds::Line::Line(const char* label, int length) : LblShape(label)
	{
		m_length = length;
	}

	void sdds::Line::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(1000, '\n');
	}

	void sdds::Line::draw(std::ostream& ostr)const
	{
		if (LblShape::label() != nullptr && m_length > 0)
		{
			ostr << LblShape::label() << endl;
			for (int i = 0; i < m_length; i++)
				ostr << "=";
		}
	}

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

	void sdds::Line::draw(std::ostream& ostr)
	{
		if (LblShape::label() != nullptr && m_length > 0)
		{
			ostr << LblShape::label() << endl;
			for (int i = 0; i < m_length; i++)
				ostr << "=";
		}
	}

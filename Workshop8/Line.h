#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
#include <iostream>
namespace sdds {
	class Line : public LblShape {
	private:
		int m_length{};
	public:
		Line();
		Line(const char* label, int length);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr);
	};
}
#endif // !SDDS_LINE_H

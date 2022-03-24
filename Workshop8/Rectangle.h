#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
#include <iostream>
namespace sdds {
	class Rectangle : public LblShape {
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		~Rectangle() {};
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}
#endif // !SDDS_RECTANGLE_H


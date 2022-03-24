#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream& ostr=std::cout)const = 0;
		virtual void getSpecs(std::istream& istr=std::cin) = 0;
		virtual ~Shape() {};
	};
	std::ostream& operator<<(std::ostream& ostr, const Shape& S);
	std::istream& operator>>(std::istream& istr, Shape& S);
}

#endif // !SDDS_SHAPE_H

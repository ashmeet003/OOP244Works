#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
#include <iostream>
namespace sdds {
	class Line : public LblShape {
	private:
		int m_length{};
	protected:
		char* label();
	public:
		Line();
		Line(const char* label, int length);
		~Line() {};
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}
#endif // !SDDS_LINE_H

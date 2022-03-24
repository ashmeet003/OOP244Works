/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 24, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
#include <iostream>
namespace sdds {
	class LblShape : public Shape {
		char* m_label=nullptr;
	protected:
		char* label()const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		void getSpecs(std::istream& istr);
		virtual void draw(std::ostream& ostr) const = 0;

	};

}
#endif // !SDDS_LBLSHAPE_H
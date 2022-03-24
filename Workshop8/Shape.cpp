/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 24, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#include "Shape.h"
#include <cstring>
using namespace std;
using namespace sdds;
std::ostream& sdds::operator<<(std::ostream& ostr, const Shape& S)
{
    S.draw(ostr);
    return ostr;
}

std::istream& sdds::operator>>(std::istream& istr, Shape& S)
{
    S.getSpecs(istr);
    return istr;
}

sdds::Shape::~Shape()
{
}

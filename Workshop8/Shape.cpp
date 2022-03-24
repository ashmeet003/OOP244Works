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

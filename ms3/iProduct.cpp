/* Citation and Sources...
Final Project Milestone 3
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: April 3, 2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "iProduct.h"
using namespace std;
namespace sdds
{
    std::ostream &operator<<(std::ostream &ostr, const iProduct& I)
    {
        I.display(ostr);
        return ostr;
    }

    std::istream &operator>>(std::istream &istr, iProduct& I)
    {
        I.read(istr);
        return istr;
    }
}
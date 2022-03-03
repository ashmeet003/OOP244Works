/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 03, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/

#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H
#include <iostream>
using namespace std;
namespace sdds {
    class HealthCard {
        char* m_name{};
        long long m_number;
        char m_vCode[3];
        char m_sNumber[10];
        bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
        void setEmpty();
        void allocateAndCopy(const char* name);
        void extractChar(istream& istr, char ch) const;
        ostream& printIDInfo(ostream& ostr)const;
        void set(const char* name, long long number, const char vCode[], const char sNumber[]);
    public:
        //...
        HealthCard(const HealthCard& hc);
        HealthCard& operator=(const HealthCard& hc);
        ~HealthCard();
        operator bool() const;        
        ostream& print(ostream& ostr, bool toFile = true) const;
        istream& read(istream& istr);
        ostream& operator<<(ostream& ostr, const HealthCard& hc);
        istream& operator>>(istream& istr, HealthCard& hc);
    };
}
#endif // !SDDS_HEALTHCARD_H

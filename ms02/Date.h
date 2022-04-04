/* Citation and Sources...
Final Project Milestone 2
Filename: Date.h
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 24, 2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include <iomanip>
#include "Status.h"
namespace sdds
{
    const int MAX_YEAR = 2030;
    class Date
    {
        int m_year;
        int m_month;
        int m_day;
        Status m_state;
        bool m_formatted = true;
        bool validate();
        int value() const;
    public:
        Date();
        Date(int year, int month, int day);
        bool operator==(const Date& D) const;
        bool operator!=(const Date& D) const;
        bool operator<(const Date& D) const;
        bool operator>(const Date& D) const;
        bool operator<=(const Date& D) const;
        bool operator>=(const Date& D) const;
        const Status& state() const;
        void formatted(bool value);
        operator bool() const;
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const Date& D);
    std::istream& operator>>(std::istream& istr, Date& D);
}

#endif //!SDDS_DATE_H
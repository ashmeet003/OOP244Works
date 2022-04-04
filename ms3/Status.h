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
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
#include <iomanip>
namespace sdds
{
    class Status
    {
        char* m_statusDesc;
        int m_statusCode;
    public:
        Status(char* statusDesc = nullptr);
        Status(const Status& S);
        Status& operator=(const Status& S);
        ~Status();
        Status& operator=(const char* statusDesc);
        Status& operator=(int code);
        operator int() const;
        operator char* () const;
        operator bool() const;
        Status& clear();
        const char* getDesc() const;
        int getCode() const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Status& S);
}

#endif // !SDDS_STATUS_H
/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 03, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "HealthCard.h"
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {
    const int MaxNameLength = 55;

    bool sdds::HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
    {
        bool result = true;
        if (name == nullptr || name[0] == '\0')
            result = false;
        else if (number >= 9999999999 || number <= 999999999)
            result = false;
        else if (vCode == nullptr || strlen(vCode) != 2)
            result = false;
        else if (sNumber == nullptr || strlen(sNumber) != 9)
            result = false;
        return result;
    }

    void sdds::HealthCard::setEmpty()
    {
        if (m_name != nullptr)
        {
            delete[] m_name;
            m_name = nullptr;
        }
        m_name = nullptr;
        m_number = 0;
        m_vCode[0] = '\0';
        m_sNumber[0] = '\0';
    }

    void sdds::HealthCard::allocateAndCopy(const char* name)
    {
        if (m_name != nullptr)
            delete[] m_name;
        m_name = new char[MaxNameLength];//changed
        strcpy(m_name, name);
    }

    void sdds::HealthCard::extractChar(istream& istr, char ch) const
    {
        char t_var = istr.peek();
        if (t_var == ch)
            istr.ignore();
        else {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }

    ostream& sdds::HealthCard::printIDInfo(ostream& ostr) const {
        ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
        return ostr;
    }

    void sdds::HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
    {
        if (validID(name, number, vCode, sNumber)) {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
        else
            setEmpty();
    }

    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
    {
        setEmpty();
        if (validID(name, number, vCode, sNumber)) {
            set(name, number, vCode, sNumber);
        }
    }
    HealthCard::HealthCard(const HealthCard& hc) {
        setEmpty();
        if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        }
    }
    HealthCard& HealthCard::operator=(const HealthCard& hc) {
        setEmpty();
        if (this != &hc) {
            if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
                set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
            }
            /*else {
                delete[] m_name;//..
                m_name = nullptr;//..
            }*/
        }
        return *this;
    }
    HealthCard::~HealthCard() {
        setEmpty();
    }
    HealthCard::operator bool() const {
        return m_name != nullptr;
    }
    ostream& HealthCard::print(ostream& ostr, bool toFile) const {
        if (toFile)
        {
            if (validID(m_name, m_number, m_vCode, m_sNumber)) {
                ostr << m_name << ",";
                printIDInfo(ostr);
                ostr << '\n';
            }
        }
        else {
            if (validID(m_name, m_number, m_vCode, m_sNumber))
            {
                ostr << left << setw(50) << setfill('.') << m_name;
                printIDInfo(ostr);
            }
            else
            {
                ostr << "Invalid Health Card Record";
            }
        }
        return ostr;

    }
    istream& HealthCard::read(istream& istr) {
        char l_name[MaxNameLength + 1];//l_name=local_name
        long long l_number;
        char l_vCode[4];
        char l_sNumber[11];
        istr.get(l_name, MaxNameLength, ',');
        extractChar(istr, ',');
        istr >> l_number;
        extractChar(istr, '-');
        istr.get(l_vCode, 4, ',');
        extractChar(istr, ',');
        istr.get(l_sNumber, 11, '\n');
        extractChar(istr, '\n');
        if (!istr.fail()) {
            set(l_name, l_number, l_vCode, l_sNumber);
        }
        else {
            setEmpty();
            istr.clear();
            istr.ignore(1000, '\n');
        }
        //delete[] l_name;
        return istr;
    }
    ostream& operator<<(ostream& ostr, const HealthCard& hc)
    {
        // hc.print(ostr, false);
        return hc.print(ostr, false);
    }

    istream& operator>>(istream& istr, HealthCard& hc)
    {
        // hc.read(istr);
        return  hc.read(istr);
    }
}
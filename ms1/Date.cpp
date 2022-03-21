#include "Date.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
    bool Date::validate()
    {
        bool result = true;
        int currentYear;
        ut.getSystemDate(&currentYear, nullptr, nullptr);
        if (m_year < currentYear || m_year > MAX_YEAR){
            m_state = 1;
            m_state = "Invalid year in date";
            result = false;
        }
        else if (m_month < 1 || m_month > 12){
            m_state = 2;
            m_state = "Invalid month in date";
            result = false;
        }
        else if (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year)) {
            m_state = 3;
            m_state = "Invalid day in date";
            result = false;
        }
        else
            m_state.clear();
        return result;
    }

    int Date::value() const
    {
        return m_year * 372 + m_month * 31 + m_day;
    }

    Date::Date()
    {
        ut.getSystemDate(&m_year, &m_month, &m_day);
        validate();
    }

    Date::Date(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
        validate();
    }

    bool Date::operator==(const Date& D) const
    {
        return value() == D.value();
    }

    bool Date::operator!=(const Date& D) const
    {
        return value() != D.value();
    }

    bool Date::operator<(const Date& D) const
    {
        return value() < D.value();
    }

    bool Date::operator>(const Date& D) const
    {
        return value() > D.value();
    }

    bool Date::operator<=(const Date& D) const
    {
        return value() <= D.value();
    }

    bool Date::operator>=(const Date& D) const
    {
        return value() >= D.value();
    }
    const Status& Date::state() const
    {
        return m_state;
    }

    void Date::formatted(bool value)
    {
        m_formatted = value;
    }

    Date::operator bool() const
    {
        return m_state;
    }

    ostream& Date::write(ostream& ostr) const
    {
        if (m_formatted)
            ostr << setw(4) << setfill('0') << m_year << "/" << setw(2) << setfill('0') << m_month << "/" << setw(2) << setfill('0') << m_day;
        else
            ostr << setw(2) << setfill('0') << m_year % 100 << setw(2) << setfill('0') << m_month << setw(2) << setfill('0') << m_day;
        return ostr;
    }

    istream& Date::read(istream& istr)
    {
        int value;
        istr >> value;
        if (istr.fail()){
            m_state = "Invalid date value";
            istr.setstate(ios::failbit);
        }
        else{
            if (value < 0){
                m_state = "Invalid date value";
                istr.setstate(ios::failbit);
            }
            if (value >= 10 && value <= 999){
                m_state = "Invalid month in date";
                m_state = 2;
                istr.setstate(ios::failbit);
            }
            else if (value >= 1000 && value <= 9999){
                ut.getSystemDate(&m_year, nullptr, nullptr);
                m_month = value / 100;
                m_day = value % 100;
                if (!validate()){
                    istr.setstate(ios::failbit);
                }
            }
            else if (value >= 10000 && value <= 99999){
                m_state = "Invalid year in date";
                m_state = 1;
                istr.setstate(ios::failbit);
            }
            else if (value >= 100000 && value <= 999999){
                m_year = value / 10000;
                m_year += 2000;
                m_month = (value / 100) % 100;
                m_day = value % 100;
                if (!validate()){
                    istr.setstate(ios::failbit);
                }
            }
            else{
                m_state = "Invalid date value";
                istr.setstate(ios::failbit);
            }
        }
        return istr;
    }

    ostream& operator<<(ostream& ostr, const Date& D)
    {
        return D.write(ostr);
    }

    istream& operator>>(istream& istr, Date& D)
    {      
        return D.read(istr);;
    }

}
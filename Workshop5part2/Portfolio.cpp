
#define _CRT_SECURE_NO_WARNINGS
#include "Portfolio.h"
#include <string.h>
using namespace std;
namespace sdds {
    Portfolio::Portfolio() {
        setPortfolio();
    }

    void Portfolio::setPortfolio(){
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        setPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::viewDetails() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }

    std::ostream& Portfolio::display() const {
        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            viewDetails();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            viewDetails();
        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            viewDetails();
        }
        return cout;
    }

    Portfolio::operator double() const
    {
        return m_value;
    }

    Portfolio::operator const char* () const
    {
        return m_stock;
    }
    Portfolio::operator char() const
    {
        return m_type;
    }

    Portfolio::operator bool() const
    {
        bool result = false;
        if (m_type == 'G' || m_type == 'V' || m_type == 'I'){
            result = true;
        }
        return result;
    }

    Portfolio& Portfolio::operator +=(double value){
        if ((value > 0) && (m_type == 'G' || m_type == 'V' || m_type == 'I')){
            m_value += value;
        }
        return *this;
    }

    Portfolio& Portfolio::operator -=(double value){
        if ((value >= 0) && (m_type == 'G' || m_type == 'V' || m_type == 'I')){
            m_value -= value;
        }
        return *this;
    }

    double Portfolio::getValue() const
    {
        return m_value;
    }

    bool operator ~(const Portfolio& value)
    {
        bool result = false;
        if (value.getValue() < 0){
            result = true;
        }
        return result;
    }

    bool Portfolio::istrue() const
    {
        bool result = false;
        if ((m_value >= 0) && (m_type == 'G' || m_type == 'V' || m_type == 'I'))
        {
            result = true;
        }
        return result;
    }

    Portfolio& Portfolio::operator <<(Portfolio& value){
        m_value += value.m_value;
        value.m_value = 0;
        value.m_stock[0] = 0;
        value.m_type = 'E';
        return *this;
    }

    Portfolio& Portfolio::operator >>(Portfolio& value){
        value.m_value += m_value;
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
        return *this;
    }

    double operator +(const Portfolio& rO, Portfolio& lO){
        double value = 0;
        if (rO.istrue() && lO.istrue()){
            value = rO.getValue() + lO.getValue();
        }
        return value;
    }

    double operator +=(double& rO, const Portfolio& lO){
        rO += lO.getValue();
        return rO;
    }
}
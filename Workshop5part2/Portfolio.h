
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>
namespace sdds {
    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;
    public:
        Portfolio();
        Portfolio(double value, const char* stock, char type);
        std::ostream& display() const;
        operator double() const;
        operator const char* () const;
        operator char() const;
        operator bool() const;
        Portfolio& operator +=(double value);
        Portfolio& operator -=(double value);
        double getValue() const;
        Portfolio& operator <<(Portfolio& value);
        Portfolio& operator >>(Portfolio& value);
        bool istrue() const;
        void  setPortfolio();
        void viewDetails() const;      
    };
    bool operator ~(const Portfolio& value);
    double operator +(const Portfolio& rO, Portfolio& lO);
    double operator +=(double& rO, const Portfolio& lO);
}
#endif // !SDDS_Portfolio_H_
/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: February 17, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
 As for the last two functions(deemed as friend): I was not sure weather we are allowed to use friend function, so had to discuss it with friends and thus decided to use friend()
*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>
namespace sdds
{
    const int MaxPassengerCap = 388;
    const int MaxFuelCap = 238840;
    class Flight
    {
    private:
        int m_passenger = 0;
        double m_fuel = 0;
        char m_title[16];
        void emptyPlane();
    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double()const;
        operator const char* ()const;
        bool operator~() const;
        Flight& operator=(Flight& F);
        Flight& operator=(const int passengers);
        Flight& operator=(const double fuel);
        Flight& operator+=(const double fuel);
        Flight& operator+=(const int passengers);
        Flight& operator-=(const double fuel);
        Flight& operator-=(const int passengers);
        Flight& operator<<(Flight& F);
        Flight& operator>>(Flight& F);
        friend int operator+(const Flight& lO, const Flight& rO);
        friend int operator+=(int& lO, const Flight& rO);
    };
}
#endif //!SDDS_FLIGHT_H
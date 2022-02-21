/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: February 17, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"
using namespace std;
namespace sdds
{
    void Flight::emptyPlane()
    {
        m_passenger = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    Flight::Flight()//default
    {
        emptyPlane();
    }

    Flight::Flight(int passengers, double fuel, const char* title){
        emptyPlane();
        if (passengers > 0 && passengers <= MaxPassengerCap && fuel >= 0 && fuel <= MaxFuelCap){
            m_passenger = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }

    std::ostream& Flight::display() const{
        if (*this){
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this){
            cout << " Flight  |  Empty Plane    ";
        }
        else{
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool()const{
        bool result = false;
        if (m_passenger > 0 && m_fuel >= (600 * m_passenger)){
            result = true;
        }
        return result;
    }

    Flight::operator double() const
    {
        return m_fuel;
    }

    Flight::operator int() const
    {
        return m_passenger;
    }

    Flight::operator const char*() const
    {
        return m_title;
    }

    bool Flight::operator~()const
    {
        return m_passenger == 0;
    }

    Flight& Flight::operator=(Flight& F){
        if (!~F){
            this->m_passenger = F.m_passenger;
            this->m_fuel = F.m_fuel;
            strcpy(this->m_title, F.m_title);
            F.m_passenger = 0;
            F.m_fuel = 0.0;
            F.m_title[0] = '\0';
        }
        return *this;
    }

    Flight& Flight::operator=(const int passengers){
        if (passengers > 0 && passengers <= MaxPassengerCap){
            this->m_passenger = passengers;
        }
        return *this;
    }

    Flight& Flight::operator=(const double fuel){
        if (fuel <= MaxFuelCap) {
            this->m_fuel = fuel;
        }
        return *this;
    }

    Flight& Flight::operator+=(const double fuel){
        if (fuel > 0 && (this->m_fuel + fuel) <= MaxFuelCap){
            this->m_fuel += fuel;
        }
        else if (this->m_fuel < MaxFuelCap){
            double temp = MaxFuelCap - this->m_fuel;
            if (temp <= fuel){
                this->m_fuel += temp;
            }
        }
        return *this;
    }

    Flight& Flight::operator+=(const int passengers){
        if (passengers > 0 && this->m_passenger < MaxPassengerCap){
            this->m_passenger += passengers;
        }
        else if (this->m_passenger < MaxPassengerCap){
            int t = MaxPassengerCap - this->m_passenger;
            if (t <= passengers){
                this->m_passenger += t;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(const double fuel){
        if (fuel > 0){
            if ((this->m_fuel - fuel) >= 0){
                this->m_fuel -= fuel;
            }
            else{
                int i = 0;
                while (this->m_fuel >= 0 && i <= fuel){
                    this->m_fuel--;
                    i++;
                }
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(const int passengers){
        if (passengers > 0){
            if ((this->m_passenger - passengers) >= 0){
                this->m_passenger -= passengers;
            }
            else{
                int i = 0;
                while (this->m_passenger >= 0 && i <= passengers){
                    this->m_passenger--;
                    i--;
                }
            }
        }
        return *this;
    }

    Flight& Flight::operator<<(Flight& F){
        if (this != &F){
            if ((this->m_passenger + F.m_passenger) <= MaxPassengerCap){
                this->m_passenger += F.m_passenger;
                F.m_passenger = 0;
            }
            else{
                int t = MaxPassengerCap - this->m_passenger;
                this->m_passenger += t;
                F.m_passenger -= t;
            }
        }
        return *this;
    }
    Flight& Flight::operator>>(Flight& F){
        if (this != &F){
            if ((this->m_passenger + F.m_passenger) <= MaxPassengerCap){
                F.m_passenger += this->m_passenger;
                this->m_passenger = 0;
            }
            else{
                int t = MaxPassengerCap - F.m_passenger;//t is a temporary variable to store value of passangers on a flight
                F.m_passenger += t;
                this->m_passenger -= t;
            }
        }
        return *this;
    }

    int operator+(const Flight& lO, const Flight& rO){//lO=left operator and rO=right operator
        int total = 0;
        if (lO && rO){
            total = lO.m_passenger + rO.m_passenger;
        }
        return total;
    }

    int operator+=(int& lO, const Flight& rO){
        lO += rO.m_passenger;
        return lO;
    }
}
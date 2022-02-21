/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: February 10, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;
namespace sdds
{
    CarInventory::CarInventory()
    {
        resetInfo();
    }
    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
    {
        resetInfo();
        setInfo(type, brand, model, year, code, price);
        if (!isValid()) 
            resetInfo();

    }
    CarInventory::~CarInventory()
    {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
    }
    void CarInventory::resetInfo()
    {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0;
    }
    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
    {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
        m_type = new char[strlen(type) + 1];
        strcpy(m_type, type);

        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand, brand);

        m_model = new char[strlen(model) + 1];
         strcpy(m_model, model);

        m_year = year;
        m_code = code;
        m_price = price;

        return *this;
    }
    void CarInventory::printInfo() const {
        cout.setf(ios::left);
        cout << "| " << setw(10) << m_type << " | " << setw(16) << m_brand << " | " << setw(16) << m_model << " | " << m_year << " |  " << m_code << " |";
        cout.unsetf(ios::left);
       cout <<setw(7)<< m_price << ".00 |" << endl;;
       
    }
    bool CarInventory::isValid() const {
        return m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code >= 100 && m_code <=999 && m_price > 0;
    }
    bool CarInventory::isSimilarTo(const CarInventory& car) const {
        return(strcmp(m_type, car.m_type) == 0 && strcmp(m_model, car.m_model) == 0 && strcmp(m_brand, car.m_brand) == 0 && m_year == car.m_year);
    }
    bool find_similar(CarInventory car[], const int num_cars)
    {
        bool result = false;
        for (int i = 0; (i < num_cars) && !result; i++) {

            for (int j = i + 1; (j < num_cars) && !result; j++)
            {
                if ((car[i].isValid() && car[j].isValid()) && car[i].isSimilarTo(car[j]))
                {
                    result = true;
                }
            }
        }

        return result;
    }
}
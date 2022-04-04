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
#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include <iomanip>
using namespace std;
namespace sdds
{
    Utils ut;
    void Utils::testMode(bool testmode)
    {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day)
    {
        if (m_testMode)
        {
            if (day)
                *day = sdds_testDay;
            if (mon)
                *mon = sdds_testMon;
            if (year)
                *year = sdds_testYear;
        }
        else
        {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day)
                *day = lt.tm_mday;
            if (mon)
                *mon = lt.tm_mon + 1;
            if (year)
                *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year) const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    void Utils::alocpy(char*& destination, const char* source)
    {
        // Safely allocates memory in destination and copies the source into it.

        // deletes the destination dynamic array and sets it to null
        // if the source is not null
        // Allocates memory in the destination to the size of the source and copies the source into it.
        if (destination)
            delete[] destination;

        if (source != nullptr)
        {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
        else
            destination = nullptr;
    }

    int Utils::getint(const char* prompt)
    { // If the prompt is not null, it will display it.
       // Then it performs a foolproof entry of an integer.
       // If the user enters an invalid integer it will display
       // "Invalid Integer, retry: "
       // and will not let the user leave the
       // function until a valid integer is entered.

        int num = -1;
        bool result = false;
        while (!result)
        {
            if (prompt)
                cout << prompt;
            cin >> num;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Integer, retry: ";
            }
            else
                result = true;
        }
        return num;
    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes)
    {
        int num;
        bool result = false;
        while (!result)
        {
            num = getint(prompt);
            if (num < min || num > max)
            {
                if (errMes)
                    cout << errMes << "retry: ";
                else
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
            }
            else
                result = true;
        }
        return num;
    }

    double Utils::getdouble(double min, double max, const char* prompt, const char* errMes)
    {
        double num;
        bool result = false;
        while (!result){
            num = getdouble(prompt);
            if (num < min || num > max){
                if (errMes) cout << errMes << "retry: ";
                else cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
            }
            else result = true;
        }
        return num;
    }

    double Utils::getdouble(const char* prompt)
    {
        double num = -1;
        bool result = false;
        while (!result){
            if (prompt) cout << prompt;
            cin >> num;
            if (cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid double, retry: ";
            }
            else result = true;
        }
        return num;
    }

    int Utils::getIntStream(istream& istr, const char* prompt)
    {
        int num;
        bool result = false;
        while (!result){
            if (prompt)
                cout << prompt;
            istr >> num;
            if (istr.fail()){
                istr.clear();
                istr.ignore(1000, '\n');
                cout << "Invalid Integer, retry: ";
            }
            else result = true;
        }
        return num;
    }

    int Utils::getIntStream(istream& istr, int min, int max, const char* prompt, const char* errMes)
    {
        int num;
        bool result = false;
        while (!result){
            num = getIntStream(istr, prompt);
            if (num < min || num > max){
                if (errMes) cout << errMes << "retry: ";
                else cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
            }
            else result = true;
        }
        return num;
    }

    double Utils::getDoubleStream(istream& istr, double min, double max, const char* prompt, const char* errMes)
    {
        double num;
        bool result = false;
        while (!result)
        {
            num = getDoubleStream(istr, prompt);
            if (num < min || num > max){
                if (errMes) cout << errMes << "retry: ";
                else cout << "Value out of range [" << std::fixed << std::setprecision(2) << min << "<=val<=" << std::fixed << std::setprecision(2) << max << "]: ";
            }
            else result = true;
        }
        return num;
    }

    double Utils::getDoubleStream(istream& istr, const char* prompt)
    {
        double num;
        bool result = false;
        while (!result){
            if (prompt)
                cout << prompt;
            istr >> num;
            if (istr.fail()){
                istr.clear();
                istr.ignore(1000, '\n');
                cout << "Invalid number, retry: ";
            }
            else result = true;
        }
        return num;
    }

}
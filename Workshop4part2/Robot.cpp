/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: February 14, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Robot.h"
using namespace std;
namespace sdds
{
    Robot::Robot()
    {
        m_name = nullptr;
        m_location = nullptr;
        m_weight = -1;//assigning impossible value
        m_width = -1;
        m_height = -1;
        m_speed = -1;
        m_deployed = false;
    }
    Robot::Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed)
    {
        set(name, location, weight, width, height, speed, deployed);
    }
    Robot::~Robot()
    {
        delete[] m_name;
        delete[] m_location;
    }
    Robot& Robot::set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed)
    {
        delete[] m_name;
        delete[] m_location;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        m_location = new char[strlen(location) + 1];
        strcpy(m_location, location);
        m_weight = weight;
        m_width = width;
        m_height = height;
        m_speed = speed;
        m_deployed = deployed;
        return *this;
    }
    void Robot::setLocation(const char* location)
    {
        delete[] m_location;
        m_location = new char[strlen(location) + 1];
        strcpy(m_location, location);
    }

    void Robot::setDeployed(bool deployed)
    {
        m_deployed = deployed;
    }
    const char* Robot::getName() const
    {
        return m_name;
    }
    const char* Robot::getLocation() const
    {
        return m_location;
    }
    bool Robot::isDeployed() const
    {
        return m_deployed;
    }
    bool Robot::isValid() const
    {
        return (m_name != nullptr && m_location != nullptr && m_weight > 0 && m_height > 0 && m_width > 0 && m_speed > 0);
    }
    double Robot::getSpeed() const
    {
        return m_speed;
    }
    void Robot::display() const
    {
        cout << "| ";
        cout.width(10);
        cout.setf(ios::left);
        cout << m_name << " | ";
        cout.width(15);
        cout << m_location << " | ";
        cout.unsetf(ios::left);
        cout.width(6);
        cout.setf(ios::right);
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << m_weight << " | ";
        cout.width(6);
        cout.setf(ios::right);
        cout << m_width << " | ";
        cout.width(6);
        cout.setf(ios::right);
        cout << m_height << " | ";
        cout.width(6);
        cout.setf(ios::right);
        cout << m_speed << " | ";
        cout.unsetf(ios::right);
        cout.width(8);
        cout.setf(ios::left);
        isDeployed() ? cout << "YES" : cout << "NO";
        cout.unsetf(ios::left);
        cout << " |" << endl;    }
    int conrtolRooomReport(const Robot robot[], int num_robots)
    {
        int result = -1;
        cout << setw(55) << "------ Robot Control Room -----" << endl;
        cout << setw(59) << "---------------------------------------" << endl;
        cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
        cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
        int i;  int keep = 0; int speedIndex = 0;

        for (i = 0; i < num_robots; i++) {
            if (robot[i].isValid()) {
                robot[i].display();
                if (robot[i].isDeployed()) keep++;
                for (int j = 0; j < num_robots; j++) {
                    if (robot[j].getSpeed() > robot[i].getSpeed())
                        speedIndex = j;
                }
            }
            else {
                result = i;
                keep++;
                break;
            }
        }
        if (result == -1) {
            cout << "|=============================================================================|" << endl;
            cout << "| SUMMARY:" << setw(69) << "|" << endl;
            cout << "| " << keep << "  robots are deployed." << setw(54) << "|" << endl;
            cout << "| The fastest robot is:" << setw(56) << "|" << endl;
            cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
            cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
            robot[speedIndex].display();
            cout << "|=============================================================================|" << endl;
        }
        return result;
    }
}

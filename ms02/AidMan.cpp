/* Citation and Sources...
Final Project Milestone 2
Filename: AidMan.cpp
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 24, 2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "AidMan.h"
#include <iomanip>
#include <cstring>
using namespace std;
namespace sdds
{
    unsigned int AidMan::menu()
    {
        cout << "Aid Management System Version 0.1" << endl;
        cout << "Date: " << Date() << endl;
        cout << "Data file: ";
        if (m_fileName == nullptr)
            cout << "No file" << endl;
        else
            cout << m_fileName << endl;
        cout << "---------------------------------" << endl;
        unsigned int selection = 0;
        selection = m_mainMenu.run();
        return selection;
    }

    AidMan::AidMan()
    {
        m_fileName = nullptr;
        m_mainMenu.setContent("1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n");
        m_mainMenu.setSelection(7);
    }

    AidMan::AidMan(const AidMan& A)
    {
        m_fileName = nullptr;
    }

    AidMan& AidMan::operator=(const AidMan& A)
    {
        return *this;
    }

    AidMan::~AidMan()
    {
        delete[] m_fileName;
    }

    void AidMan::run()
    {
        int flag = -1;
        while (flag != 0){
            flag = menu();
            switch (flag){
            case 1:
                cout << "\n****List Items****" << endl << endl;
                break;
            case 2:
                cout << "\n****Add Item****" << endl << endl;
                break;
            case 3:
                cout << "\n****Remove Item****" << endl << endl;
                break;
            case 4:
                cout << "\n****Update Quantity****" << endl << endl;
                break;
            case 5:
                cout << "\n****Sort****" << endl << endl;
                break;
            case 6:
                cout << "\n****Ship Items****" << endl << endl;
                break;
            case 7:
                cout << "\n****New/Open Aid Database****" << endl << endl;
                break;
            case 0:
                cout << "Exiting Program!" << endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
            }
        }
    }
}

/* Citation and Sources...
Final Project Milestone 2
Filename: AidMan.h
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 24, 2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include <iostream>
#include "Utils.h"
#include "Menu.h"
#include "Date.h"
namespace sdds
{
    class AidMan
    {
        char* m_fileName;
        Menu m_mainMenu;
        unsigned int menu();
    public:
        AidMan();
        AidMan(const AidMan& A);
        AidMan& operator=(const AidMan& A);
        ~AidMan();
        void run();
    };
}

#endif //!SDDS_AIDMAN_H
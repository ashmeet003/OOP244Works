/* Citation and Sources...
Final Project Milestone 2
Filename: Menu.cpp
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 24, 2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>
#include "Utils.h"
#include "Menu.h"
using namespace std;
namespace sdds
{
    Menu::Menu(const char* content, unsigned int numOfOptions)
    {
        if (content == nullptr || numOfOptions > MAX_OPTIONS || numOfOptions <= 0) {
            this->m_content = nullptr;
            this->m_numOfOptions = 0;
        }
        else {
            ut.alocpy(this->m_content, content);
            this->m_numOfOptions = numOfOptions;
        }
    }

    Menu::Menu(const Menu& M)
    {
        m_content = nullptr;
        m_numOfOptions = 0;
    }

    Menu& Menu::operator=(const Menu& M)
    {
        this->m_content = nullptr;
        this->m_numOfOptions = 0;
        return *this;
    }

    Menu::~Menu()
    {
        delete[] m_content;
    }

    unsigned int Menu::run()
    {
        int selectOption = 0;
        cout << m_content;
        cout << "0- Exit" << endl;
        cout << "> ";
        selectOption = ut.getint(0, m_numOfOptions);
        return selectOption;
    }
    void Menu::setContent(const char* content)
    {
        ut.alocpy(this->m_content, content);
    }
    void Menu::setSelection(unsigned int numOfOptions)
    {
        this->m_numOfOptions = numOfOptions;
    }
}

/* Citation and Sources...
Final Project Milestone 2
Filename: Menu.h
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 24, 2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds
{
    const int MAX_OPTIONS = 15;
    class Menu {
        char* m_content;
        unsigned int m_numOfOptions;
    public:
        Menu(const char* content = nullptr, unsigned int numOfOptions = 0);
        Menu(const Menu& M);
        Menu& operator=(const Menu& M);
        ~Menu();
        unsigned int run();
        void setContent(const char* content);
        void setSelection(unsigned int numOfOptions);
    };
}

#endif //!SDDS_MENU_H
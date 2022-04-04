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
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "iProduct.h"
#include "Utils.h"
#include "Status.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
namespace sdds
{
    class Item : public iProduct
    {
        double m_price{};
        int m_qty{};
        int m_qtyNeeded{};
        char* m_desc{};
        bool m_linear{};

    protected:
        Status m_status;
        int m_sku;
        bool linear() const;

    public:
        Item();
        Item(const Item &item);
        Item &operator=(const Item &item);
        ~Item();
        int qtyNeeded() const;
        int qty() const;
        operator double() const;
        operator bool() const;
        int operator-=(int qty);
        int operator+=(int qty);
        void linear(bool isLinear);
        void clear();
        bool operator==(int sku) const;
        bool operator==(const char *description) const;
        std::ofstream &save(std::ofstream &ofstr) const;
        std::ifstream &load(std::ifstream &ifstr);
        std::ostream &display(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
        int readSku(std::istream &istr);
    };
}

#endif //!SDDS_ITEM_H
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
#include "Item.h"
using namespace std;
namespace sdds
{
    bool Item::linear() const
    {
        return m_linear;
    }

    Item::Item()
    {
        m_sku = 0;
        m_price = 0;
        m_qty = 0;
        m_qtyNeeded = 0;
        m_desc = nullptr;
        m_linear = false;
        m_status = Status();
    }

    Item::Item(const Item &I)
    {
        m_sku = I.m_sku;
        m_price = I.m_price;
        m_qty = I.m_qty;
        m_qtyNeeded = I.m_qtyNeeded;
        ut.alocpy(m_desc, I.m_desc);
        m_linear = I.m_linear;
        m_status = I.m_status;
    }

    Item &Item::operator=(const Item &I)
    {
        if (this != &I)
        {
            m_sku = I.m_sku;
            m_price = I.m_price;
            m_qty = I.m_qty;
            m_qtyNeeded = I.m_qtyNeeded;
            ut.alocpy(m_desc, I.m_desc);
            m_linear = I.m_linear;
            m_status = I.m_status;
        }
        return *this;
    }

    Item::~Item()
    {
        delete[] m_desc;
    }

    int Item::qtyNeeded() const
    {
        return m_qtyNeeded;
    }

    int Item::qty() const
    {
        return m_qty;
    }

    Item::operator double() const
    {
        return m_price;
    }

    Item::operator bool() const
    {
        return m_status;
    }

    int Item::operator-=(int qty)
    {
        if (qty > 0) m_qty -= qty;
        return m_qty;
    }

    int Item::operator+=(int qty)
    {
        if (qty > 0) m_qty += qty;
        return m_qty;
    }

    void Item::linear(bool isLinear)
    {
        m_linear = isLinear;
    }

    void Item::clear()
    {
        m_status.clear();
    }

    bool Item::operator==(int sku) const
    {
        return (m_sku == sku);
    }

    bool Item::operator==(const char *description) const
    {
        bool result = false;
        if (description == nullptr || m_desc == nullptr) result= false;
        else {
            if (strstr(m_desc, description) != nullptr) 
                result = true;
        }
        return result;
    }

    ofstream &Item::save(ofstream &ostr) const
    {
        if (m_status.operator bool())
        {
            ostr << m_sku << "\t" << m_desc << "\t" << m_qty << "\t" << m_qtyNeeded << "\t" << std::fixed << std::setprecision(2) << m_price;
        }
        return ostr;
    }
   
    ifstream &Item::load(ifstream &ifstr)
    {
        if (ifstr.is_open())
        {
            if (m_desc != nullptr) delete[] m_desc;
            m_desc = new char[100000];
            ifstr >> m_sku;
            if (ifstr.peek() == '\t') ifstr.get();
            ifstr.getline(m_desc, 100000, '\t');
            if (ifstr.peek() == '\t') ifstr.get();
            ifstr >> m_qty >> m_qtyNeeded >> m_price;
            ifstr.get();
            if (ifstr.fail()){
                m_status = "Input file stream read failed!";
                m_status = 1;
            }
        }
        return ifstr;
    }

    ostream &Item::display(ostream &ostr) const
    {
        if (m_status.operator bool()){
            if (m_linear){
                char* temp_desc{};
                ut.alocpy(temp_desc, m_desc);
                if (strlen(m_desc) > 35)
                {
                    temp_desc[35] = '\0';
                }
                ostr << setw(6) << left << m_sku << "| " << setw(35) << left << temp_desc << " | " << setw(4) << right << m_qty << " | " << setw(4) << m_qtyNeeded << " | " << setw(7) << std::fixed << std::setprecision(2) << m_price << " |";
                delete[] temp_desc;
            }
            else{
                ostr << "AMA Item:\n" << m_sku << ": " << m_desc << endl;
                ostr << "Quantity Needed: " << m_qtyNeeded << endl;
                ostr << "Quantity Available: " << m_qty << endl;
                ostr << "Unit Price: $" << std::fixed << std::setprecision(2) << m_price << endl;
                ostr << "Needed Purchase Fund: $" << std::fixed << std::setprecision(2) << (m_qtyNeeded * m_price) - (m_qty * m_price) << endl;
            }
        }
        else ostr << m_status;
        return ostr;
    }

    int Item::readSku(istream &istr)
    {
        cout << "SKU: ";
        m_sku = ut.getint(40000, 99999);
        return m_sku;
    }

    istream &Item::read(istream &istr)
    {
        if (m_desc != nullptr) delete[] m_desc;
        m_status.clear();
        cout << "AMA Item:" << endl;
        cout << "SKU: " << m_sku << endl;
        cout << "Description: ";
        if (istr.peek() == '\n') istr.get();
        m_desc = new char[10000];
        istr.getline(m_desc, 10000, '\n');
        cout << "Quantity Needed: ";
        m_qtyNeeded = ut.getIntStream(istr, 1, 9999);
        cout << "Quantity On Hand: ";
        m_qty = ut.getIntStream(istr, 0, m_qtyNeeded);
        cout << "Unit Price: $";
        m_price = ut.getDoubleStream(istr, 0.0, 9999.0);
        if (istr.fail()){
            m_status = "Console entry failed!";
            m_status = 1;
        }
        return istr;
    }
}
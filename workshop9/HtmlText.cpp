/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: April 3 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HtmlText.h"
using namespace std;
namespace sdds {
    ostream& HtmlText::write(ostream& ostr) const {
        ostr << "<html><head><title>";

        if (m_title == nullptr) ostr << "No Title";
        else ostr << m_title;
        ostr << "</title></head>\n<body>\n";
        if (m_title != nullptr)
            ostr << "<h1>" << m_title << "</h1>\n";
        unsigned int index = 0;
        bool result = false;
        if (Text::content() != nullptr) {
            while (index != strlen(Text::content())) {
                char ch = Text::operator[](index);
                if (ch == ' ') {
                    if (result == true) ostr << "&nbsp;";
                    else ostr << ch;
                    result = true;
                }
                else if (ch == '<') {
                    ostr << "&lt;";
                    result = false;
                }
                else if (ch == '>') {
                    ostr << "&gt;";
                    result = false;
                }
                else if (ch == '\n') {
                    ostr << "<br />\n";
                    result = false;
                }
                else {
                    ostr << ch;
                    result = false;
                }
                index++;
            }
        }
        return ostr << "</body>\n</html>";
    } 

    HtmlText::HtmlText(const char* title) {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
    }

    void HtmlText::clear()
    {
        if (m_title != nullptr) delete[] m_title;
        m_title = nullptr;
    }

    HtmlText::HtmlText() {
        m_title = nullptr;
    }

    HtmlText::HtmlText(HtmlText& H) {
        clear();
        if (H.m_title != nullptr) {
            m_title = new char[strlen(H.m_title) + 1];
            strcpy(m_title, H.m_title);
        }
        Text::operator=(H);
    }

    HtmlText& HtmlText::operator=(HtmlText& H) {
        clear();
        if (this != &H) {
            if (H.m_title != nullptr) {
                m_title = new char[strlen(H.m_title) + 1];
                strcpy(m_title, H.m_title);
            }
        }
        Text::operator=(H);
        return *this;
    }

    HtmlText::~HtmlText() {
            delete[] m_title;
    }

    istream& operator>>(istream& istr, HtmlText& H) {
        return H.read(istr);
    }

    ostream& operator<<(ostream& ostr, const HtmlText& H) {
        return H.write(ostr);
    }
}
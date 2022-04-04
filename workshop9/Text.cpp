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
#include "Text.h"
#include<cstring>
using namespace std;
namespace sdds {
    char* Text::content() const
    {
        return m_content;
    }

    const char& Text::operator[](int index)const {
        return m_content[index];
    }

    Text::Text() {
        m_content = nullptr;
    }

    Text::Text(const Text& T) {
        if (T.m_content != nullptr) {
            m_content = new char[strlen(T.m_content) + 1];
            strcpy(m_content, T.m_content);
        }
    }

    Text& Text::operator=(const Text& T) {
        dealloc();
        if (this != &T) {
            if (T.m_content != nullptr) {
                m_content = new char[strlen(T.m_content) + 1];
                strcpy(m_content, T.m_content);
            }
        }
        return *this;
    }

    Text::~Text() {
        delete[] m_content;
    }

    void Text::dealloc() {
        if (m_content != nullptr) {
            delete[] m_content;
        }
        m_content = nullptr;
    }

    int Text::getFileLength(std::istream& is) {
        int len{};
        if (is) {
            // save the current read position
            std::streampos cur = is.tellg();
            // go to the end
            is.seekg(0, ios::end);
            // let what is the positions (end position = size)
            len = is.tellg();
            // now go back to where you were.
            is.seekg(cur);
        }
        return len;
    }

    istream& Text::read(istream& istr) {
        dealloc();
        if (getFileLength(istr)) {
            m_content = new char[getFileLength(istr) + 1];
            char c;
            int i = 0;
            while (istr.get(c)) m_content[i++] = c;
            m_content[i] = '\0';

            istr.clear();
        }
        return istr;
    }

    ostream& Text::write(ostream& ostr) const {
            return ostr << m_content;
    }   

    istream& operator>>(istream& istr, Text& T) {
        return T.read(istr);
    }

    ostream& operator<<(ostream& ostr, const Text& T) {
        return T.write(ostr);
    }
}

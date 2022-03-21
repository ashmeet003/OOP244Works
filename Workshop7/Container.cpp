#define _CRT_SECURE_NO_WARNINGS
#include "Container.h"
using namespace std;
using namespace sdds;
void Container::setEmpty() {
    m_validContainer = false;
}

int Container::capacity() const {
    return m_capacity;
}

int Container::volume() const {
    return m_contentVolume;
}

Container::Container(const char* content, int capacity, int contentVolume) {
    if (content == NULL || contentVolume > capacity) {
        m_validContainer = false;
    }
    else {
        strcpy(this->m_content, content);
        this->m_capacity = capacity;
        this->m_contentVolume = contentVolume;
        m_validContainer = true;
    }
}

int Container::operator += (int value) {
    if (m_contentVolume + value <= m_capacity) {
        m_contentVolume += value;
    }
    else {
        value = m_capacity - m_contentVolume;
        m_contentVolume = m_capacity;
    }
    return value;
}

int Container::operator -= (int value) {
    if (m_contentVolume - value >= 0) {
        m_contentVolume -= value;
    }
    else {
        value = m_contentVolume;
        m_contentVolume = 0;
    }
    return value;
}

bool Container::valid() const {
    return m_validContainer;
}

void Container::clear(int capacity, const char* content) {
    if (capacity >= 1 && content != NULL && strlen(content) >= 1) {
        this->m_capacity = capacity;
        strcpy(this->m_content, content);
        this->m_contentVolume = 0;
        m_validContainer = true;
    }
}

ostream& Container::print(ostream& ostr) const {
    if (m_validContainer) {
        ostr << m_content << ": (" << m_contentVolume << "cc/" << m_capacity << ")";
    }
    else {
        ostr << "****: (**cc/***)";
    }
    return ostr;
}

istream& Container::read(istream& istr) {
    int value;
    if (!m_validContainer) {
        cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
        istr.ignore();
    }
    else {
        bool result = false;
        cout << "Add to ";
        print(cout);
        while (!result) {
            cout << endl << "> ";
            istr >> value;
            if (value > m_capacity) {
                cout << "Invalid Integer, retry:";
            }
            else if (value < 1 || value > 999) {
                cout << "Value out of range [1<=val<=999]:";
            }
            else result = true;
        }
        value = (*this += value);
        cout << "Added " << value << " CCs" << endl;
    }

    return istr;
}

std::ostream& sdds::operator<<(std::ostream& ostr, const Container& C)
{
        return C.print(ostr);
}

std::istream& sdds::operator>>(std::istream& istr, Container& C)
{
    return C.read(istr);
}

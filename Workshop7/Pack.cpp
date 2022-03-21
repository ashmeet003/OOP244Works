#include "Pack.h"
using namespace std;
using namespace sdds;

    Pack::Pack(const char* content, int size, int unitSize, int numberOfUnits)
        :Container(content, size * unitSize, unitSize * numberOfUnits) {
        this->m_size = size;
        this->m_unitSize = unitSize;
        this->m_numberOfUnits = numberOfUnits;
    }

    int Pack::operator += (int units) {
        int calculate = Container::operator+=(units * m_unitSize) / m_unitSize;
        this->m_numberOfUnits += calculate;
        return calculate;
    }

    int Pack::operator -= (int units) {
        int calculate = Container::operator-=(units * m_unitSize) / m_unitSize;
        this->m_numberOfUnits -= calculate;
        return calculate;
    }

    int Pack::unit() const {
        return m_unitSize;
    }

    int Pack::noOfUnits() const{
        return m_numberOfUnits;
    }

    int Pack::size() const{
        return m_size;
    }

    void Pack::clear(int packSize, int unitSize, const char* content) {
        if (unitSize > 0) {
            Container::clear(packSize * unitSize, content);
            this->m_size = packSize;
            this->m_unitSize = unitSize;
            this->m_numberOfUnits = 0;
        }
    }

    ostream& Pack::print(ostream& ostr)const {
        Container::print(ostr);
        if (valid())
            ostr << ", " << m_numberOfUnits << " in a pack of " << m_size;
        return ostr;
    }

    istream& Pack::read(istream& istr) {
        int units;
        if (!valid()) {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            istr.ignore();
        }
        else if (m_numberOfUnits == m_size) {
            istr.ignore();
            cout << "Pack is full!, press <ENTER> to continue...";
            istr.ignore();
        }
        else {
            bool result = false;
            cout << "Add to ";
            print(cout);
            int maxValue = m_size - m_numberOfUnits;
            while (!result) {
                cout << endl << "> ";
                istr >> units;
                if (units > m_size)
                    cout << "Invalid Integer, retry: ";
                else if (units < 1 || units > maxValue) {
                    cout << "Value out of range [1<=val<=" << maxValue << "]: ";
                    cout << maxValue << endl;; result = true;
                }
                else
                    result = true;
            }
            units = (*this += units);
            cout << "Added " << units << endl;
        }
        return istr;
    }

    std::ostream& sdds::operator<<(std::ostream& ostr, const Pack& P)
    {
        return P.print(ostr);
    }

    std::istream& sdds::operator>>(std::istream& istr, Pack& P)
    {
        return P.read(istr);
    }

#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include <iostream>
#include "Container.h"
namespace sdds {
    class Pack : public Container {
    private:
        int m_unitSize;
        int m_size;
        int m_numberOfUnits;
    public:    
        Pack(const char* content, int size, int unitSize = 330, int numberOfUnits = 0);
        int operator += (int units);
        int operator -= (int units);
        int unit()const;
        int noOfUnits()const;
        int size()const;
        void clear(int packSize, int unitSize, const char* content);
        std::ostream& print(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator << (std::ostream& ostr, const Pack& P);
    std::istream& operator >> (std::istream& istr, Pack& P);
}


#endif //!SDDS_PACK_H
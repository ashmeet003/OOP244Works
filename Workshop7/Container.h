#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include <iostream>
#include <cstring>
namespace sdds {
    class Container {
    private:
        char m_content[50]{};
        int m_capacity{};
        int m_contentVolume{};
        bool m_validContainer{};
    protected:
        void setEmpty();
        int capacity()const;
        int volume()const;
    public:
        Container(const char* content, int capacity, int contentVolume = 0);
        int operator += (int value);
        int operator -= (int value);
        bool valid() const;
        void clear(int capacity, const char* content);
        std::ostream& print(std::ostream& ostr=std::cout) const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator << (std::ostream& ostr, const Container& C);
    std::istream& operator >> (std::istream& istr, Container& C);
}

#endif //!SDDS_CONTAINER_H
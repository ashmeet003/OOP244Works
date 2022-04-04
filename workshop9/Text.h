/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: April 3 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <iostream>
namespace sdds {
    class Text {
    private:
        char* m_content{};
    protected:
        char* content() const;
        const char& operator[](int index)const;
        void dealloc();
    public:
        Text();
        Text(const Text& T);
        Text& operator=(const Text& T);
        virtual ~Text();
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
        int getFileLength(std::istream& istr);
    };   
    std::istream& operator>>(std::istream& istr, Text& T);
    std::ostream& operator<<(std::ostream& ostr, const Text& T);
}

#endif //!SDDS_TEXT_H
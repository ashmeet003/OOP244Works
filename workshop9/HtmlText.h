/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: April 3 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include <iostream>
#include "Text.h"
namespace sdds {
    class HtmlText : public Text {
    private:
        char* m_title{};
    public:
        HtmlText();
        HtmlText(HtmlText& H);
        HtmlText& operator=(HtmlText& H);
        ~HtmlText();
        HtmlText(const char* title);
        void clear();
        std::ostream& write(std::ostream& ostr) const;
    };
    std::istream& operator>>(std::istream& istr, HtmlText& H);
    std::ostream& operator<<(std::ostream& ostr, const HtmlText& H);
}

#endif //!SDDS_HTMLTEXT_H
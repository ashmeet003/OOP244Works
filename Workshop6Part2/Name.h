/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 07, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>
#include <cstring>
namespace sdds
{
    class Name{
    private:
        char* fname;
        char* mname;
        char* lname;
        bool abbereviation;       
    public:
        Name();
        Name(const char* fname, const char* mname , const char* lname);
        Name(const Name& N);
        Name(const char* fname, const char* lname);
        Name(const char* fname);
        ~Name();
        void setEmpty();
        Name& operator=(const Name& N);
        void setShort(bool abber);
        Name& operator+=(const char* str);
        const char* getf() const;
        const char* getm() const;
        const char* getl() const;
        operator bool() const;
        bool checkSpace(const char* str);
        bool isvalid() const;
        bool isShort() const;
    };
    std::istream& operator>>(std::istream& istr, Name& name);
    std::ostream& operator<<(std::ostream& ostr, const Name& name);
}
#endif // !SDDS_NAME_H
/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 07, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Name.h"
using namespace std;
namespace sdds
{
    const int MAX_NAME_LEN = 20;
    bool Name::checkSpace(const char* str)
    {
        bool result = true;
        while (*str != '\0') {
            if (!isspace(*str)) {
                result = false;
                break;
            }
            str++;
        }
        return result;
    }
    Name::Name()
    {
        fname = nullptr;
        mname = nullptr;
        lname = nullptr;
        abbereviation = false;
    }

    Name::Name(const char* fname, const char* mname, const char* lname)
    {
        if (fname == nullptr || mname == nullptr || lname == nullptr)
            setEmpty();
        else{
            if (!checkSpace(fname)){
                this->fname = new char[strlen(fname) + 1];
                strcpy(this->fname, fname);
            }
            else
                this->fname = nullptr;
            if (!checkSpace(mname)){
                this->mname = new char[strlen(mname) + 1];
                strcpy(this->mname, mname);
            }
            else
                this->mname = nullptr;
            if (!checkSpace(lname)){
                this->lname = new char[strlen(lname) + 1];
                strcpy(this->lname, lname);
            }
            else
                this->lname = nullptr;
            abbereviation = false;
        }
    }
    
    Name::Name(const Name& N)
    {
        if (N.fname != nullptr){
            fname = new char[strlen(N.fname) + 1];
            strcpy(fname, N.fname);
        }
        else
            fname = nullptr;
        if (N.mname != nullptr){
            mname = new char[strlen(N.mname) + 1];
            strcpy(mname, N.mname);
        }
        else
            mname = nullptr;
        if (N.lname != nullptr){
            lname = new char[strlen(N.lname) + 1];
            strcpy(lname, N.lname);
        }
        else
            lname = nullptr;
        abbereviation = N.abbereviation;
    }
    
    Name::Name(const char* fname, const char* lname)
    {
        if (fname == nullptr || lname == nullptr)
            setEmpty();
        else{
            if (!checkSpace(fname)){
                this->fname = new char[strlen(fname) + 1];
                strcpy(this->fname, fname);
            }
            else
                this->fname = nullptr;
            this->mname = nullptr;
            if (!checkSpace(lname)){
                this->lname = new char[strlen(lname) + 1];
                strcpy(this->lname, lname);
            }
            else
                this->lname = nullptr;
            abbereviation = false;
        }
    }
    
    Name::Name(const char* fname)
    {
        if (fname != nullptr){
            this->fname = new char[strlen(fname) + 1];
            strcpy(this->fname, fname);
            this->mname = nullptr;
            this->lname = nullptr;
            abbereviation = false;
        }          
        else
            setEmpty();
    }
    
    Name::~Name()
    {
        delete[] fname;
        delete[] mname;
        delete[] lname;
    }
    
    Name& Name::operator=(const Name& N)
    {
        if (this != &N){
            delete[] fname;
            delete[] mname;
            delete[] lname;
            if (N.fname != nullptr && !checkSpace(N.fname)){
                fname = new char[strlen(N.fname) + 1];
                strcpy(fname, N.fname);
            }
            else
                fname = nullptr;
            if (N.mname != nullptr && !checkSpace(N.mname)){
                mname = new char[strlen(N.mname) + 1];
                strcpy(mname, N.mname);
            }
            else
                mname = nullptr;
            if (N.lname != nullptr && !checkSpace(N.lname)){
                lname = new char[strlen(N.lname) + 1];
                strcpy(lname, N.lname);
            }
            else
                lname = nullptr;
        }
        return *this;
    }

    void Name::setEmpty()
    {
        delete[] fname;
        delete[] mname;
        delete[] lname;
        fname = nullptr;
        mname = nullptr;
        lname = nullptr;
        abbereviation = false;
    }
    
    void Name::setShort(bool abber){
        this->abbereviation = abber;
    }
    
    Name& Name::operator+=(const char* str){
        if (str != nullptr && !checkSpace(str)){
            if (fname == nullptr){
                fname = new char[strlen(str) + 1];
                strcpy(fname, str);
            }
            else if (mname == nullptr){
                mname = new char[strlen(str) + 1];
                strcpy(mname, str);
            }
            else if (lname == nullptr){
                lname = new char[strlen(str) + 1];
                strcpy(lname, str);
            }
            else
                setEmpty();
        }
        return *this;
    }

    Name::operator bool() const {
        return isvalid();
    }

    const char* Name::getf() const {
        return fname;
    }

    const char* Name::getm() const {
        return mname;
    }

    const char* Name::getl() const {
        return lname;
    }

    bool Name::isvalid() const{
        bool result = true;
        if (fname == nullptr) result = false;
            return result;
    }

    bool Name::isShort() const{
        return abbereviation;
    }

    istream& operator>>(istream& istr, Name& name)
    {
        char f_name[MAX_NAME_LEN];
        char m_name[MAX_NAME_LEN];
        char l_name[MAX_NAME_LEN];
        char c;
        name.setEmpty();
        istr >> f_name;
        if (istr.fail())
            return istr;
        istr.get(c);
        if (c == '\n') {
            name = Name(f_name);
            return istr;
        }
        istr >> m_name;
        if (istr.fail()) {
            istr.clear();
            istr.ignore(MAX_NAME_LEN, '\n');
            return istr;
        }
        istr.get(c);
        if (c == '\n') {
            name = Name(f_name, m_name);
            return istr;
        }
        istr >> l_name;
        if (istr.fail()) {
            istr.clear();
            istr.ignore(MAX_NAME_LEN, '\n');
            return istr;
        }
        istr.get(c);
        if (istr.fail()) {
            istr.clear();
            istr.ignore(MAX_NAME_LEN, '\n');
            return istr;
        }
        if (c != '\n') {
            name.setEmpty();
            return istr;
        }
        name = Name(f_name, m_name, l_name);
        return istr;
    }

    ostream& operator<<(ostream& ostr, const Name& N) {
        if (N.isvalid()) {
            if (N.isShort()) {
                ostr << N.getf();
                if (N.getm() != nullptr && strlen(N.getm()) > 0)
                    ostr << ' ' << N.getm()[0] << ".";
                if (N.getl() != nullptr && strlen(N.getl()) > 0)
                    ostr << " " << N.getl();
            }
            else {
                ostr << N.getf();
                if (N.getm() != nullptr && strlen(N.getm()) > 0)
                    ostr << " " << N.getm();
                if (N.getl() != nullptr && strlen(N.getl()) > 0)
                    ostr << " " << N.getl();
            }
        }
        else
            ostr << "Bad Name";
        return ostr;
    }
}
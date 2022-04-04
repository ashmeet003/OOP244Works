/* Citation and Sources...
Final Project Milestone 3
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: April 3, 2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
Also, I have referred to @vrpatel30@myseneca.ca for getDoubleStream() and getIntStream(),
to understand the concept of using the mentioned functions and then implement them
 according to my understanding .

-----------------------------------------------------------
*/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>
#include <ctime>
#include <cstring>
namespace sdds
{
   const int sdds_testYear = 2022;
   const int sdds_testMon = 03;
   const int sdds_testDay = 31;
   class Utils
   {
      bool m_testMode = false;

   public:
      void getSystemDate(int *year = nullptr, int *mon = nullptr, int *day = nullptr);
      int daysOfMon(int mon, int year) const;
      void testMode(bool testmode = true);
      void alocpy(char *&destination, const char *source);
      int getint(const char *prompt = nullptr);
      int getint(int min, int max, const char *prompt = nullptr, const char *errMes = nullptr);
      double getdouble(const char *prompt = nullptr);
      double getdouble(double min, double max, const char *prompt = nullptr, const char *errMes = nullptr);
      int getIntStream(std::istream &istr, const char *prompt = nullptr);
      int getIntStream(std::istream &istr, int min, int max, const char *prompt = nullptr, const char *errMes = nullptr);
      double getDoubleStream(std::istream &istr, const char *prompt = nullptr);
      double getDoubleStream(std::istream &istr, double min, double max, const char *prompt = nullptr, const char *errMes = nullptr);
   };
   extern Utils ut;
}

#endif // !SDDS_UTILS_H

/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: March 06, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>;
namespace sdds {
	class Name {
		char* m_fname{};
		char* m_mname{};
		char* m_lname{};
		void setEmpty();
		bool isvalid(const char* name);
		void set(const char* fname, const char* lname, const char* mname);
	public:
		Name(const char* fname = nullptr, const char* lname = nullptr, const char* mname = nullptr);
		Name(const Name& N);
		Name& operator=(const Name& N);
		~Name();
		
		void setShort(bool arg = false);
		Name& operator+=(const Name& N);
		operator bool() const;
		std::istream& read(std::istream& istr);
	};
	char operator+=(Name& N, const char* name);
	std::istream& operator>>(std::istream& istr, Name& N);
	std::ostream& operator<<(std::ostream& ostr, const Name& N);
}
#endif // !SDDS_NAME_H

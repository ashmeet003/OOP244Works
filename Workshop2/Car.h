/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: January 27, 2021
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
namespace sdds
{
	struct Car {
		char licensePlate[9]="";
		char* Make_model = nullptr;
		int time=0;
	};

	void VBPLE_Title();
	void initialize(int allocSize);
	void deallocate(Car& C);
	bool read(Car& C);
	void print(const Car& C);
	void record(const Car& C);
	void  endOfDay();
}
#endif
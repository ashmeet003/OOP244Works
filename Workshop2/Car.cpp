/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: January 27, 2021
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "Car.h"
#include "cStrTools.h"
using namespace std;
namespace sdds {
	Car* cptr = nullptr;;
	int allocation_size;
	int numOfCars;
	int carArraySize;
	void VBPLE_Title()
	{
		cout << "Vehicle Border Passing Log Entry" << endl
			<< "Enter the data in the following format :" << endl
			<< "Make and model, LicensePlate, MilitaryTime<ENTER>" << endl
			<< "Exit the program by entering the following :" << endl
			<< "X, <ENTER>" << endl;
	}
	void initialize(int allocSize)
	{

		allocation_size = allocSize;
		numOfCars = 0;
		carArraySize = allocSize;
		cptr = new Car[allocation_size];
	}
	void deallocate(Car& C)
	{


		if (C.Make_model != nullptr) {
			delete[] C.Make_model;
			C.Make_model = nullptr;
		}
	}
	bool read(Car& C) {
		bool flag = false;
		char temp[60];
		read(temp, 60, ',');
		if (strCmp(temp, "X") != 0) { 
			flag = true;
			C.Make_model = new char[strLen(temp) + 1];
			strCpy(C.Make_model, temp);
			read(C.licensePlate, 9, ',');
			cin >> C.time;
			
		}
		return flag;
	}
	void print(const Car& C)
	{
		cout << C.time << ": " << C.Make_model << "," << C.licensePlate << endl;
		
	}
	void record(const Car& C)
	{
		
		if (numOfCars == carArraySize)
		{
			Car* tptr = new Car[carArraySize + allocation_size];
			for (int j = 0; j < carArraySize; j++) {
				tptr[j] = cptr[j];
			}
			
			delete[] cptr;
			cptr = tptr;
			carArraySize += allocation_size;
		}
		cptr[numOfCars++] = C;
	}
	void endOfDay()
	{

		for (int j = 0; j < carArraySize; j++)
		{
			print(cptr[j]);
			deallocate(cptr[j]);
		}

		delete[]cptr;
		cptr = nullptr;

	}
}

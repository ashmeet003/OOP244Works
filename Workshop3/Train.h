#pragma once
/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: February 6, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#ifndef NAMESPACE_TRAIN_H
#define NAMESPACE_TRAIN_H

#define MAX_NAME_LEN 20
#define MAX_PEOPLE 1000
#define MAX_SPEED 320

namespace sdds
{
	class Train
	{
		char nameOfTrain[MAX_NAME_LEN];
		int numOfPeople;
		double speedOfTrain;

	public:
		void set(const char*, int, double);

		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;

		bool isSafeEmpty() const;
		void display() const;
	};

}
#endif
/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: February 6, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Train.h"
using namespace std;

namespace seneca
{

	void Train::set(const char* name, int people, double speed) {
		if (name != nullptr && strlen(name) > 0) {//works to validate name of the train
			strncpy(nameOfTrain, name, MAX_NAME_LEN);
		}
		else {
			strcpy(nameOfTrain, " "); // sets Empty state as " "(invalid value) for the train name
		};

		if (people > 0 && people <= MAX_PEOPLE) {//works to validate number of people on train
			numOfPeople = people;
		}
		else {
			numOfPeople = 0; // sets Empty state as 0(invalid value) for the number of people
		};

		if (speed > 0 && speed <= MAX_SPEED) {
			speedOfTrain = speed;
		}

		else {
			speedOfTrain = 0; //sets Empty state as 0(invaild value) for the speed of train
		}
	}

	int Train::getNumberOfPeople() const {
		return numOfPeople;
	}
	const char* Train::getName() const {
		return nameOfTrain;
	}
	double Train::getSpeed() const {
		return speedOfTrain;
	}

	bool Train::isSafeEmpty() const {
		if (strcmp(nameOfTrain, " ") == 0 || speedOfTrain == 0 || numOfPeople == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Train::display() const {
		if (!isSafeEmpty()) {
			cout << "NAME OF THE TRAIN : " << nameOfTrain << endl;
			cout << "NUMBER OF PEOPLE  : " << numOfPeople << endl;
			cout << "SPEED             : " << speedOfTrain << " km/h" << endl;
		}
		else {
			cout << "Safe Empty State!\n";
		}

	}
	bool Train::changeSpeed(double speed)
	{
		bool result = false;
		if (!isSafeEmpty()) {
			double newSpeed = speedOfTrain + speed;
			if (newSpeed < 0)speedOfTrain = 0.00;
			if (newSpeed > MAX_SPEED)speedOfTrain = 320.00;
			else speedOfTrain = newSpeed;

			result = true;
		}
		return result;

	}
	bool Train::loadPeople(int  people)
	{
		bool result = false;
		if (!isSafeEmpty()) {
			int newNumOfPeople = numOfPeople + people;
			if (newNumOfPeople < 0)numOfPeople = 0;
			if (newNumOfPeople > MAX_PEOPLE)numOfPeople = MAX_PEOPLE;
			else numOfPeople = newNumOfPeople;

			result = true;
		}
		return result;
		;
	}
	int transfer(Train& train1, Train& train2) {
		int transferComplete = -1;
		if (!train1.isSafeEmpty() && !train2.isSafeEmpty()) {
			int actualT2 = train2.getNumberOfPeople(); int afterShift = 0;
			int canAfford = MAX_PEOPLE - actualT2;
			if (canAfford > 0 && actualT2 > 0) {
				int shift = 0;
				if (canAfford <= actualT2) {
					train1.loadPeople(canAfford);
					train2.loadPeople(-canAfford);
					transferComplete = canAfford;
				}
				if (canAfford > actualT2) {
					train1.loadPeople(actualT2);
					train2.loadPeople(-actualT2);
					transferComplete = actualT2;
				}
			}
		}
		return transferComplete;
	}
}
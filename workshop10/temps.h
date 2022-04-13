#ifndef SDDS_TEMPS_H
#define SDDS_TEMPS_H
#include "Collection.h"
#include <iostream>
namespace sdds {
	/*The template for select() needed oerator== for respective type to compare values.
	It also needed constructor to assign the size to new object of type Collection<T>
	Futhermore, the function needs a assignment operator to copy values from the given array to new array
	and also operator[] to access the values*/
	template <typename T>
	Collection<T> select(const T arr[], int a, const T& A) {
		int count = 0;
		for ( int i = 0; i < a; i++) {
			if (arr[i] == A) count++;			
		}
		unsigned int j = 0;
		Collection<T> s = Collection<T>(count);
		for ( int i = 0; i < a; i++) {
			if (arr[i] == A) s[j++] = arr[i];
		}
		return s;
	}
	/*The template for printCollection needed accessor method to get the size of the array and operator[] to access values
	Finally, the values are displayed usinf display() for each type*/
	template <typename T>
	void printCollection(const Collection<T>& A, const char* prompt) {
		std::cout << prompt << std::endl;
		for (int i = 0; i < A.size(); i++) {
			std::cout << A[i] << std::endl;
		}
	}
}
#endif // !SDDS_TEMPS_H
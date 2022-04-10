#ifndef SDDS_TEMPS_H
#define SDDS_TEMPS_H
#include "Collection.h"
#include <iostream>
namespace sdds {
	template <typename T>
	Collection<T> select(const T arr[], int a, const T& A) {
		int count = 0;
		for ( int i = 0; i < a; i++) {
			if (arr[i] == A) { count++;// std::cout << arr[i] << std::endl;
			}
		}
		unsigned int j = 0;
		Collection<T> s = Collection<T>(count);
		for ( int i = 0; i < a; i++) {
			if (arr[i] == A) s[j++] = arr[i];
		}
		return s;
	}

	template <typename T>
	void printCollection(const Collection<T>& A, const char* prompt) {
		std::cout << prompt << std::endl;
		for (int i = 0; i < A.size(); i++) {
			std::cout << A[i] << std::endl;
		}
	}
	//void sort(T arr[], int n, bool Ascending = true)
}
#endif // !SDDS_TEMPS_H
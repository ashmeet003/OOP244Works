/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: January 27, 2021
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/

#include "Car.h"
using namespace sdds;

int main() {
    Car C;
    VBPLE_Title();
    // the value "2" is passed to make testing easier
    // in the tester program on submission it will be set to higher value
    initialize(2);
    while (read(C)) {
        
        record(C);
    }
    
    endOfDay();
    return 0;
}

/*
Name : Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: January 20, 2021
*/
#include <iostream>
#include "Word.h"
#include "cStrTools.h" // This is intentional
using namespace sdds;
using namespace std;
int main() {
    char filename[256];
    //cout << "Enter the following file name" << endl
     //   << "> FoxInSocks.txt" << endl << "---------------------" << endl;
    programTitle();
    cout << "Enter filename: ";
    cin >> filename;
    wordStats(filename);
    return 0;
}

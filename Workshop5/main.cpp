/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: February 17, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#include <iostream>
#include "Flight.h"
using namespace std;
using namespace sdds;
void display_filght_details(const Flight* fl, int num){
    cout << "+------------------------------------------------------------------------------+" << endl;
    for (int i = 0; i < num; i++)
    {
        fl[i].display() << endl;
    }
    cout << "+------------------------------------------------------------------------------+" << endl;
}
int main(){
    int total_passengers;
    Flight f[] =
    {
       {200, 300000, "BA 504"},
       {100, 65000, "MD 432"},
       {300, 195000, "CAD 453"},
       {150,97500 , "IND 678"},
       {70, 45500, "FRN 435"},
       {-500, 5000, "SA 435"},
       {270, 17550, "ZAA 500"}
    };
    display_filght_details(f, 7);
    cout << " Total passengers in " << (const char*)(f[2]) << " and " << (const char*)(f[4]) << " is:  " << (total_passengers = f[2] + f[4]) << endl;
    cout << " Total fuel in " << (const char*)(f[2]) << " and " << (const char*)(f[4]) << " is:  " << double(f[2]) + double(f[4]) << endl;
    cout << "+------------------------------------------------------------------------------+" << endl;

    total_passengers = 0;
    total_passengers += f[1];
    total_passengers += f[3];

    cout << " Total passengers in " << (const char*)(f[1]) << " and " << (const char*)(f[3]) << " is:  " << total_passengers << endl;
    cout << " Total fuel in " << (const char*)(f[1]) << " and " << (const char*)(f[3]) << " is:  " << double(f[1]) + double(f[3]) << endl;
    cout << "+------------------------------------------------------------------------------+" << endl;
    cout << " Total passengers in " << (const char*)(f[1]) << " is:  " << int(f[1]) << endl;
    cout << " Total passengers in " << (const char*)(f[2]) << " is:  " << int(f[2]) << endl;
    cout << " Total passengers in " << (const char*)(f[3]) << " is:  " << int(f[3]) << endl;
    cout << " Total passengers in " << (const char*)(f[4]) << " is:  " << int(f[4]) << endl;
    cout << "+------------------------------------------------------------------------------+" << endl;

    f[5] = f[1];
    f[2] >> f[3];
    display_filght_details(f, 7);
    f[6] += 160000.50;
    f[4] -= 15000.50;
    f[2] += 200;
    f[3] -= 300;
    display_filght_details(f, 7);
    f[0] = 300;
    f[4] = 200000.50;
    display_filght_details(f, 7);
    return 0;
}
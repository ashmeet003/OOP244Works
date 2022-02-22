/* ------------------------------------------------------
Workshop 5 part 2
Module: N/A
Filename: main.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#include <iostream>
#include "Portfolio.h"
using namespace std;
using namespace sdds;

void portfolioDisplay(const Portfolio* portfolio, int num) {
      cout << "+----------------------------------------------------------------+" << endl;
      for (int i = 0; i < num; i++) {
          portfolio[i].display() << endl;
      }
      cout << "+----------------------------------------------------------------+" << endl;
}

int main() {
   double total;
   Portfolio P[] = {
      {300000, "Fitzer", 'F'},   // invalid
      {400000, "Fitzer", 'G'},
      {500000, "Honda", 'I'},
      {140000, "RIM", 'V'},
      {-500000, "Nortel", 'V'},  // invalid
      {95000, "Nvdia", 'G'},
   };
   portfolioDisplay(P, 6);
   cout << " Total Investment in " << (const char*)(P[2]) << " and " << (const char*)(P[5]) << " is:  " << (total = P[2] + P[5]) << endl;
   cout << " Total Investment in " << (const char*)(P[1]) << " and " << (const char*)(P[3]) << " is:  " << double(P[1]) + double( P[3]) << endl;
   cout << "+----------------------------------------------------------------+" << endl;
   total = 0;
   total += P[1];
   total += P[5];
   cout << " Total Investment in " << (const char*)(P[1]) << " and " << (const char*)(P[5]) << " is:  " << total << endl;
   P[2] >> P[3];
   P[1] << P[5];
   portfolioDisplay(P, 6);
   P[5] += 250005.50;
   P[4] -= 150000.50;
   portfolioDisplay(P, 6);
   P[3] += 60000.50;
   P[1] -= 95000.00;
   portfolioDisplay(P, 6);
   return 0;
}
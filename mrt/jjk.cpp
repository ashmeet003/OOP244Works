#include <iostream>
using namespace std;
int main() {
	char str[20];
	cin.ignore(5, 'c');
	cin >> str;
	cout << str;
	return 0;
}
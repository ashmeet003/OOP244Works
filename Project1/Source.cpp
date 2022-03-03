#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class Car {
public:
    ostream& print(ostream& ostr) const {
        return cout << m_plate;
    }
    Car(const char* plate = nullptr) {
        if (plate)
            strcpy(m_plate, plate);
    }
private:
    char m_plate[10]{};
};
ostream& operator<<(ostream& ostr, Car& P) {
    return P.print(ostr);
}
class Parking {
public://change
    operator int()const {
        return m_count;
    }
    bool operator!() {
        return m_count == 0;
    }
    const Car& operator[](int index)const {
        return m_cars[index % m_count];
    }
    Parking& operator<<(const Car& P) {
        Car* temp = new Car[m_count + 1];
        m_cars[m_count] = P;//change
        for (int i = 0; i < m_count; i++)
            temp[i] = m_cars[i];
        delete[] m_cars;
        m_cars = temp;
        m_count++;
        return *this;
    }
private:
    int m_count{};//change
    Car* m_cars{};
};
ostream& operator<<(ostream& ostr, const Parking& L) {
    for (int i = 0; i < L; i++) {
        ostr << i + 1 << ":" << L << " ";//change
    }
    return ostr;
}
void listCars(const Parking& L, const char* title) {
    cout << title;
    if (!L)
        cout << " is empty!";
    else
        cout << endl << L;
    cout << endl << "--------------" << endl;
}
int main() {
    Parking L;
    Car P;
    listCars(L, "Empty Parking");
    L << "GVBT443" << "ACDT456" << "BBCT345";
    listCars(L, "Seneca Parking");
    cout << "Empty: " << P << endl;
    P = "GVCT306";
    cout << "Not Empty: " << P << endl;
    return 0;
}


/*
* Intended output
Empty Parking is empty!
--------------
Seneca Parking
01:GVBT443 02:ACDT456 03:BBCT345
--------------
Empty:
Not Empty: GVCT306

*/
#include <iostream>
using namespace std;

unsigned long long factorialB(int n);
unsigned long long factorialA(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorialB(n - 1); // rekursif tidak langsung
    }
}

unsigned long long factorialB(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorialA(n - 1); 
    }
}

int main() {
    int number;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> number;

    if (number < 0) {
        cout << "Input tidak valid. Silakan masukkan bilangan bulat positif." << endl;
    } else {
        unsigned long long result = factorialA(number);
        cout << "Faktorial dari " << number << " adalah " << result << endl;
    }
    return 0;
}

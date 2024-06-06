#include <iostream>
// Fungsi rekursif faktorial
unsigned long long factorial(int n) {
    // Basis kasus: jika n adalah 0 atau 1, faktorialnya adalah 1
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number;
    std::cout << "Masukkan bilangan bulat positif: ";
    std::cin >> number;
    if (number < 0) {
        std::cout << "Input tidak valid. Silakan masukkan bilangan bulat positif." << std::endl;
    } else {
        unsigned long long result = factorial(number);
        std::cout << "Faktorial dari " << number << " adalah " << result << std::endl;
    }

    return 0;
}

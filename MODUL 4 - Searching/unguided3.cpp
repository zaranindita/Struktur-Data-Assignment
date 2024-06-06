#include <iostream>

// fungsi untuk mencari berapa banyak angka 4 
int cari (int angka[], int panjang) {
    int count = 0;
    for (int i = 0; i < panjang; ++i) {
        if (angka[i] == 4) {
            count++;
        }
    }
    return count;
}

int main() {
    int angka[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int panjang = sizeof(angka) / sizeof(angka[0]);

    std::cout << "angka: ";
    for (int i = 0; i < panjang; ++i) {
        std::cout << angka[i] << " ";
    }
    std::cout << std::endl;

    int fours_count = cari(angka, panjang);
    std::cout << "jumlah angka 4: " << fours_count << std::endl;

    return 0;
}

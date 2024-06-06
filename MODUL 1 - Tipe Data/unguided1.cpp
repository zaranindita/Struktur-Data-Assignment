#include <iostream>

using namespace std;

// Fungsi untuk menghitung luas segitiga
float hitungLuasSegitiga(float alas, float tinggi) {
    return 0.5 * alas * tinggi;
}

// Fungsi untuk menghitung luas persegi
float hitungLuasPersegi(float sisi) {
    return sisi * sisi;
}

int main() {
    float alasSegitiga, tinggiSegitiga, sisiPersegi;

    // Input alas dan tinggi segitiga
    cout << "Masukkan alas segitiga: ";
    cin >> alasSegitiga;
    cout << "Masukkan tinggi segitiga: ";
    cin >> tinggiSegitiga;

    // Hitung dan tampilkan luas segitiga
    cout << "Luas segitiga adalah: " << hitungLuasSegitiga(alasSegitiga, tinggiSegitiga) << endl;

    // Input sisi persegi
    cout << "Masukkan sisi persegi: ";
    cin >> sisiPersegi;

    // Hitung dan tampilkan luas persegi
    cout << "Luas persegi adalah: " << hitungLuasPersegi(sisiPersegi) << endl;

    return 0;
}
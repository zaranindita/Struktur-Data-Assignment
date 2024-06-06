#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    char choice;
    do {
        //masukkan data array
        cout << "Masukkan data array (pisahkan dengan spasi): ";
        string data_input;
        getline(cin, data_input);

        //string input menjadi vector of integers
        stringstream ss(data_input);
        vector<int> data_array;
        int num;
        while (ss >> num) {
            data_array.push_back(num);
        }

        //pemisah genap ganjil
        vector<int> genap, ganjil;
        for (int num : data_array) {
            if (num % 2 == 0) {
                genap.push_back(num);
            } else {
                ganjil.push_back(num);
            }
        }

        // hasil
        cout << "Data array: ";
        for (int num : data_array) {
            cout << num << " ";
        }
        cout << endl;

        cout << "Genap: ";
        for (int num : genap) {
            cout << num << " ";
        }
        cout << endl;

        cout << "Ganjil: ";
        for (int num : ganjil) {
            cout << num << " ";
        }
        cout << endl;

        // Meminta pengguna untuk memilih apakah ingin melanjutkan atau keluar dari program
        cout << "Apakah Anda ingin memasukkan data array lagi? (y/n): ";
        cin >> choice;
        cin.ignore(); // Membersihkan buffer agar tidak mempengaruhi getline()
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

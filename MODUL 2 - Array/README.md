# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Zahra Adya Nindita (2311110027)</p>


## Unguided 

### 1.  Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

```C++
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
```


### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int dim1, dim2, dim3;

    // Meminta pengguna untuk memasukkan ukuran array tiga dimensi
    cout << "Masukkan jumlah elemen untuk dimensi 1: ";
    cin >> dim1;
    cout << "Masukkan jumlah elemen untuk dimensi 2: ";
    cin >> dim2;
    cout << "Masukkan jumlah elemen untuk dimensi 3: ";
    cin >> dim3;

    // Membuat array tiga dimensi berdasarkan input pengguna
    vector<vector<vector<int>>> array3D(dim1, vector<vector<int>>(dim2, vector<int>(dim3)));

    // Meminta pengguna untuk memasukkan nilai setiap elemen array
    cout << "Masukkan nilai untuk setiap elemen array:" << endl;
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                cout << "Elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> array3D[i][j][k];
            }
        }
    }

    // Menampilkan array tiga dimensi
    cout << "Array tiga dimensi yang dimasukkan:" << endl;
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                cout << array3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>
#include <limits>

using namespace std;

int main() {
    char choice;
    do {
        int n;
        cout << "Masukkan jumlah elemen dalam array: ";
        cin >> n;

        // membuat array
        int arr[n];

        // input elemen array
        cout << "Masukkan elemen-elemen array:\n";
        for (int i = 0; i < n; ++i) {
            cout << "Elemen ke-" << i + 1 << ": ";
            cin >> arr[i];
        }

        // mencari maksimum
        int max = INT_MIN; // Inisialisasi dengan nilai minimum yang mungkin
        for (int i = 0; i < n; ++i) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        // mencari minimum
        int min = INT_MAX; // Inisialisasi dengan nilai maksimum yang mungkin
        for (int i = 0; i < n; ++i) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        // hitung rata-rata
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
        }
        double average = static_cast<double>(sum) / n;

        // hasil
        cout << "Nilai maksimum: " << max << endl;
        cout << "Nilai minimum: " << min << endl;
        cout << "Nilai rata-rata: " << average << endl;

        // memilih apakah ingin memasukkan data array lagi
        cout << "Apakah Anda ingin memasukkan data array lagi? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
```

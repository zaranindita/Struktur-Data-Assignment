# <h1 align="center">Laporan Praktikum Modul SORTING</h1>
<p align="center">Zahra Adya Nindita (2311110027)</p>


## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima
lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS
sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS
mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma
Selection Sort! (Score: 30)


```C++
#include <iostream>

// Fungsi untuk mengurutkan dengan selection sort
void selectionSort(double arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int max_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        std::swap(arr[i], arr[max_index]);
    }
}

int main() {
    // IPS mhs
    double ips_MHS[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int n = sizeof(ips_MHS) / sizeof(ips_MHS[0]);

    // Mengurutkan 
    selectionSort(ips_MHS, n);

    // Output 
    std::cout << "IPS mahasiswa setelah diurutkan:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << ips_MHS[i] << "    ";
    }
    std::cout << std::endl;

    return 0;
}
```
Kode di atas digunakan untuk mengurutkan IPS Mhs dengan selection sort.


### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo,
dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan
menggunakan algoritma Bubble Sort! (Score: 30)

```C++
#include <iostream>
#include <string>

// Fungsi mengurutkan array dengan bubble sort
void bubbleSort(std::string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    // Nama
    std::string nama[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(nama) / sizeof(nama[0]);

    // Mengurutkan nama 
    bubbleSort(nama, n);

    // Output 
    std::cout << "Nama setelah diurutkan:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << nama [i] << "   ";
    }
    std::cout<<std::endl;

    return 0;
}
```
Kode di atas digunakan untuk mengurutkan nama warga dengan bubble sort.

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user
untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting
secara menaik (ascending) dan menurun (descending)! (Score: 40)

```C++
#include <iostream>

// fungsi untuk ascending
void ascendingSort(char arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// fungsi untuk descending
void descendingSort(char arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    char choice;

    do {
        int n;

        // memasukkan nilai n
        std::cout << "Masukkan jumlah karakter (n): ";
        std::cin >> n;

        char characters[n];

        //  masukkan karakter
        std::cout << "Masukkan " << n << " karakter:" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cin >> characters[i];
        }
        
        // output sebelum pengurutan
        std::cout << "Hasil sebelum pengurutan: ";
        for (int i = 0; i < n; ++i) {
            std::cout << characters[i] << " ";
        }
        std::cout << std::endl;

        //  pengurutan ascending
        ascendingSort(characters, n);

        // output ascending
        std::cout << "Hasil pengurutan ascending: ";
        for (int i = 0; i < n; ++i) {
            std::cout << characters[i] << " ";
        }
        std::cout << std::endl;

        // pengurutan descending
        descendingSort(characters, n);

        // output descending
        std::cout << "Hasil pengurutan descending: ";
        for (int i = 0; i < n; ++i) {
            std::cout << characters[i] << " ";
        }
        std::cout << std::endl;

        // melanjutkan atau tidak
        std::cout << "Ingin melanjutkan? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
```
Kode di atas digunakan untuk mengurutkan karakter yang diinginkan secara ascending maupun descending.

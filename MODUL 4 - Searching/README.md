# <h1 align="center">Laporan Praktikum Searching</h1>
<p align="center">Zahra Adya Nindita (23111110027)</p>

## Dasar Teori
Pencarian (Searching) yaitu proses menemukan suatu nilai tertentu pada kumpulan data. Hasil pencarian adalah salah satu dari tiga keadaan 
ini: data ditemukan, data ditemukan lebih dari satu, atau data tidak
ditemukan.. Searching juga dapat dianggap sebagai proses pencarian suatu
data di dalam sebuah array dengan cara mengecek satu persatu pada
setiap index baris atau setiap index kolomnya dengan menggunakan teknik
perulangan untuk melakukan pencarian data.
1. Sequential Search
Sequential Search merupakan salah satu algoritma pencarian data
yang biasa digunakan untuk data yang berpola acak atau belum terurut.
2. Binary Search
Binary Search termasuk ke dalam interval search, dimana algoritma
ini merupakan algoritma pencarian pada array/list dengan elemen terurut.


## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah
kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <cstring>

// fungsi binary search huruf 
int binary_search(char arr[], int n, char target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    const int ukuranmaks = 100;
    char kalimat[ukuranmaks];
    char huruf;

    // memasukkan kalimat
    std::cout << "Masukkan kalimat: ";
    std::cin.getline(kalimat, ukuranmaks);

    // huruf yang ingin dicari
    std::cout << "Masukkan huruf yang ingin dicari: ";
    std::cin >> huruf;
    huruf = tolower(huruf); // ubah huruf menjadi huruf kecil

    // panjang kalimat
    int len = strlen(kalimat);

    // mengurutkan kalimat (Bubble Sort)
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (kalimat[j] > kalimat[j + 1]) {
                char temp = kalimat[j];
                kalimat[j] = kalimat[j + 1];
                kalimat[j + 1] = temp;
            }
        }
    }

    // mencari huruf 
    int index = binary_search(kalimat, len, huruf);
    if (index != -1) {
        std::cout << "Huruf '" << huruf << "' ditemukan pada indeks ke-" << index << " dalam kalimat." << std::endl;
    } else {
        std::cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << std::endl;
    }

    return 0;
}
```

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf
vocal dalam sebuah kalimat!

```C++
#include <iostream>

// Fungsi untuk mencari berapa banyak angka 4 
int hitung(int data[], int panjang) {
    int count = 0;
    for (int i = 0; i < panjang; ++i) {
        if (data[i] == 4) {
            count++;
        }
    }
    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int panjang = sizeof(data) / sizeof(data[0]);

    std::cout << "Data angka: ";
    for (int i = 0; i < panjang; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    int hitungvokal = hitung(data, panjang);
    std::cout << "Jumlah angka 4 dalam data: " << hitungvokal << std::endl;

    return 0;
}
```
### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak
angka 4 dengan menggunakan algoritma Sequential Search!

```C++
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
```

# <h1 align="center">Laporan Praktikum Searching</h1>
<p align="center">Zahra Adya Nindita (23111110027)</p>

## Dasar Teori
1. Sequential Search merupakan metode pencarian data dalam array dengan cara membandingkan data yang dicari
dengan data yang ada di dalam array secara berurutan. Pencarian data dengan metode sequential search efektif untuk mencari data yang dalam posisi tidak berurut atau acak(Sitorus, 2015).
2. Algoritma binary search merupakan salah satu algoritma yang digunakan untuk melakukan proses pencarian data yang sudah terurut (Sulistio et al.,2019


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
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/54c0a906-ed3a-495a-8d02-33fd11434037)

Program di atas adalah program  yang mencari huruf tertentu dalam sebuah kalimat yang dimasukkan pengguna. Program ini menggunakan algoritma Binary Search setelah mengurutkan kalimat menggunakan Bubble Sort.

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
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/813061ae-ed23-4d64-9319-87152671eeb6)

Program untuk menghitung jumlah huruf vokal dalam sebuah kalimat yang dimasukkan oleh pengguna.

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
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/4e9ec6cb-8e56-46be-b82e-b39d9e2a5a53)
Program di atas adalah program yang mencari dan menghitung berapa kali angka 4 muncul dalam sebuah array. 

## Referensi
[1]. Bhakti Siswanto,Nia Nuraeni (2022). Implementasi Algoritma Sequential Searching pada Pencarian Transaksi Bilyet Giro Wisma BCA Pondok Indah Berbasis Website. Vol.10 No.1, pp. 6-11

[2]. Bernad Jumadi Dehotman Sitompul, Ade Yusupa, Nancy Jeane Tuturoong (2022) IMPLEMENTASI ALGORITMA BINARY SEARCH PADA PENCARIAN DATA JEMAAT GEREJA HKBP MANADO

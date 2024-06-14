# <h1 align="center">Laporan Praktikum Modul Rekursif & Hash Tabel</h1>
<p align="center">Zahra Adya Nindita (2311110027)</p>

## Dasar Teori

1. Rekursif adalah sebuah algoritma yang berisi pemanggilan dirinya sendiri sehingga menghasilkan looping. Harus ada batasan di dalam rekursif sehingga looping dapat dibatalkan, jika tidak maka akan terjadi infinity loop dan
dapat menyebabkan memori penuh.

2. Hash adalah transformasi aritmatik sebuah string dari karakter menjadi nilai yang merepresentasikan string
aslinya. Menurut bahasanya, hash berarti memenggal dan kemudian menggabungkan. Hashing digunakan sebagai metode untuk menyimpan data dalam sebuah array agar penyimpanan data,
pencarian data, penambahan data, dan penghapusan data dapat dilakukan dengan cepat. Ide dasarnya adalah menghitung posisi record yang dicari dalam array, bukan membandingkan record dengan isi pada array. Fungsi
yang mengembalikan nilai atau kunci disebut fungsi hash (hash function) dan array yang digunakan disebut tabel hash (hash table). Secara teori, kompleksitas waktu (T(n)) dari fungsi hash yang ideal adalah O(1). Untuk mencapai itu setiap record membutuhkan suatu kunci yang unik. 

## Unguided 

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
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
```
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/4e74b141-f062-4d9d-b668-247e88a2d185)
Program yang Anda berikan adalah program sederhana untuk menghitung faktorial dari sebuah bilangan bulat positif menggunakan fungsi rekursif.

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 di atas!

```C++
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
```
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/8a93e770-a37f-48bf-87c3-65b6b7b79a03)

Program ini adalah implementasi dari dua fungsi faktorial factorialA dan factorialB yang saling memanggil secara rekursif tidak langsung. 

### 3. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
a. Setiap mahasiswa memiliki NIM dan nilai.
b. Program memiliki tampilan pilihan menu berisi poin C.
c. Implementasikan fungsi untuk menambahkan data baru, menghapus data,
mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai
(80 – 90).

```C++
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Struct data untuk menyimpan informasi 
struct Mahasiswa {
    string NIM;
    int nilai;
};

// Hash table untuk menyimpan data 
unordered_map<string, Mahasiswa> hashTable;

// Fungsi menambahkan data 
void tambahMahasiswa(const string& NIM, int nilai) {
    Mahasiswa mhs = {NIM, nilai};
    hashTable[NIM] = mhs;
    cout << "Mahasiswa dengan NIM " << NIM << " dan nilai " << nilai << " berhasil ditambahkan." << endl;
}

// Fungsi menghapus berdasarkan NIM
void hapusMahasiswa(const string& NIM) {
    if (hashTable.erase(NIM)) {
        cout << "Mahasiswa dengan NIM " << NIM << " berhasil dihapus." << endl;
    } else {
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }
}

// Fungsi mencari berdasarkan NIM
void cariMahasiswaNIM(const string& NIM) {
    auto it = hashTable.find(NIM);
    if (it != hashTable.end()) {
        cout << "Mahasiswa ditemukan: NIM = " << it->second.NIM << ", Nilai = " << it->second.nilai << endl;
    } else {
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }
}

// Fungsi mencari data berdasarkan nilai
void cariMahasiswaRentangNilai(int minNilai, int maxNilai) {
    vector<Mahasiswa> hasil;
    for (const auto& pair : hashTable) {
        if (pair.second.nilai >= minNilai && pair.second.nilai <= maxNilai) {
            hasil.push_back(pair.second);
        }
    }
    if (!hasil.empty()) {
        cout << "Mahasiswa dengan nilai antara " << minNilai << " dan " << maxNilai << " ditemukan:" << endl;
        for (const auto& mhs : hasil) {
            cout << "NIM = " << mhs.NIM << ", Nilai = " << mhs.nilai << endl;
        }
    } else {
        cout << "Tidak ada mahasiswa dengan nilai antara " << minNilai << " dan " << maxNilai << "." << endl;
    }
}

// Fungsi tampilkan menu
void tampilkanMenu() {
    cout << "\nMenu:\n";
    cout << "1. Tambah data mahasiswa\n";
    cout << "2. Hapus data mahasiswa\n";
    cout << "3. Cari data mahasiswa berdasarkan NIM\n";
    cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80 - 90)\n";
    cout << "5. Keluar\n";
}

int main() {
    int pilihan;
    do {
        tampilkanMenu();
        cout << "Pilih opsi: ";
        cin >> pilihan;

        string NIM;
        int nilai;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahMahasiswa(NIM, nilai);
                break;

            case 2:
                cout << "NIM yang akan dihapus: ";
                cin >> NIM;
                hapusMahasiswa(NIM);
                break;

            case 3:
                cout << "NIM yang dicari: ";
                cin >> NIM;
                cariMahasiswaNIM(NIM);
                break;

            case 4:
                cariMahasiswaRentangNilai(80, 90);
                break;

            case 5:
                cout << "Keluar dari program.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}
```
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/4157fbfa-6bd8-4e70-b149-53c375fdc6f7)
Program ini adalah sebuah aplikasi sederhana untuk mengelola data mahasiswa untuk menyimpan data mahasiswa berdasarkan NIM.

## Referensi
[1]. Fenina Adline Twince Tobing, Prayogo, Alex Chandra (2022). Analisis Perbandingan Fibonacci dengan Iterasi dan Rekursi Terhadap Efektifitas Waktu. Vol 01, No 02:halaman 188-195

[2]. Puthut Prabancono (2008). Penerapan Algoritma Runut-balik dalam Fungsi Hash


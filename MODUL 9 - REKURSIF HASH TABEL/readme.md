# <h1 align="center">Laporan Praktikum Modul Rekursif & Hash Tabel</h1>
<p align="center">Zahra Adya Nindita (2311110027)</p>

## Dasar Teori

1. Rekursif
Rekursif adalah sebuah teknik di pemrograman, di mana sebuah fungsi memanggil dirinya sendiri. Mirip dengan loop (pengulangan), yang kedua tujuannya memanggil aksi yang sama berkali-kali.
Namun rekursi sering digunakan untuk menyelesaikan masalah yang lebih kompleks:
- yang tidak bisa (sulit) diselesaikan dengan loop biasa
- kode implementasinya akan sangat sulit dibaca jika menggunakan loop (iterasi)
2. Hash Tabel
Hash table merupakan struktur data yang secara asosiatif menyimpan data. Dalam hal ini, data disimpan dalam format array, di mana setiap nilai data memiliki nilai indeks uniknya sendiri. Akses data akan menjadi sangat cepat jika Anda mengetahui indeks dari data yang diinginkan. 
Fungsi utamanya pada data adalah mempercepat proses akses data. Hal ini berkaitan dengan peningkatan data dalam jumlah besar yang diproses oleh jaringan data global dan lokal. Hash table adalah solusi untuk membuat proses akses data lebih cepat dan memastikan bahwa data dapat dipertukarkan dengan aman. 
Di dalam banyak bidang, hash table dikembangkan dan digunakan karena menawarkan kelebihan dalam efisiensi waktu operasi, mulai dari pengarsipan hingga pencarian data. Contohnya adalah bidang jaringan komputer yang mengembangkannya menjadi hybrid open hash table, yang kemudian dipakai untuk memproses jaringan komputer.

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

## Referensi
[1] (https://algorit.ma/blog/hash-table-adalah-2022/)
[2] (https://sko.dev/wiki/rekursif)


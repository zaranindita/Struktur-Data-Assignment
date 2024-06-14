# <h1 align="center">Laporan Praktikum Modul Stack dan Queue</h1>
<p align="center">Zahra Adya Nindita (2311110027)</p>

## Dasar Teori

Pada pemrograman struktur data, stack dan queue adalah dua jenis struktur data non primitif
bertipe data abstrak yang digunakan untuk menyimpan elemen data baik di array maupun di linked
list yang sebenarnya didasarkan pada beberapa kejadian di kehidupan nyata. Stack menggunakan
metode LIFO (last in first out) untuk mengakses dan menambahkan elemen data sedangkan queue
menggunakan metode FIFO (First in first out) untuk mengakses dan menamhkan elemen data. 

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya
```C++
#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

// Fungsi hapus karakter tdk alfabet 
string preprocessString(const string& str) {
    string result;
    for (char c : str) {
        if (isalpha(c)) {
            result += tolower(c);
        }
    }
    return result;
}

// Fungsi cek palindrom
bool isPalindrome(const string& str) {
    stack<char> s;
    string processedStr = preprocessString(str);

    // Memasukkan karakter 
    for (char c : processedStr) {
        s.push(c);
    }

    // Membandingkan karakter 
    for (char c : processedStr) {
        if (c != s.top()) {
            return false;
        }
        s.pop();
    }

    return true;
}

int main() {
    string kalimat;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
```
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/01816604-9b06-45fa-91a4-04d7e6632c20)

Berikut adalah contoh program  yang menggunakan stack untuk menentukan apakah sebuah kalimat merupakan palindrom atau tidak dan tidak membedakan huruf besar dan kecil. 

### 2. Ubah guided queue diatas agar menjadi program inputan user dan program menu
```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maks antrian
int front = 0; 
int back = 0; 
string queueTeller[maksimalQueue]; 

bool isFull() { 
    if (back == maksimalQueue) {
        return true; 
    } else {
        return false;
    }
}

bool isEmpty() { 
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { 
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { 
            queueTeller[0] = data;
            front++;
            back++;
        } else { 
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { 
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[back - 1] = "";
        back--;
    }
}

int countQueue() { 
    return back;
}

void clearQueue() { 
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { 
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
int main() {
    char pilihan;
    string nama;
    do {
        cout << "\nMenu Antrian Teller" << endl;
        cout << "1. Tambah Data Antrian" << endl;
        cout << "2. Hapus Data Antrian" << endl;
        cout << "3. Lihat Data Antrian" << endl;
        cout << "4. Hitung Jumlah Antrian" << endl;
        cout << "5. Hapus Seluruh Data Antrian" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih operasi (1-6): ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
            case '1':
                cout << "Masukkan nama: ";
                getline(cin, nama);
                enqueueAntrian(nama);
                break;
            case '2':
                dequeueAntrian();
                break;
            case '3':
                viewQueue();
                break;
            case '4':
                cout << "Jumlah antrian = " << countQueue() << endl;
                break;
            case '5':
                clearQueue();
                break;
            case '6':
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != '6');

    return 0;
}
```
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/8eb62ff7-6e70-4e5b-abf7-c11c8f7b3327)
Program yang telah diubah untuk menerima input dari user dan menampilkan menu untuk mengelola antrian

## Referensi
[1] Johnson Sihombing. PENERAPAN STACK DAN QUEUE PADA ARRAY DAN LINKED LIST DALAM JAVA 



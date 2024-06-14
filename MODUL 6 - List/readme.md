# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Zahra Adya Nindita (2311110027)</p>

## Dasar Teori
Linked List merupakan salah satu metode dalam Algoritma dan Struktur Data yang digunakan untuk mengorganisasi struktur data dalam sebuah sistem. Linked List memiliki keunggulan dibandingkan Array dalam hal menambahkan dan mengurangi elemennya (Ryan, 2008).

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
a.	Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.
[Nama_anda]	[Usia_anda]
John	19
Jane	20
Michael	18
Yusuke	19
Akechi	20
Hoshino	18
Karin	18
b.	Hapus data Akechi
c.	Tambahkan data berikut diantara John dan Jane : Futaba	18
d.	Tambahkan data berikut diawal : Igor	20
e.	Ubah data Michael menjadi : Reyn	18
f.	Tampilkan seluruh data

```C++
#include <iostream>
using namespace std;

class Node {
public:
    string nama;
    int usia;
    Node* next;

    Node(string nama, int usia) {
        this->nama = nama;
        this->usia = usia;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void tambahDepan(string nama, int usia) {
        Node* newNode = new Node(nama, usia);
        newNode->next = head;
        head = newNode;
    }

    void tambahBelakang(string nama, int usia) {
        Node* newNode = new Node(nama, usia);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void tambahSetelah(string namaPrev, string nama, int usia) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != namaPrev) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node dengan nama " << namaPrev << " tidak ditemukan" << endl;
            return;
        }
        Node* newNode = new Node(nama, usia);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void hapus(string nama) {
        Node* temp = head;
        Node* prev = nullptr;
        if (temp != nullptr && temp->nama == nama) {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->nama != nama) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node dengan nama " << nama << " tidak ditemukan" << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    void ubahData(string namaLama, string namaBaru, int usiaBaru) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->nama == namaLama) {
                temp->nama = namaBaru;
                temp->usia = usiaBaru;
                return;
            }
            temp = temp->next;
        }
        cout << "Node dengan nama " << namaLama << " tidak ditemukan" << endl;
    }

    void tampilkanData() {
        Node* temp = head;
        cout << "Nama\t\tUsia" << endl;
        while (temp != nullptr) {
            cout << temp->nama << "\t\t" << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList linkedList;
    char pilihan;
    string nama, namaPrev;
    int usia, usiaBaru;

    do {
        cout << "Menu:" << endl;
        cout << "a. Masukkan data" << endl;
        cout << "b. Hapus data" << endl;
        cout << "c. Tambahkan data di antara" << endl;
        cout << "d. Ubah data" << endl;
        cout << "e. Tampilkan data" << endl;
        cout << "f. Keluar" << endl;
        cout << "Pilih operasi (a/b/c/d/e/f): ";
        cin >> pilihan;

        switch (pilihan) {
            case 'a':
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan usia: ";
                cin >> usia;
                linkedList.tambahBelakang(nama, usia);
                break;
            case 'b':
                cout << "Masukkan nama yang ingin dihapus: ";
                cin >> nama;
                linkedList.hapus(nama);
                break;
            case 'c':
                cout << "Masukkan nama setelah yang baru akan ditambahkan: ";
                cin >> namaPrev;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan usia: ";
                cin >> usia;
                linkedList.tambahSetelah(namaPrev, nama, usia);
                break;
            case 'd':
                cout << "Masukkan nama yang akan diubah: ";
                cin >> nama;
                cout << "Masukkan nama baru: ";
                cin >> namaPrev;
                cout << "Masukkan usia baru: ";
                cin >> usiaBaru;
                linkedList.ubahData(nama, namaPrev, usiaBaru);
                break;
            case 'e':
                linkedList.tampilkanData();
                break;
            case 'f':
                cout << "Keluar" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 'f');

    return 0;
}
```
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/250cd3a6-f39e-4e17-b983-519390992b7d)

Program implemetasi struktur data linked list untuk menyimpan dan mengelola data berupa
nama dan umur dan menyediakan beberapa operasi dasar pada linked list seperti menambah
data, menghapus data, menambah data di antara node, mengubah data, dan menampilkan
data.

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
Nama Produk	Harga
Originote	60.000
Somethinc	150.000
Skintific	100.000
Wardah	50.000
Hanasui	30.000

Case:
1.	Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
2.	Hapus produk wardah
3.	Update produk Hanasui menjadi Cleora dengan harga 55.000
4.	Tampilkan menu seperti dibawah ini
Toko Skincare Purwokerto
1.	Tambah Data
2.	Hapus Data
3.	Update Data
4.	Tambah Data Urutan Tertentu
5.	Hapus Data Urutan Tertentu
6.	Hapus Seluruh Data
7.	Tampilkan Data
8.	Exit
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :

Nama Produk	Harga
Originote	60.000
Somethinc	150.000
Azarine	65.000
Skintific	100.000
Cleora	55.000

```C++
#include <iostream>
using namespace std;

class Node {
public:
    string nama_produk;
    int harga;
    Node* prev;
    Node* next;

    Node(string nama_produk, int harga) {
        this->nama_produk = nama_produk;
        this->harga = harga;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void tambahBelakang(string nama_produk, int harga) {
        Node* newNode = new Node(nama_produk, harga);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void tambahSetelah(string nama_produk_prev, string nama_produk, int harga) {
        Node* temp = head;
        while (temp != nullptr && temp->nama_produk != nama_produk_prev) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Produk dengan nama " << nama_produk_prev << " tidak ditemukan" << endl;
            return;
        }
        Node* newNode = new Node(nama_produk, harga);
        newNode->prev = temp;
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        if (temp == tail) {
            tail = newNode;
        }
    }

    void hapus(string nama_produk) {
        Node* temp = head;
        while (temp != nullptr && temp->nama_produk != nama_produk) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Produk dengan nama " << nama_produk << " tidak ditemukan" << endl;
            return;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }
        delete temp;
    }

    void update(string nama_produk, string nama_produk_baru, int harga_baru) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->nama_produk == nama_produk) {
                temp->nama_produk = nama_produk_baru;
                temp->harga = harga_baru;
                return;
            }
            temp = temp->next;
        }
        cout << "Produk dengan nama " << nama_produk << " tidak ditemukan" << endl;
    }

    void tampilkanData() {
        cout << "Nama Produk\tHarga" << endl;
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama_produk << "\t\t" << temp->harga << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DoubleLinkedList dll;

    // Menambahkan data awal
    dll.tambahBelakang("Originote", 60000);
    dll.tambahBelakang("Somethinc", 150000);
    dll.tambahBelakang("Skintific", 100000);
    dll.tambahBelakang("Wardah", 50000);
    dll.tambahBelakang("Hanasui", 30000);

    char pilihan;
    string nama_produk, nama_produk_prev;
    int harga, harga_baru;

    do {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih operasi (1-8): ";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                cout << "Masukkan nama produk: ";
                cin >> nama_produk;
                cout << "Masukkan harga: ";
                cin >> harga;
                dll.tambahBelakang(nama_produk, harga);
                break;
            case '2':
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama_produk;
                dll.hapus(nama_produk);
                break;
            case '3':
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> nama_produk;
                cout << "Masukkan nama produk baru: ";
                cin >> nama_produk_prev;
                cout << "Masukkan harga baru: ";
                cin >> harga_baru;
                dll.update(nama_produk, nama_produk_prev, harga_baru);
                break;
            case '4':
                cout << "Masukkan nama produk setelah yang baru akan ditambahkan: ";
                cin >> nama_produk_prev;
                cout << "Masukkan nama produk: ";
                cin >> nama_produk;
                cout << "Masukkan harga: ";
                cin >> harga;
                dll.tambahSetelah(nama_produk_prev, nama_produk, harga);
                break;
            case '5':
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama_produk;
                dll.hapus(nama_produk);
                break;
            case '6':
                // Hapus seluruh data
                dll = DoubleLinkedList();
                break;
            case '7':
                // Tampilkan data
                dll.tampilkanData();
                break;
            case '8':
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != '8');

    return 0;
}
```
# Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/b0be0867-6e94-46e8-b189-f333b223b121)

Program di atas adalah program yang mengelola daftar produk skincare menggunakan struktur data linked list ganda (doubly linked list). Program ini menyediakan berbagai operasi untuk menambahkan, menghapus, mengupdate, dan menampilkan data produk.

## Referensi
[1] Hermawan Wijaya, Wibisono Sukmo Wardhono, Issa Arwani (2018). Implementasi Linked List pada Interaksi Antar Marker Augmented Reality untuk Operand dan Operator Aritmetika. Vol. 2, No. 9. hlm. 3328-3332



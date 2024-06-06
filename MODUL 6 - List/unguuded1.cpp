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

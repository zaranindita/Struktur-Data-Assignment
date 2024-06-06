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

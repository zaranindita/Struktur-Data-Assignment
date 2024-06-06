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

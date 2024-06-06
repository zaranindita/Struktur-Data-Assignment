#include <iostream>
using namespace std;

// Struct tree
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

// Deklarasi variabel 
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* alamat[256];
int nim_2311110027[256]; 

// Fungsi inisialisasi root
void inisialisasi() {
    root = NULL;
}

// Fungsi membuat simpul baru
void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

// Fungsi membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Masukkan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk." << endl;
    } else {
        cout << "Root sudah tersedia." << endl;
    }
}

// Fungsi tambah simpul
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;
        while (penanda == 0 && j < 256) {
            cout << "Masukkan data kiri (Masukkan '0' jika selesai): ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan (Masukkan '0' jika selesai): ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

// Fungsi membaca tree
void bacaPohon() {
    if (root != NULL) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != NULL) {
            saatIni = alamat[i];
            cout << saatIni->data << " ";
            pencacah++;
            if (pencacah == n) {
                cout << endl;
                pencacah = 0;
                n = n * 2;
            }
            i++;
        }
    }
}

// Preorder
void preorder(pohon* node) {
    if (node != NULL) {
        cout << node->data << " ";
        preorder(node->kiri);
        preorder(node->kanan);
    }
}

// Inorder 
void inorder(pohon* node) {
    if (node != NULL) {
        inorder(node->kiri);
        cout << node->data << " ";
        inorder(node->kanan);
    }
}

// Postorder 
void postorder(pohon* node) {
    if (node != NULL) {
        postorder(node->kiri);
        postorder(node->kanan);
        cout << node->data << " ";
    }
}

// Fungsi utama
int main() {
    int pilihan;
    inisialisasi();

    do {
        cout << "\nMenu:\n";
        cout << "1. Buat simpul akar\n";
        cout << "2. Tambah simpul\n";
        cout << "3. Tampilkan tree\n";
        cout << "4. Preorder\n";
        cout << "5. Inorder\n";
        cout << "6. Postorder\n";
        cout << "7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                simpulAkar();
                break;
            case 2:
                tambahSimpul();
                break;
            case 3:
                bacaPohon();
                break;
            case 4:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;
            case 7:
                cout << "Keluar\n";
                break;
            default:
                cout << "Pilihan tidak ada.\n";
        }
    } while (pilihan != 7);

    return 0;
}

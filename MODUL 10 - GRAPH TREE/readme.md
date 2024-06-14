# <h1 align="center">Laporan Praktikum Modul Graph Tree</h1>
<p align="center">Zahra Adya Nindita (2311110027)</p>

## Dasar Teori
1. Graph
Graph merupakan struktur data linear yangdapat didefinisikan sebagai himpunan atauketerhubungan tak terbatas antara verteks (entitasdata). Graph juga dapat didefinisikan dengan struktur yang elemennya memiliki hubungan
many to many. Suatu graph mengandung dua himpunanyaitu himpunan V dan himpunan E. Himpunan Vmerupakan himpunan verteks dan E himpunanyang terdefinisi antara pasangan verteks.Banyaknya verteks disebut dengan order dan banyaknya edge (ruas) dikenal dengan size darigraph. Suatu graph yang tidak memiliki self-loopdapat juga disebut sebagai graph sederhana atausimple graph.

2. Tree
Pohon (tree) adalah sebuah struktur data yang terdiri dari simpul (node) dan rusuk (edge). Simpul pada sebuah
pohon dibedakan menjadi tiga, yaitu simpul akar (root/node), simpul percabangan/internal (branch/internal
node) dan simpul daun (leaf node)

## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.


```C++
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Masukan jumlah simpul: ";
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    vector<vector<int>> weights(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << nodes[i] << "--> " << nodes[j] << " = ";
            cin >> weights[i][j];
        }
    }

    // Matriks
    cout << setw(10) << " ";
    for (const string& node : nodes) {
        cout << setw(10) << node;
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << setw(10) << nodes[i];
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << weights[i][j];
        }
        cout << endl;
    }

    return 0;
}

```
## Output
![alt text](image.png)
Program ini adalah untuk membuat representasi graf berbobot menggunakan matriks berbobot.

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan tampilkan pada pre-order, inorder, dan post order!


```C++
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

```
## Output
![alt text](image-1.png)
Program ini adalah implementasi dari struktur data pohon biner

## Referensi
[1] Rizky agung saragiih, Surya Habibi Syahrozi, Indra Gunawan. Data dan Struktur Data
[2]. Asmaul Husnah Nasrullah (2021). IMPLEMENTASI ALGORITMA DECISION TREE UNTUK KLASIFIKASI PRODUK LARIS 

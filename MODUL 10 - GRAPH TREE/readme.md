# <h1 align="center">Laporan Praktikum Modul Graph Tree</h1>
<p align="center">Zahra Adya Nindita (2311110027)</p>

## Dasar Teori

1. Graph
Graph adalah jenis struktur data umum yang susunan datanya tidak berdekatan satu sama lain (non-linier). Graph terdiri dari kumpulan simpul berhingga untuk menyimpan data dan antara dua buah simpul terdapat hubungan saling keterkaitan.Graph banyak dimanfaatkan untuk menyelesaikan masalah dalam kehidupan nyata, dimana masalah tersebut perlu direpresentasikan atau diimajinasikan seperti sebuah jaringan. Contohnya adalah jejaring sosial (seperti Facebook, Instagram, LinkedIn)
Jenis-jenis graph:
1. Undirected Graph
Pada undirected graph, simpul-simpulnya terhubung dengan edge yang sifatnya dua arah. Misalnya kita punya simpul 1 dan 2 yang saling terhubung, kita bisa menjelajah dari simpul 1 ke simpul 2, begitu juga sebaliknya.
2. Directed Graph
Pada graph jenis ini simpul-simpulnya terhubung oleh edge yang hanya bisa melakukan jelajah satu arah pada simpul yang ditunjuk. Sebagai contoh jika ada simpul A yang terhubung ke simpul B, namun arah panahnya menuju simpul B, maka kita hanya bisa melakukan jelajah (traversing) dari simpul A ke simpul B, dan tidak berlaku sebaliknya.
3. Weighted Graph
Weighted graph adalah jenis graph yang cabangnya diberi label bobot berupa bilangan numerik. Pemberian label bobot pada edge biasanya digunakan untuk memudahkan algoritma dalam menyelesaikan masalah.
Implementasinya misalkan kita ingin menyelesaikan masalah dalam mencari rute terpendek dari lokasi A ke lokasi D, namun kita juga dituntut untuk mempertimbangkan kepadatan lalu lintas, panjang jalan dll. 
4. Unweighted Graph
Unweighted graph tidak memiliki properti bobot pada koneksinya. Graph ini hanya mempertimbangkan apakah dua node saling terhubung atau tidak

2. Tree
Dalam Struktur Data Konsep Tree mirip seperti pohon yaitu kumpulan node yang saling terhubung satu sama lain dalam suatu kesatuan yang membentuk layaknya struktur sebuah pohon. Struktur Tree adalah suatu cara merepresentasikan suatu struktur hirarki ( one — to many ) secara grafis yang mirip sebuah pohon, walaupun pohon tersebut hanya tampak sebagai kumpulan — node — node dari atas ke bawah. Konsep Tree Di seuah struktur data yang tidak linier yang menggambarkan hubungan yang hirarkis ( one to many ) dan tidak linier antara elemen — elemennya. Dalam Konsep Tree di sebuah Node ada namanya Node Root. Node Root dalam sebuah tree yang dimaksud adalah suatu node yang memiliki hirarki tertinggi dan dapat juga memiliki node — node anak atau yang disebut child node. jadi semua node yang dapat ditelurusan dari node root tersebut. Node Root dicirikan adalah suatu node khusus yang tercipta pertama kalinya. Sedangkan Node — Node lain dibawah node root saling terhubung satu sama lain disebut sebagai Subtree.

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

## Referensi
[1] (https://www.trivusi.web.id/2022/07/struktur-data-graph.html)
[2] (https://daismabali.medium.com/memahami-konsep-tree-dalam-struktur-data-lengkap-dengan-source-code-programnya-acbd0a8733d6)


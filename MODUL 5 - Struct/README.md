# <h1 align="center">Laporan Praktikum Modul STRUCT</h1>
<p align="center">Zahra Adya Nindita (2311110027)</p>

## Dasar Teori
Struct adalah cara penyimpanan, pengorganisasian, dan pengaturan
data di dalam media penyimpanan komputer sehingga data tersebut dapat
digunakan secara efisien.Sedangkan data adalah representasi dari fakta dunia
nyata. Fakta atau keterangan tentang kenyataan yang disimpan, direkam atau
direpresentasikan dalam bentuk tulisan, suara, gambar, sinyal atau simbol. 

## Unguided 

### 1.  Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada
struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan

```C++
#include <iostream>
#include <string>
using namespace std;

struct buku {
    string judulbuku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_buku[5];
    double harga_buku[5];
};

int main(){
    buku buku1, buku2;

    // Mengisi data untuk buku1
    buku1.pengarang[0] = "JK Rowling";
    buku1.judulbuku[0] = "Harry Potter";
    buku1.penerbit[0] = "Gramedia";
    buku1.tebal_buku[0] = 400;
    buku1.harga_buku[0] = 100000;

    // Mengisi data untuk buku2
    buku2.pengarang[0] = "Tere Liye";
    buku2.judulbuku[0] = "Hujan";
    buku2.penerbit[0] = "Gramedia";
    buku2.tebal_buku[0] = 200;
    buku2.harga_buku[0] = 100000;

    // Menampilkan informasi buku1
    cout << "Informasi buku 1" << endl;
    cout << "Pengarang: " << buku1.pengarang[0] << endl;
    cout << "Judul buku: " << buku1.judulbuku[0] << endl;
    cout << "Penerbit: " << buku1.penerbit[0] << endl;
    cout << "Tebal buku: " << buku1.tebal_buku[0] << endl;
    cout << "Harga buku: " << buku1.harga_buku[0] << endl;

    // Menampilkan informasi buku2
    cout << "\nInformasi buku 2" << endl;
    cout << "Pengarang: " << buku2.pengarang[0] << endl;
    cout << "Judul buku: " << buku2.judulbuku[0] << endl;
    cout << "Penerbit: " << buku2.penerbit[0] << endl;
    cout << "Tebal buku: " << buku2.tebal_buku[0] << endl;
    cout << "Harga buku: " << buku2.harga_buku[0] << endl;

    return 0;
}
```


### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I,
berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?

```C++
#include <iostream>
#include <string>
using namespace std;

// struct buku
struct buku {
    string judulbuku;
    string pengarang;
    string penerbit;
    int tebal_buku;
    double harga_buku;
};

int main() {
    const int jumlah_buku = 2;
    buku daftar_buku[jumlah_buku];

    // mengisi data dalam array
    for (int i = 0; i < jumlah_buku; ++i) {
        cout << "Masukkan informasi untuk buku ke-" << i + 1 << ":" << endl;
        cout << "Judul buku: ";
        getline(cin, daftar_buku[i].judulbuku);
        cout << "Pengarang: ";
        getline(cin, daftar_buku[i].pengarang);
        cout << "Penerbit: ";
        getline(cin, daftar_buku[i].penerbit);
        cout << "Tebal buku: ";
        cin >> daftar_buku[i].tebal_buku;
        cout << "Harga buku: ";
        cin >> daftar_buku[i].harga_buku;

        cin.ignore();
    }

    // menampilkan informasi 
    cout << "\nInformasi buku:\n";
    for (int i = 0; i < jumlah_buku; ++i) {
        cout << "\nBuku ke-" << i + 1 << ":\n";
        cout << "Judul: " << daftar_buku[i].judulbuku << endl;
        cout << "Pengarang: " << daftar_buku[i].pengarang << endl;
        cout << "Penerbit: " << daftar_buku[i].penerbit << endl;
        cout << "Tebal: " << daftar_buku[i].tebal_buku << " halaman" << endl;
        cout << "Harga: " << daftar_buku[i].harga_buku << " IDR" << endl;
    }

    return 0;
}
```
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/f548dedb-3cf3-4cc5-a3a7-5acfd1b6bf3b)

Program di atas adalah program mendefinisikan struktur untuk menyimpan informasi buku, mengisi data buku melalui input pengguna, dan kemudian menampilkan informasi tersebut

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?

```C++
#include <iostream>
#include <string>
using namespace std;

// struct buku
struct buku {
    string judulbuku;
    string pengarang;
    string penerbit;
    int tebal_buku;
    double harga_buku;
};

int main() {
    const int jumlah_buku = 2;
    buku daftar_buku[jumlah_buku];

    // mengisi data dalam array
    for (int i = 0; i < jumlah_buku; ++i) {
        cout << "Masukkan informasi untuk buku ke-" << i + 1 << ":" << endl;
        cout << "Judul buku: ";
        getline(cin, daftar_buku[i].judulbuku);
        cout << "Pengarang: ";
        getline(cin, daftar_buku[i].pengarang);
        cout << "Penerbit: ";
        getline(cin, daftar_buku[i].penerbit);
        cout << "Tebal buku: ";
        cin >> daftar_buku[i].tebal_buku;
        cout << "Harga buku: ";
        cin >> daftar_buku[i].harga_buku;

        cin.ignore();
    }

    // menampilkan informasi 
    cout << "\nInformasi buku:\n";
    for (int i = 0; i < jumlah_buku; ++i) {
        cout << "\nBuku ke-" << i + 1 << ":\n";
        cout << "Judul: " << daftar_buku[i].judulbuku << endl;
        cout << "Pengarang: " << daftar_buku[i].pengarang << endl;
        cout << "Penerbit: " << daftar_buku[i].penerbit << endl;
        cout << "Tebal: " << daftar_buku[i].tebal_buku << " halaman" << endl;
        cout << "Harga: " << daftar_buku[i].harga_buku << " IDR" << endl;
    }

    return 0;
}
```
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/4a2b80a8-4306-40c8-9c14-a21e294aaf89)

Program di atas adalah program mendefinisikan struktur untuk menyimpan informasi buku, mengisi data buku melalui input pengguna, dan kemudian menampilkan informasi tersebut dalam bentuk array

## Referensi
[1].Triase (2020). Diktat Edisi Revisi STRUKTUR DATA






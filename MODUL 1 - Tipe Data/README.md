# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Zahra Adya Nindita (2311110027)</p>

## Dasar Teori

1. Tipe Data Primitif
Tipe data primitif digunakan untuk representasi data sederhana dalam program.
Penggunaan tipe data primitif yang sesuai memungkinkan program untuk mengolah data dengan efisien dan tepat sesuai kebutuhan aplikasi.
Tipe data primitif di bahasa pemrograman C++ adalah tipe data yang sudah terdefinisi secara bawaan dalam bahasa pemrograman tersebut. Tipe data primitif biasanya digunakan untuk menyimpan nilai yang sederhana dan tidak kompleks seperti bilangan bulat, bilangan pecahan, karakter, dan nilai boolean.
2. Class dan Struct
Class: Konsep kelas merupakan hal mendasar dalam C++, karena kelas menyediakan cara untuk mendefinisikan tipe baru yang ditentukan pengguna, lengkap dengan fungsi dan operator terkait. Dengan membatasi akses ke anggota kelas tertentu, dimungkinkan untuk memisahkan properti yang penting untuk penggunaan kelas yang benar dari rincian yang diperlukan untuk implementasinya. Kelas merupakan hal mendasar dalam pemrograman yang menggunakan pendekatan berorientasi objek.
Struct: Struktur (disebut juga struct) adalah cara mengelompokkan beberapa variabel terkait ke dalam satu tempat. Setiap variabel dalam struktur dikenal sebagai anggota struktur. Berbeda dengan array, struktur dapat berisi banyak tipe data berbeda (int, string, bool, dll.).
3. Perbedaan Array dan Map
Array adalah suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Elemen-elemen array tersusun secara sekuensial dalam memori komputer. Semua elemen array bertipe sama. Array cocok untuk organisasi kumpulan data homogen yang ukuran atau jumlah elemen maksimumnya telah diketahui dari awal. 
Map adalah struktur data terurut yang menyimpan data dalam bentuk terurut sehingga elemen dapat dengan mudah dicari dalam struktur data. Map adalah wadah yang menyimpan pasangan data. Pasangan ini, yang dikenal sebagai pasangan kunci-nilai, memiliki kunci unik, sedangkan nilai terkait tidak harus unik. Elemen dalam peta diurutkan secara internal berdasarkan kuncinya.



## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
#include <iostream>

using namespace std;

// Fungsi  hitung luas segitiga
float hitungLuasSegitiga(float alas, float tinggi) {
    return 0.5 * alas * tinggi;
}

// Fungsi  hitung luas persegi
float hitungLuasPersegi(float sisi) {
    return sisi * sisi;
}

int main() {
    float alasSegitiga, tinggiSegitiga, sisiPersegi;

    // Input alas dan tinggi segitiga
    cout << "Masukkan alas segitiga: ";
    cin >> alasSegitiga;
    cout << "Masukkan tinggi segitiga: ";
    cin >> tinggiSegitiga;

    // Hitung dan tampilkan luas segitiga
    cout << "Luas segitiga adalah: " << hitungLuasSegitiga(alasSegitiga, tinggiSegitiga) << endl;

    // Input sisi persegi
    cout << "Masukkan sisi persegi: ";
    cin >> sisiPersegi;

    // Hitung dan tampilkan luas persegi
    cout << "Luas persegi adalah: " << hitungLuasPersegi(sisiPersegi) << endl;

    return 0;
}
```
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/9042e7a4-dd37-461e-ac4f-51ac5bb57c6e)

Kode di atas digunakan untuk mencaqri luas persegi dan luas segitiga.

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya]

```C++
#include <iostream>
#include <string>
using namespace std;

// struct eskrim
struct Es_krim {
    string rasa;
    string merek;
    float harga;
};

// class harga eskrim
class hargaeskrim {
public:
    
    hargaeskrim(string _rasa, string _merek, float _harga) {
        eskrim.rasa = _rasa;
        eskrim.merek = _merek;
        eskrim.harga = _harga;
    }

    // Fungsi menampilkan harga 
    void tampilkan() {
        cout << "Rasa: " << eskrim.rasa << endl;
        cout << "Merek: " << eskrim.merek << endl;
        cout << "Harga: Rp" << eskrim.harga << endl;
    }

private:
    Es_krim eskrim; // Objek eskrim dalam class harga 
};

int main() {
    // Membuat objek eskrim menggunakan class harga 
    hargaeskrim es_krim1("Oreo", "Cornetto", 6000);
    hargaeskrim es_krim2("Chocolate Almond", "Magnum", 14000);
    hargaeskrim es_krim3("Durian","Aice",3000);
    hargaeskrim es_krim4("Chocolate","Campina",7000);
    hargaeskrim es_krim5("Tiramisu","Haku",8000);

    // Menampilkan harga eskrim
    cout << "Es Krim 1:" << endl;
    es_krim1.tampilkan();

    cout << "\nEs Krim 2:" << endl;
    es_krim2.tampilkan();
    
    cout << "\nEs Krim 3:" << endl;
    es_krim3.tampilkan();

    cout << "\nEs Krim 4:" << endl;
    es_krim4.tampilkan();

    cout << "\nEs Krim 5:" << endl;
    es_krim5.tampilkan();


    return 0;
}
```
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/605208f0-312a-4494-904d-7cb3d5a1141c)

Kode di atas digunakan untuk menyimpan dan menampilkan informasi harga eskrim.

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dariarray dengan map.]

```C++
#include <iostream>
#include <map>
#include <string>
using namespace std;

// Struct untuk menyimpan informasi 
struct DataNama{
    int usia;
    string gender;
    string pekerjaan;
};

// Fungsi menampilkan map
void Map(const map<string, DataNama>& data) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        cout << "Nama: " << it->first << ", Usia: " << it->second.usia << ", Gender: " << it->second.gender << ", Pekerjaan: " << it->second.pekerjaan << endl;
    }
}

int main() {
    // Map untuk menyimpan informasi
    map<string, DataNama> dataNama;

    // Menambahkan data ke dalam map
    dataNama["Bella"] = {25, "Wanita", "Desainer"};
    dataNama["Nathan"] = {35, "Pria", "Dokter"};
    dataNama["Natasha"] = {40, "Wanita", "Direktur"};
    dataNama["Rafa"] = {24, "Pria", "Editor"};

    // Menampilkan data 
    cout << "Data :" << endl;
    Map(dataNama);

    // Mengubah data 
    dataNama["Nathan"].usia = 19;

    // Data setelah diubah
    cout << "\nPerubahan Data:" << endl;
    Map(dataNama);

    return 0;
}
```
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/1fb5db70-4ba8-4fa0-96cf-23d7cb0fa5af)
Kode di atas digunakan untuk menyimpan, mengubah, dan menampilkan data.


## Referensi
[1] Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). Data Structures and Algorithms in C++. Wiley.
Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++. 8.

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

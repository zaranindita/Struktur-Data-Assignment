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

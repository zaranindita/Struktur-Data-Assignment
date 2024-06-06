#include<iostream>
using namespace std;

struct hewan{
    string nama_hewan;
    string jenis_kelamin;
    string kembangbiak;
    string pernapasan;
    string tempat_hidup;
    bool karnivora;
};hewan info_hewan;

struct hewan_drt{
    int jumlah_kaki;
    bool apakah_menyusui;
    string suara;
    hewan info_hewan;
};
hewan_drt hewan1;

struct hewan_lt{
    string bentuk_sirip;
    string pertahanan_diri;
    hewan info_hewan;
};
hewan_lt hewan2;

int main() {
    //hewan 1
    hewan1.info_hewan.nama_hewan="bebek";
    hewan1.info_hewan.jenis_kelamin="J";
    hewan1.info_hewan.kembangbiak="telor";
    hewan1.info_hewan.pernapasan="paru";
    hewan1.info_hewan.tempat_hidup="tanah";
    hewan1.info_hewan.karnivora=false;
    hewan1.jumlah_kaki=2;
    hewan1.apakah_menyusui=false;
    hewan1.suara="wek wek";

    //hewan 2
    hewan2.info_hewan.nama_hewan="ikan";
    hewan2.info_hewan.jenis_kelamin="B";
    hewan2.info_hewan.nama_hewan="ikan";
}
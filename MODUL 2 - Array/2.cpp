#include <iostream>
#include <vector>

using namespace std;

int main() {
    int dim1, dim2, dim3;

    // Meminta pengguna untuk memasukkan ukuran array tiga dimensi
    cout << "Masukkan jumlah elemen untuk dimensi 1: ";
    cin >> dim1;
    cout << "Masukkan jumlah elemen untuk dimensi 2: ";
    cin >> dim2;
    cout << "Masukkan jumlah elemen untuk dimensi 3: ";
    cin >> dim3;

    // Membuat array tiga dimensi berdasarkan input pengguna
    vector<vector<vector<int>>> array3D(dim1, vector<vector<int>>(dim2, vector<int>(dim3)));

    // Meminta pengguna untuk memasukkan nilai setiap elemen array
    cout << "Masukkan nilai untuk setiap elemen array:" << endl;
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                cout << "Elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> array3D[i][j][k];
            }
        }
    }

    // Menampilkan array tiga dimensi
    cout << "Array tiga dimensi yang dimasukkan:" << endl;
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                cout << array3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

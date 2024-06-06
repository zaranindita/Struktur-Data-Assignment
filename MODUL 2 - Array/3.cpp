#include <iostream>
#include <limits>

using namespace std;

int main() {
    char choice;
    do {
        int n;
        cout << "Masukkan jumlah elemen dalam array: ";
        cin >> n;

        // membuat array
        int arr[n];

        // input elemen array
        cout << "Masukkan elemen-elemen array:\n";
        for (int i = 0; i < n; ++i) {
            cout << "Elemen ke-" << i + 1 << ": ";
            cin >> arr[i];
        }

        // mencari maksimum
        int max = INT_MIN; // Inisialisasi dengan nilai minimum yang mungkin
        for (int i = 0; i < n; ++i) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        // mencari minimum
        int min = INT_MAX; // Inisialisasi dengan nilai maksimum yang mungkin
        for (int i = 0; i < n; ++i) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        // hitung rata-rata
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
        }
        double average = static_cast<double>(sum) / n;

        // hasil
        cout << "Nilai maksimum: " << max << endl;
        cout << "Nilai minimum: " << min << endl;
        cout << "Nilai rata-rata: " << average << endl;

        // memilih apakah ingin memasukkan data array lagi
        cout << "Apakah Anda ingin memasukkan data array lagi? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

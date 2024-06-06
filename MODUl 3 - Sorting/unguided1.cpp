#include <iostream>

// Fungsi untuk mengurutkan dengan selection sort
void selectionSort(double arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int max_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        std::swap(arr[i], arr[max_index]);
    }
}

int main() {
    // IPS mhs
    double ips_MHS[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int n = sizeof(ips_MHS) / sizeof(ips_MHS[0]);

    // Mengurutkan 
    selectionSort(ips_MHS, n);

    // Output 
    std::cout << "IPS mahasiswa setelah diurutkan:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << ips_MHS[i] << "    ";
    }
    std::cout << std::endl;

    return 0;
}

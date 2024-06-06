#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menukar dua elemen dalam array
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk mengheapify sub-tree yang di-root oleh node i
void heapify(vector<int> &arr, int n, int i) {
    int smallest = i; // Inisialisasi smallest sebagai root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // Jika anak kiri lebih kecil dari root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // Jika anak kanan lebih kecil dari smallest
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // Jika smallest bukan root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Rekursif heapify sub-tree yang terpengaruh
        heapify(arr, n, smallest);
    }
}

// Fungsi untuk membangun heap dari array
void buildHeap(vector<int> &arr, int n) {
    // Indeks dari elemen non-leaf terakhir
    int startIdx = (n / 2) - 1;

    // Lakukan heapify dari sub-tree bawah ke atas
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Fungsi untuk mencetak array
void printArray(const vector<int> &arr) {
    for (int num : arr)
        cout << num << " ";
    cout << "\n";
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Jumlah elemen harus lebih besar dari nol.\n";
        return 1;
    }

    vector<int> arr(n);
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Array sebelum terurut: ";
    printArray(arr);

    // Membangun heap
    buildHeap(arr, n);

    cout << "Array setelah terurut: ";
    printArray(arr);

    return 0;
}
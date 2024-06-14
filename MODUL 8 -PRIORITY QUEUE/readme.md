# <h1 align="center">Laporan Praktikum Modul Priority Queue</h1>
<p align="center">Zahra Adya Nindita (2311110027)</p>

## Dasar Teori

1. Priority Queue
Priority Queue adalah struktur data khusus yang memungkinkan kita menyimpan elemen-elemen dengan nilai prioritas tertentu. Konsep dasar Priority Queue mirip dengan antrian biasa, namun perbedaannya adalah setiap elemen dalam Priority Queue memiliki nilai prioritas yang menentukan urutan elemen saat diambil.Pada dasarnya, Priority Queue dapat diimplementasikan dengan menggunakan struktur data dasar seperti heap atau binary search tree yang memungkinkan kita untuk melakukan operasi penyisipan (insert) dan penghapusan (delete) dalam waktu logaritmik. 

## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.
```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n;
    std::cout << "Masukkan jumlah elemen: ";
    std::cin >> n;

    std::cout << "Masukkan elemen-elemen: ";
    for (int i = 0; i < n; ++i) {
        int elemen;
        std::cin >> elemen;
        insert(elemen);
    }

    std::cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node dengan prioritas maksimum: " << extractMax() << "\n";
    std::cout << "Priority queue setelah maksimum dikeluarkan: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue setelah perubahan prioritas: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue setelah hapus elemen: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }

    return 0;
}
```
## Output
![image](https://github.com/zaranindita/Struktur-Data-Assignment/assets/160976449/0a799f63-e303-4a95-907c-c029024ec41f)
Program ini adalah implementasi dari struktur data antrian prioritas (priority queue) menggunakan heap maksimum (max heap) dengan array. 

## Referensi
[1]. Yoga Pradafa Harahap, Aditya Prapanca (2021). AnalisisAlgoritma Penjadwalan Priority Queueing (PQ) Terhadap Quality of Service (QoS) pada Jaringan Mobile WiMAXMenggunakan OPNET Modeler. Vol 03 No 02


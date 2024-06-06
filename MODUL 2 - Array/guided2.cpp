#include <iostream>
using namespace std;
 int main () {
    int maks,a,lokasi;
    cout << "masukkan panjang array:";
    cin >> a;
    
    if (a<=0) {
        cout << "panjang array haus lebih besar dari 0." << endl;
        return 1; // return 1
    }
    int array [a];
    cout << "masukkan" << a << "angka\n";

    for (int i=0;i<a;i++) {
        if (array[i]>maks) {
            maks = array[i];
            lokasi=i;
        }
    }
    cout << "nilai maksimum adalah" << maks << "berada di array ke" << (lokasi+1);
    return 0;
 }

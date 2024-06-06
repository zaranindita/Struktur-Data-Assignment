#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Masukan jumlah simpul: ";
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    vector<vector<int>> weights(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << nodes[i] << "--> " << nodes[j] << " = ";
            cin >> weights[i][j];
        }
    }

    // Matriks
    cout << setw(10) << " ";
    for (const string& node : nodes) {
        cout << setw(10) << node;
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << setw(10) << nodes[i];
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << weights[i][j];
        }
        cout << endl;
    }

    return 0;
}

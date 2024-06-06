#include <iostream>
#include <string>

using namespace std;

// Implementasi sederhana dari stack menggunakan array
class Stack {
private:
    char* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new char[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char c) {
        if (top == capacity - 1) {
            cout << "Stack penuh" << endl;
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack kosong" << endl;
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    char peek() {
        if (top == -1) {
            cout << "Stack kosong" << endl;
            return '\0';
        }
        return arr[top];
    }
};

// Fungsi untuk mengecek apakah suatu karakter adalah huruf atau angka
bool isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

bool isPalindrome(string sentence) {
    Stack charStack(sentence.length());

    string cleanSentence;

    // Mengonversi semua karakter ke lowercase dan menghapus karakter non-alphanumeric
    for (char c : sentence) {
        if (isAlphanumeric(c)) {
            cleanSentence += tolower(c);
        }
    }

    int halfLength = cleanSentence.length() / 2;

    // Memasukkan setengah karakter pertama ke dalam stack
    for (int i = 0; i < halfLength; i++) {
        charStack.push(cleanSentence[i]);
    }

    // Membandingkan setengah karakter kedua dengan karakter di stack
    for (int i = halfLength + cleanSentence.length() % 2; i < cleanSentence.length(); i++) {
        if (cleanSentence[i] != charStack.pop()) {
            return false;
        }
    }

    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}

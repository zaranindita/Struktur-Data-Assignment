#include <iostream>
using namespace std;

struct buku {
    string judulbuku;
    string pengarang;
    string penerbit;
    int tebal_buku;
    double harga_buku;

};buku buku1, buku2;

int main(){
    buku1.pengarang="JK Rowling";
    buku1.judulbuku="Harry Potter";
    buku1.penerbit="Gramedia";
    buku1.tebal_buku=400;
    buku1.harga_buku=100000;

    cout<<"Informasi buku"<<endl;
    cout << "\npengarang:"<<buku1.pengarang<<endl;
    cout << "\njudul buku:"<<buku1.judulbuku<<endl;
    cout << "\npenerbit:"<<buku1.penerbit<<endl;
    cout << "\ntebal buku"<<buku1.tebal_buku<<endl;
    cout << "\nharga buku:"<<buku1.harga_buku<<endl;

    buku2.pengarang="Tere Liye";
    buku2.judulbuku="Hujan";
    buku2.penerbit="Gramedia";
    buku2.tebal_buku=200;
    buku2.harga_buku=100000;


    cout<<"Informasi buku"<<endl;
    cout << "\npengarang:"<<buku2.pengarang<<endl;
    cout << "\njudul buku:"<<buku2.judulbuku<<endl;
    cout << "\npenerbit:"<<buku2.penerbit<<endl;
    cout << "\ntebal buku"<<buku2.tebal_buku<<endl;
    cout << "\nharga buku:"<<buku2.harga_buku<<endl;

    return 0;
}
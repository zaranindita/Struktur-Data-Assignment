#include <iostream> 
using namespace std;
//Main program
int main()
{
    char op;
    float num1,num2;
    cout<<"Masukkan Operator:";
    cin>>op;
    cout<<"\nMasukkan Bilangan Ke-1 dan ke-2:";
    cin>>num1>>num2;

    switch(op)
    {
    case '+':
        cout<<num1+num2;
        break;
    case '-':
        cout<<num1-num2;
    case '*':
        cout<<num1*num2;
    case '/':
        cout<<num1/num2;
    default:
        cout<<"Error! Operator is not correct";
    }
return 0;
}

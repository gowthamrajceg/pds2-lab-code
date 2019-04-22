#include<iostream>
using namespace std;
class Summa
{
public:
    string a;
    void get();
    void print();
    void print(string);
};
void Summa :: get()
{
    cout << "Enter your name :" << endl;
    getline(cin,a);
}
void Summa :: print()
{
    cout << "Function 1 :" << endl;
    cout << "Your name is " << a << endl;
}
void Summa :: print(string x)
{
    a = x;
    cout << "Function 2 :" << endl;
    cout << "Your name is " << a << endl;
}
int main()
{
    Summa s1,s2;
    s1.get();
    cout << "Calling Function 1 : " << endl;
    s1.print();
    cout << "Passing a String in Function 2 : " <<endl;
    s2.print("Bucky");
    return 0;
}


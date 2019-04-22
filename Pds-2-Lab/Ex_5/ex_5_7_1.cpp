#include<iostream>
using namespace std;
class Modulus
{
public:
    int a,b;
    void get();
    int modulud();
    int modulud(int ,int);
};
void Modulus :: get()
{
    cout << "Enter 2 nos :" << endl;
    cin >> a >> b;
}
int Modulus :: modulud()
{
    return a%b;
}
int Modulus :: modulud(int x,int y)
{
    return x%y;
}
int main()
{
    Modulus m1,m2;
    m1.get();
    m2.get();
    cout << "Modulus is : " << m1.modulud() << endl;
    cout << "Modulus is : " << m2.modulud(m2.a,m2.b);
    return 0;
}


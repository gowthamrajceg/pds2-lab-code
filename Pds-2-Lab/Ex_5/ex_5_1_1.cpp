#include<iostream>
using namespace std;
class Strcp
{
    string a;
public:
    Strcp()
    {
    }
    Strcp(string x)
    {
        a = x;
    }
    void display();
    void operator =(Strcp);
};
void Strcp :: display()
{
    cout << "a : " << a << endl;
}
void Strcp :: operator =(Strcp y)
{
    a = y.a;
}
int main()
{
    Strcp s1("Hello World "),s2;
    s2 = s1;
    s1.display();
    s2.display();
    return 0;
}

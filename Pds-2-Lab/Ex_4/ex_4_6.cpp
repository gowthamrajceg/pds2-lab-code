#include<iostream>
using namespace std;
class Negative
{
    int a,b;
public:
    Negative()
    {
    }
    Negative(int x,int y)
    {
        a = x;
        b = y;
    }
    void display();
    Negative operator +(Negative &);
};
void Negative :: display()
{
    cout << "a : " << a << " b : " << b << endl;
}
Negative Negative :: operator +(Negative &c) //Adding objects using binary'+'
{
    Negative temp;
    temp.a = a + c.a;
    temp.b = b + c.b;
    return temp;
}
int main()
{
    Negative n1(5,10),n2(15,20),n3;
    cout << "Obj 1 : ";
    n1.display();
    cout << "Obj 2 : ";
    n2.display();
    n3 = n1 + n2;
    cout << "Obj 3 = Obj 1 + Obj 2 : ";
    n3.display();
    return 0;
}


#include<iostream>
using namespace std;
class Demo
{
    int a,b;
public:
    Demo()
    {
    }
    Demo(int x,int y)
    {
        a = x;
        b = y;
    }
    Demo (Demo &summa) //Copying a Constructor
    {
        a = summa.a;
        b = summa.b;
    }
    void display();
};
void Demo :: display()
{
    cout << "A :" << a << " B :" << b << endl;
}
int main()
{
    Demo d1(10,20),d2(d1);
    d1.display();
    d2.display();
    return 0;
}

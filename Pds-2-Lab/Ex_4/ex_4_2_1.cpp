#include<iostream>
using namespace std;
class Demo
{
    int a,b;
public:
    Demo()
    {
        a = 0;
        b = 1;
    }
    Demo(int x,int y) //Paramatised Constructor
    {
        a = x;
        b = y;
    }
    void display();
};
void Demo :: display()
{
    cout << "A :" << a << " B :" << b << endl;
}
int main()
{
    Demo d1,d2(10,20);
    d1.display();
    d2.display();
    return 0;
}

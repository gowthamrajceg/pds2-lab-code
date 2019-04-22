#include<iostream>
using namespace std;
class Demo
{
    int a,b;
public:
    Demo(int x,int y)
    {
        a = x;
        b = y;
        cout << "Hi! From Constructor" << endl;
    }
    ~Demo() // Destructor
    {
        cout << "Hi! From Destructor" <<endl;   // Print Statement is not needed here..but still to understand destructor, i've included the print statement...Destructor will be called for n times for n number of objects created to destroy them :)
    }
    void display();
};
void Demo :: display()
{
    cout << "A :" << a << " B :" << b << endl;
}
int main()
{
    Demo d1(10,20), d2(100,200), d3(900,1000);
    d1.display();
    d2.display();
    d3.display();
    return 0;
}


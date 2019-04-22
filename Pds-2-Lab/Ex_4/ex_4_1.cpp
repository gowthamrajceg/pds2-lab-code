#include<iostream>
using namespace std;
class Demo
{
    int a,b;
public:
    Demo()
    {
        a = 5;
        b = 10;
    }
    void display();
};
void Demo :: display()
{
    cout << "A :" << a << " B :" << b << endl;
}
int main()
{
    Demo d;
    d.display();
    return 0;
}

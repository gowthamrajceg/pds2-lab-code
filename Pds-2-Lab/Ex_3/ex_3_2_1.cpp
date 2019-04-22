#include<iostream>
using namespace std;
class Two;
class One
{
public:
    int a;
    void display();
    friend void multiply(One , Two);
};
void One :: display()
{
    cout << "Variable 1: " <<a <<endl;
}
class Two
{
public:
    int b;
    void display();
    friend void multiply(One , Two);
};
void Two :: display()
{
    cout << "Variable 2: " <<b<<endl;
}
void multiply(One o,Two t)      //Type 1:method multiply is the friend function of both the classes
{
    cout << "Answer is "<< (o.a * t.b);
}
int main()
{   One x;
    Two y;
    cout << "Enter number 1 : ";
    cin >> x.a;
    cout << "Enter number 2 : ";
    cin >> y.b;
    x.display();
    y.display();
    multiply(x,y);
}

#include<iostream>
using namespace std;
class Two;
class One
{
public:
    int a;
    void multiply(Two);
    void display()
{
    cout << "Variable 1: " <<a<<endl;
}
};
class Two
{
public:
    int b;
    void display();
    friend void One::multiply(Two);
};
void One::multiply(Two t)
{
    cout << "Answer is "<< (a * t.b);
}
void Two :: display()
{
    cout << "Variable 2: " <<b<<endl;
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
    x.multiply(y);
}


#include<iostream>
using namespace std;
class Demo
{
public :
    int a;
    Demo()
    {
    }
    Demo(int n)
    {
        a = n;
    }
    void display();
};
void Demo::display()
{
    cout << "Int a : " << a << endl;
}
int main()
{
    int b;
    cout << "Enter the no :";
    cin >> b;
    Demo d(b),*dp;
    dp = &d; //creating a ( pointer to Class ) and assigning it to another normal Class object
    dp->display();
    int Demo::*p = &Demo::a; //creating a pointer to only the member of a Class..It can be accessed or modified only through objects
    d.*p = 10; //assinging the int a = 10 in object d
    d.display();
    dp->*p = 20;//Since *dp is refering to object d, assinging also works this way
    dp->display();
    void (Demo::*q)() = &Demo::display; // assinging pointer to method in a class
    (d.*q)();
}

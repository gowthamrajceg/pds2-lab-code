#include<iostream>
using namespace std;
class Parent
{
public:
    virtual void display()
    {
       cout << "Hi! This is Parent's Class.";
    } 
    void sum()
    {
        cout << "No Sum..Its main class.";
    }
};
class Child : public Parent
{
    int a,b;
public:
    Child(int x,int y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        cout << "Hi! This is Child's Class.";
    }
    void sum()
    {
        cout << "Sum is :" << a+b;
    }
};
int main()
{
    Parent *p;
    Child c;
    p = &c;
    p->display(); //without the virtual keyword in the Parent class's display method, the ocompiler will get the Parent's display..this is called Early Binding
    p->sum();
    return 0;
}

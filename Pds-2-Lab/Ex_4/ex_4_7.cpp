#include<iostream>
using namespace std;
class Add
{
public:
    int a,b;
    void get();
    int add();
    int add(int ,int);
};
void Add :: get()
{
    cout << "Enter 2 nos :" << endl;
    cin >> a >> b;
}
int Add :: add()
{
    return a+b;
}
int Add :: add(int x,int y) //Normal function Overloading
{
    return x+y;
}
int main()
{
    Add a1,a2;
    a1.get();
    a2.get();
    cout << "Addition is : " << a1.add() << endl;
    cout << "Addition is : " << a2.add(a2.a,a2.b);
    return 0;
}

#include<iostream>
using namespace std;
void value(int x,int y);
int main()
{
    int a,b;
    cout << "Enter two values :";
    cin >> a >> b;
    cout << "Before : x = "<< a <<" y =  "<< b <<endl;
    value(a,b);
    cout << "After : x = "<< a <<" y =  "<< b <<endl;
}
void value(int x,int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout << "In call by value function : x = "<< x <<" y =  "<< y <<endl;
}

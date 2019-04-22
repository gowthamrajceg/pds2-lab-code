#include<iostream>
using namespace std;
void refer(int &x,int &y);
int main()
{
    int a,b;
    cout << "Enter two values :";
    cin >> a >> b;
    cout << "Before : x = "<< a <<" y =  "<< b <<endl;
    refer(a,b);
    cout << "After : x = "<< a <<" y =  "<< b <<endl;
}
void refer(int &x,int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

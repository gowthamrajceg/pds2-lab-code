#include<iostream>
using namespace std;
void swapp(int *,int *);
int main()
{
    int a,b;
    cout << "Enter two numbers:";
    cin >> a >> b;
    cout <<"Before swapping"<<endl;
    cout << "A :" << a << " B :" << b << endl;
    swapp(&a,&b);
    cout <<"After swapping"<<endl;
    cout << "A :" << a << " B :" << b;
    return 0;
}

void swapp(int *p,int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

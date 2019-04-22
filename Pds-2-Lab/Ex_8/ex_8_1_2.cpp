#include<iostream>
using namespace std;
int temp;
int* multi(int *,int *);
int main()
{
    int a,b,*r;
    cout << "Enter two numbers:";
    cin >> a >> b;
    r=multi(&a,&b);
    cout <<"Answer"<<endl;
    cout << *r;
    return 0;
}

int* multi(int *p,int *q)
{
    temp = (*p)*(*q);
    return &temp;
}


#include<iostream>
using namespace std;
int multi(int *,int *);
int main()
{
    int a,b;
    int (*r)(int *,int *);
    cout << "Enter two numbers:";
    cin >> a >> b;
    r = &multi;
    cout <<"Answer"<<endl;
    cout << r(&a,&b);
    return 0;
}

int multi(int *p,int *q)
{
    return (*p)*(*q);
}

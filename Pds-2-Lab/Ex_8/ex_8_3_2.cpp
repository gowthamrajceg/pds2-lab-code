#include<iostream>
using namespace std;
class Demo
{
    public:
    int add(int *,int *);
};

int main()
{
    int a,b;
    Demo d;
    cout << "Enter two numbers:";
    cin >> a >> b;
    int (Demo::*r)(int *,int *) = &Demo::add;
    cout <<"Answer"<<endl;
    cout << (d.*r)(&a,&b);
    return 0;
}

int Demo::add(int *p,int *q)
{
    return (*p)+(*q);
}

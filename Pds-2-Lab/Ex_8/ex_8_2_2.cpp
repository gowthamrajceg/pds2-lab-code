#include<iostream>
using namespace std;
int* add(int *,int *,int);
int c[10];
int main()
{
    int a[10],b[10],*p,*q,*r,n;
    cout << "Enter the number of elements:";
    cin >> n;
    cout << "Enter the elements of A :";
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << "Enter the elements of B :";
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
    }
    p = &a[0];
    q = &b[0];
    r = &c[0];
    r = add(p,q,n);
    cout << "The elements in the Answer Array C : ";
    for(int i=0;i<n;i++)
    {
        cout << * r<< " " ;
        r++;
    }
    return 0;
}

int* add(int *p,int *q,int n)
{

    for(int i=0;i<n;i++)
    {
        c[i] = *p + *q;
        p++;
        q++;
    }
    return c;
}


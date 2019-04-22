#include<iostream>
using namespace std;
void display(int *,int);
int main()
{
    int a[10],n;
    cout << "Enter the number of elements:";
    cin >> n;
    cout << "Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << "The elements in the Array : ";
    display(a,n);
    return 0;
}

void display(int *p,int q)
{
    for(int i=0;i<q;i++)
    {
        cout <<*p << " ";
        p++;
    }
}

#include<iostream>
using namespace std;
class Larger
{
    int a,b;
public:
    void read();
    void display();
    int large();
};
void Larger :: read()
{
    cout << "Enter two numbers : ";
    cin >> a >> b;
}
void Larger :: display()
{
    cout << "Larger value is :" << large(); //calling the method large() inside the method display()
}
int Larger :: large()
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    Larger l;
    l.read();
    l.display();
    return 0;
}

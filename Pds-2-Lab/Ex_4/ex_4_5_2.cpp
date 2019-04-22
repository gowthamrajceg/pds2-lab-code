#include<iostream>
using namespace std;
class Negative
{
    int a,b,c;
public:
    Negative(int x,int y,int z)
    {
        a = x;
        b = y;
        c = z;
    }
    void display();
    void operator --();
};
void Negative :: display()
{
    cout << "a : " << a << " b : " << b << " c : " << c << endl;
}
void Negative :: operator --() //Decrementing the value of the variables using unary '--'
{
    --a;
    --b;
    --c;
}
int main()
{
    Negative n(5,10,15);
    n.display();
    --n;
    n.display();
    return 0;
}

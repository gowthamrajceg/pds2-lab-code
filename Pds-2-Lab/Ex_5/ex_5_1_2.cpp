#include<iostream>
using namespace std;
class Greater
{
    int a;
public:
    Greater(int x)
    {
        a = x;
    }
    bool operator >(Greater);
};
bool Greater :: operator >(Greater y)
{
    if(a > y.a)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int p,q;
    cout << "Enter a numbers for Object G1:";
    cin >> p;
    cout << "Enter a numbers for Object G2:";
    cin >> q;
    Greater g1(p),g2(q);
    bool t = g1>g2;
    if(t)
    {
        cout << "G1 "<< p <<" is Greater than G2 " << q << endl;
    }
    else
    {
        cout << "G2 "<< q <<" is Greater than G1 " << p << endl;
    }
    return 0;
}

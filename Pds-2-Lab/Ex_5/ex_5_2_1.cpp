#include<iostream>
using namespace std;
class Parent
{
protected :
    int a;
public :
    void setData(int x)
    {
        a = x;
    }
    void printData()
    {
        cout << "Number is : " << a << endl;
    }
};
class Child : public Parent
{
public:
    Child()
    {
    }
};
int main()
{
    Child c;
    int num;
    cout << "Enter a number :" ;
    cin >> num;
    c.setData(num);
    c.printData();
    return 0;
}

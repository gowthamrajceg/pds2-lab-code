#include<iostream>
using namespace std;
class Number
{
protected:
    int num;
public:
    void getNumber()
    {
        cout << "Enter a number : " << endl;
        cin >> num;
    }
};
class Square : public Number
{
public:
    void square()
    {
        num = num * num;
        cout << "Square of num :" <<num<< endl;
    }
};
class Minus : public Square
{
public:
    void minus_num()
    {
        int x;
        cout << "Enter the number to minus from num :";
        cin >> x;
        cout << "Minus is " << (num-x) << endl;
    }
};
int main()
{
    Minus m;
    m.getNumber();
    m.square();
    m.minus_num();
    return 0;
}


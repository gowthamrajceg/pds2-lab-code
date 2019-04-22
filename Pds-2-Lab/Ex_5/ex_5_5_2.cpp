#include<iostream>
using namespace std;
class Conversion
{
protected:
    float rupee;
public:
    Conversion()
    {
    }
    Conversion(float x)
    {
        rupee = x;
    }
};
class Dollar : public Conversion
{
protected:
    float dollar;
public:
    Dollar(int x):Conversion(x)
    {
    }
    void display()
    {
        dollar = (rupee / 68.52);
        cout <<"Dollar is : " << dollar <<endl;
    }
};
class Euro : public Conversion
{
protected:
    float euro;
public:
    Euro(int x):Conversion(x)
    {
    }
    void display()
    {
        euro = (rupee / 79.36);
        cout << "Euro is : "<< euro <<endl;
    }
};
int main()
{
    float x;
    cout << "Enter the money in Rupees " ;
    cin >> x;
    Dollar d(x);
    Euro e(x);
    d.display();
    e.display();
}


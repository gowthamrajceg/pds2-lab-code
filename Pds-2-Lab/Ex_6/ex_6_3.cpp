/* Classes HouseEmi and CarEmi are derived from class Savings
Class Total is derived from both classes HouseEmi and CarEmi
Thus, making it Hybrid
                      Savings
                    ____|______
                   |           |
                HouseEmi     CarEmi
                   |___________|
                         |
                       Total
We are using Virtual keyword while inheriting Savings for
HouseEmi and CarEmi..BEcause "setSavings" functions can be
accessed in two ways..Total->House->Savings and Total->Car->Savings
.if the virtual is not there, the compiler would throw an error
"ambiguous" and ask you to show the path..if virtul keyword
is there, it will choose its own path, automically.
*/
#include<iostream>
using namespace std;
class Savings
{
public:
    int savings;
    void setSavings(int x)
    {
        savings = x;
    }
};
class HouseEmi : virtual public Savings
{
protected:
    int h_emi;
public:
    void house_emi()
    {
        h_emi = savings / 10;
    }
};
class CarEmi : virtual public Savings
{
protected:
    int c_emi;
public:
    void car_emi()
    {
        c_emi = savings / 50;
    }
};
class Total : public HouseEmi,public CarEmi
{
protected:
    int total;
public:
    void display()
    {
    total = h_emi + c_emi;
    savings = savings - total;
    cout << "House Emi :" << h_emi << endl;
    cout << "Car Emi :" << c_emi << endl;
    cout << "Remaining Savings :" << savings << endl;
    }
};
int main()
{
    Total t;
    int x;
    cout << "Enter the Savings :";
    cin >> x;
    t.setSavings(x);
    t.house_emi();
    t.setSavings(x);
    t.car_emi();
    t.display();
    return 0;
}


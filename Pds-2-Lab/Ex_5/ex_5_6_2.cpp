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
*/
#include<iostream>
using namespace std;
class Savings
{
protected:
    int savings;
public:
    void setSavings(int x)
    {
        savings = x;
    }
};
class HouseEmi : public Savings
{
protected:
    int h_emi;
public:
    void house_emi()
    {
        h_emi = savings / 10;
    }
};
class CarEmi : public Savings
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
    HouseEmi::savings = HouseEmi::savings - total;
    CarEmi::savings = CarEmi::savings - total;
    cout << "House Emi :" << h_emi << endl;
    cout << "Car Emi :" << c_emi << endl;
    cout << "Remaining Savings :" << HouseEmi::savings << endl;
    }
};
int main()
{
    Total t;
    int x;
    cout << "Enter the Savings :";
    cin >> x;
    t.HouseEmi::setSavings(x);
    t.house_emi();
    t.CarEmi::setSavings(x);
    t.car_emi();
    t.display();
    return 0;
}

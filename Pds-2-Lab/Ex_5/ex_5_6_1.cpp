/* Class IncomeTax is derived from class Salary
Class Total is derived from both classes Income tax and Car tax
Thus, making it Hybrid
                Salary
                  |
                IncomeTax   CarTax
                   |___________|
                         |
                       Total

*/
#include<iostream>
using namespace std;
class Salary
{
protected:
    int salary;
public:
    void setSalary()
    {
        cout << "Enter the Salary :";
        cin >> salary;
    }
};
class IncomeTax : public Salary
{
protected:
    int income_t;
public:
    void incomet_calculate()
    {
        income_t = salary / 10;
    }
};
class CarTax
{
protected:
    int car_t;
public:
    void setCarTax()
    {
        cout << "Enter the Car tax :" ;
        cin >> car_t;
    }
};
class Total : public IncomeTax,public CarTax
{
protected:
    int total;
public:
    void display()
    {
    total = income_t + car_t;
    cout << "Income tax :" << income_t << endl;
    cout << "Car tax :" << car_t << endl;
    cout << "Total tax :" << total << endl;
    }
};
int main()
{
    Total t;
    t.setSalary();
    t.incomet_calculate();
    t.setCarTax();
    t.display();
    return 0;
}

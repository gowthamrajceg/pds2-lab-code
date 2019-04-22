#include<iostream>
using namespace std;
class Appa
{
protected:
    int appa_pm;
public:
    void money_appa()
    {
        cout << "Enter the pocket money given by Appa :" << endl;
        cin >> appa_pm;
    }
};
class Amma
{
protected:
    int amma_pm;
public:
    void money_amma()
    {
        cout << "Enter the pocket money given by Amma :" << endl;
        cin >> amma_pm;
    }
};
class Total : public Appa,public Amma
{
private:
    int total_pm;
public:
    void display()
    {
        total_pm = appa_pm + amma_pm;
        cout << "Pocket money given by Appa :" <<appa_pm<< endl;
        cout << "Pocket money given by Amma:" <<amma_pm<< endl;
        cout << "Total Pocket money :" <<total_pm<< endl;
    }
};
int main()
{
    Total t;
    t.money_appa();
    t.money_amma();
    t.display();
    return 0;
}


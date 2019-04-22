#include<iostream>
using namespace std;
class Demo
{
    string a;
public:
    Demo()
    {
    }
    Demo(string s)
    {
        a = s;
    }
    void display();
};
void Demo :: display()
{
    cout << "Hi " << a << " :)"<< endl;
}
int main()
{
    string x;
    cout << "Enter your name :" ;
    cin >> x;
    Demo d(x);
    d.display();
    return 0;
}


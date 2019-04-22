#include<iostream>
using namespace std;
class Grandparents
{
public:
    void display_Gp()
    {
        cout << "Hi ! This is Grandparents Class..." << endl;
    }
};
class Parents : public Grandparents
{
public:
    void display_P()
    {
        cout << "Hi ! This is Parents Class..." << endl;
    }
};
class Child : public Parents
{
public:
    void display_Child()
    {
        cout << "Hi ! This is Child Class..." << endl;
    }
};
int main()
{
    Child c;
    c.display_Gp();
    c.display_P();
    c.display_Child();
    return 0;
}

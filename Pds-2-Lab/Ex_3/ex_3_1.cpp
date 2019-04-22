#include<iostream>
using namespace std;
class Incre
{
public:
    static int count_var;
    static void countfun();
    void display();
};
int Incre :: count_var; //static variables should be defined like this outside the class, otherwise it'll throw an error
void Incre :: countfun()
{
    count_var++;
}
void Incre :: display()
{
    cout << count_var;
}
int main()
{
    Incre i;
    Incre::countfun(); //Static functions are independent of the object of class.so it's ideal to call by scope resolution operator.
    Incre::countfun();
    Incre::countfun();
    i.display(); //to show static variables can be accesed by normal functions also
}

#include<iostream>
using namespace std;
class Details
{
protected:
    string name;
    int age;
public:
    void getInfo()
    {
        cout << "Enter the name :" ;
        cin >> name;
        cout << "Enter the age :" ;
        cin >> age;
    }
};
class Professor : public Details
{
public:
    void display()
    {
        cout << "Professor : \n"<< "Name :" << name << " Age :" << age <<endl;
    }
};
class Teaching_Fellow : public Details
{
public:
    void display()
    {
        cout << "Teaching Fellow : \n"<< "Name :" << name << " Age :" << age <<endl;
    }
};
class Students : public Details
{
public:
    void display()
    {
        cout << "Students : \n"<< "Name :" << name << " Age :" << age << endl;
    }
};
int main()
{
    Professor p;
    Teaching_Fellow t;
    Students s;
    cout << "Enter the info of Professor :" << endl;
    p.getInfo();
    cout << "Enter the info of Teaching Fellow :" << endl;
    t.getInfo();
    cout << "Enter the info of Students :" << endl;
    s.getInfo();
    p.display();
    t.display();
    s.display();
}

#include<iostream>
using namespace std;
struct address
{
    string city;
    string state;
};
struct details
{
    char name[20];
    int roll;
    address add;
};
int main()
{
    details d[5];
    for(int i=0;i<2;i++)
    {
    cout<<"Enter name :";
    cin >>d[i].name;
    cout<<"Enter roll :";
    cin >>d[i].roll;
    cin.ignore();
    cout<<"Ente city :";
    getline(cin,d[i].add.city);
     cout<<"Enter state :";
    getline(cin , d[i].add.state);
    }
    for(int i=0;i<2;i++)
    {
        cout<<"Name "<<d[i].name <<" Roll "<<d[i].roll<<" City "<<d[i].add.city <<" State "<<d[i].add.state;
    }
    return 0;
}

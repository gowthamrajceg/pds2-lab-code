#include<iostream>
using namespace std;
struct stud
{
    char name[25];
    int roll;
};
int main()
{
 stud s[10];
 int n;
 cout << "Enter the number of studs:";
 cin >> n;
 for(int i=0;i<n;i++)
 {
     cout << "Enter the name of stud " << (i+1) << ":";
     cin >> s[i].name;
     cout << "Enter the roll of stud " << (i+1) << ":";
     cin >> s[i].roll;
 }
 for(int i=0;i<n;i++)
 {
     cout << s[i].name;
     cout << s[i].roll;
 }
 return 0;
}

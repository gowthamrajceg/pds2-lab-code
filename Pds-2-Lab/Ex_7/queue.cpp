#include <iostream>
using namespace std;
#define SIZE 10
int A[SIZE];
int front = -1,back = -1;
bool isempty()
{
  if(back==-1)
  {
    return true;
  }
  else if(front+1==back)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void inser(int value)
{
  if(front==SIZE-1)
  {    cout<<"Queue is full!\n";
  }
   else
  {
    A[++front]=value;
    if(back == -1)
    {
    back = 0;
    }
  }
}
void delet()
{
 if(isempty())
 {
  cout<<"Queue is empty!\n";
 }
 else
  {
   cout << A[back++] << " is deleted" << endl;
  }
}
void display()
{
  if(isempty())
 {
    cout<<"Queue is empty!\n";
 }
 else
 {
     cout<< "The elements in the queue are :" << endl;
  for(int i=back ; i<=front; i++)
  {
    cout<<A[i]<<" ";
  }
   cout<<"\n";
  }
}
int main()
{
 int choice, flag=1, value;
 while(flag == 1)
 {
 cout<<"\n1.Insert 2.Delete 3.DISPLAY 4.EXIT\nEnter your choice :";
 cin>>choice;
 switch (choice)
 {
 case 1: cout<<"Enter Value :";
         cin>>value;
         inser(value);
         break;
 case 2: delet();
         break;
 case 3: display();
         break;
 case 4: flag = 0;
         break;
 default: cout<< "Enter correct choice ." << endl;
 }
 }
  return 0;
}

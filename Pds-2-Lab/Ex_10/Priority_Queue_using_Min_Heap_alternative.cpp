#include<iostream>
using namespace std;
int arr[100],count=0;
void enqueue(int x)
{
    int hole = ++count;
    for(;hole>1 && x<arr[hole/2];hole/=2)
    {
        arr[hole] = arr[hole/2];
    }
    arr[hole] = x;
}
void dequeue()
{
    if(count!=0)
    {
    cout << arr[1];
    arr[1] = arr[count--];
    int hole = 1,child;
    int temp = arr[hole];
    for(;hole*2<=count;hole=child)
    {
        child = hole * 2;
        if(child!=count && arr[child]>arr[child+1])
        {
            child++;
        }
        if(arr[child]<temp)
        {
            arr[hole] = arr[child];
        }
        else
        {
            break;
        }
    }
    arr[hole] = temp;
    }
    else
    {
        cout << "Queue Empty!!!" << endl;
    }
}
void display()
{
    if(count==0)
    {
        cout << "Queue Empty!!!" << endl;
    }
    else
    {
        for(int i =1;i<=count;i++)
        {
            cout << arr[i] << " ";
        }
    }
}
int main()
{
    int choice,n;
    bool flag = true;
    while(flag)
    {
        cout << "\n1.Insert 2.Delete 3.Display 4.Exit\nEnter Choice :";
        cin >> choice;
        switch(choice)
        {
        case 1:
        {
            cout << "Enter the value to be inserted:";
            cin >> n;
            enqueue(n);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            flag = false;
            break;
        }
        default:
        {
            cout << "Enter correct choice." << endl;
        }
        }
    }
    return 0;
}

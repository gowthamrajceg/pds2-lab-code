#include<iostream>
using namespace std;
int arr[100],count=0;
void heapify(int i)
{
    int smallest = i;
    int l = (2*i)+1;
    int r = (2*i)+2;
    if(l<count&&arr[l]<arr[smallest])
    {
        smallest = l;
    }
    if(r<count&&arr[r]<arr[smallest])
    {
        smallest = r;
    }
    if(smallest!=i)
    {
        swap(arr[i],arr[smallest]);
        heapify(smallest);
    }
}
void enqueue(int x)
{
    arr[count++] = x;
    int i;
    for(i=(count/2)-1;i>=0;i--)
    {
        heapify(i);
    }
}
void dequeue()
{
    int i =count-1;
    if(count!=0)
    {
    cout << arr[0];
    swap(arr[0],arr[i]);
    count--;
    heapify(0);
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
        for(int i =0;i<count;i++)
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

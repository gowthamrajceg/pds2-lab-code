#include<iostream>
using namespace std;
static int count=0;
class Store
{
    int code,qua;
    float price,tot;
    string name;
public:
    float total();
    void add();
    void delet(int);
    void display();
    void modify(int);
}s[10];
int main()
{
    int choice,c;
    bool flag = true;

    while(flag)
    {
        cout << "\n1.Add 2.Delete 3.Modify 4.Display 5.Exit..\nEnter your choice :" ;
    cin >> choice;
    switch(choice)
    {
    case 1:
        {
            s[count].add();break;
        }
    case 2:
        {
            cout << "Enter the code number :" ;
            cin >> c;
            s[count].delet(c);
            break;
        }
        case 3:
        {
            cout << "Enter the code number :" ;
            cin >> c;
            s[count].modify(c);
            break;
        }
        case 4:
        {
            s[count].display();
            break;
        }
        case 5:
            flag = false;break;
        default:
            cout << "Enter correct choice :"<< endl;
    }
    }
}
void Store :: add()
{
    cout << "Enter code no :" ;
    cin >> code;
    cout << "Enter product name :" ;
    cin >> name;
    cout << "Enter price :" ;
    cin >> price;
    cout << "Enter quantity :" ;
    cin >> qua;
    tot = price * qua;
    count++;
}
void Store :: display()
{
    for(int i=0;i<count;i++)
    {
        cout << "Code no :" << s[i].code << " product name :" << s[i].name << " price :" << s[i].price << " quantity :"<< s[i].qua << " Total = " << s[i].tot<<endl;
    }
    cout << "Total Amount :" << total() <<endl;
}
float Store :: total()
{
    float sum=0;
    for(int i=0;i<count;i++)
    {
        sum = sum + s[i].tot;
    }
    return sum;
}
void Store :: delet(int x)
{
    for(int i=0;i<count;i++)
    {
        if(s[i].code == x)
        {
            for(int j=i;j<count;j++)
            {
                s[j] = s[j+1];
                count--;
            }
            break;
        }
    }
}
void Store :: modify(int x)
{
    int h;
    for(int i=0;i<count;i++)
    {
        if(s[i].code == x)
        {
            cout << "1.Price 2.Quantity...."<<endl;
            cin >> h;
            if(h==1)
            {
                cout << "Enter new Price : ";
                cin >> s[i].price;
                s[i].tot= s[i].price * s[i].qua;
            }
            else if(h==2)
            {
                cout << "Enter new Quantity : ";
                cin >> s[i].qua;
                s[i].tot= s[i].price * s[i].qua;
            }
        }
    }
}

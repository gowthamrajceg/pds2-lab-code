//Priority Queue
#include<iostream>
using namespace std;
struct node
{
    int data;
    int priority;
    struct node *next;
};
node *frontt = NULL;
node* createNode(int x,int y)
{
    node *temp;
    temp = new node;
    temp->data = x;
    temp->priority = y;
    temp->next = NULL;
    return temp;
}
bool isempty()
{
    if(frontt == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void insertNode()
{
    node *temp;
    int x,y;
    cout << "Enter the Element :";
    cin >> x;
    cout << "Enter the Priority :";
    cin >> y;
    temp = createNode(x,y);
    if(isempty())
    {
        frontt = temp;
    }
    else if(frontt->priority > y)
    {
        temp->next = frontt;
        frontt = temp;
    }
    else
    {
        node *traverse = frontt;
        while(traverse->next!= NULL && traverse->next->priority <= y)
        {
            traverse = traverse->next;
        }
        temp->next = traverse->next;
        traverse->next = temp;
    }
}
void deleteNode()
{
    node *temp = NULL;
    node *traverse = frontt;
    if(isempty())
    {
        cout << "List Empty " << endl;
    }
    else
    {
        temp = frontt;
        frontt = frontt->next;
        cout << temp->data << " is deleted" << endl;
        delete(temp);
    }
}
void display()
{
    if(isempty())
    {
        cout << "List Empty " << endl;
    }
    else
    {
        node *traverse = frontt;
        while(traverse!=NULL)
        {
            cout << traverse->data << "\t" << traverse->priority << endl;
            traverse = traverse->next;
        }
    }
}
int main()
{
    bool flag = true;
    int choice;
    while(flag)
    {
        cout << "\n1.Insert 2.Delete 3.Display 4.Exit\nEnter Choice :";
        cin >> choice;
        switch(choice)
        {
        case 1:
        {
            insertNode();
            break;
        }
        case 2:
        {
            deleteNode();
            break;
        }
        case 3:
        {
            cout << "Value" << " " << "  Priority" << endl;
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
}




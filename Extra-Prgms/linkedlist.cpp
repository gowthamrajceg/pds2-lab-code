#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
node *head = NULL;
node* createNode(int x)
{
    node *temp;
    temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}
bool isempty()
{
    if(head == NULL)
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
    int x;
    cout << "Enter the Element :";
    cin >> x;
    temp = createNode(x);
    if(isempty())
    {
        head = temp;
    }
    else
    {
        node *traverse = head;
        while(traverse->next!=NULL)
        {
            traverse = traverse->next;
        }
        traverse->next = temp;
    }
}
void deleteNode()
{
    int del;
    node *temp = NULL;
    cout << "Enter the Element :";
    cin >> del;
    node *traverse = head;
    if(isempty())
    {
        cout << "List Empty " << endl;
    }
    else if(head->data == del)
    {
        temp = head;
        head = head->next;
    }
    else
    {
        node *traverse = head;
        node *previous = NULL;
        while(traverse!=NULL)
        {
            if(traverse->data==del)
            {
                temp = traverse;
                if(traverse->next==NULL)
                {
                    previous->next = NULL;
                    break;
                }
                else if(traverse->next)
                {
                    previous->next = traverse->next;
                    break;
                }
            }
            previous = traverse;
            traverse = traverse->next;
        }
    }
    if(temp)
    {
        cout << temp->data << " is deleted" << endl;
    }
    else
    {
        cout << "Such Element doesn't exist " << endl;
    }
    delete(temp);
}
void reverseList()
{
    if(isempty())
    {
        cout << "List Empty " << endl;
    }
    else
    {
        node *current,*prev,*nextnode;
        current = head;
        prev = NULL;
        nextnode = NULL;
        while(current!=NULL)
        {
            nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }
        head = prev;
        cout << "Successfully Reversed " << endl;
    }
}
void reverseRecur(struct node *p)
{
    if(isempty())
    {
        cout << "List Empty " << endl;
        return;
    }
    else
    {
        if(p->next==NULL)
        {
            head = p;
            return;
        }
        reverseRecur(p->next);
        p->next->next = p;
        p->next = NULL;
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
        node *traverse = head;
        while(traverse!=NULL)
        {
            cout << traverse->data << " ";
            traverse = traverse->next;
        }
    }
}
void displayRecur(struct node *p)
{
    if(isempty())
    {
        cout << "List Empty " << endl;
    }
    else
    {
        if(p==NULL)
        {
            return;
        }
        cout << p->data << " ";
        displayRecur(p->next);
    }
}
int main()
{
    bool flag = true;
    int choice;
    while(flag)
    {
        cout << "\n1.Insert 2.Delete 3.Reverse 4.Reverse using Recursion 5.Display 6.Display using recursion 7.Exit\nEnter Choice :";
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
            reverseList();
            break;
        }
        case 4:
        {
            reverseRecur(head);
            break;
        }
        case 5:
        {
            display();
            break;
        }
        case 6:
        {
            displayRecur(head);
            break;
        }
        case 7:
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


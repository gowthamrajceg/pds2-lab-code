#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
node *head = NULL;
node* createNode(int x)
{
    node *temp;
    temp = new node;
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
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
        temp->prev = traverse;
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
        head->prev = NULL;
    }
    else
    {
        node *traverse = head;
        while(traverse!=NULL)
        {
            if(traverse->data==del)
            {
                traverse->prev->next = traverse->next;
            }
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
        node *current,*nextnode;
        current = head;
        nextnode = NULL;
        while(current!=NULL)
        {
            nextnode = current->next;
            current->next = current->prev;
            current->prev = nextnode;
            head = current;
            current = nextnode;
        }
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
        p->next->prev = p->next->next;
        p->next->next = p;
        if(p->prev!=NULL)
        {
            p->prev = p->next;
        }
        else
        {
            p->prev = p->next;
            p->next = NULL;
        }
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
            cout <<traverse->data << " ";
            traverse = traverse->next;
        }
    }
}
void displayReverse()
{
    if(isempty())
    {
        cout << "List Empty " << endl;
    }
    else
    {
        node *temp = NULL;
        node *p = head;
        while(p!=NULL)
        {
            temp = p;
            p = p->next;
        }
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }
}
int main()
{
    bool flag = true;
    int choice;
    while(flag)
    {
        cout << "\n1.Insert 2.Delete 3.Reverse 4.Reverse using Recursion 5.Display 6.Reverse Display 7.Exit\nEnter Choice :";
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
            displayReverse();
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



//Application Of Stack
#include<iostream>
#include<string>
using namespace std;
bool precedence(char ch1,char ch2);
int pre(char ch);
struct node
{
    char data;
    struct node *next;
};
node *head = NULL;
node* createNode(char x)
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
void push(char x)
{
    node *temp;
    temp = createNode(x);
    if(isempty())
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void pop()
{
    int del;
    node *temp = NULL;
    node *traverse = head;
    if(head == NULL)
    {
        cout << "empty";
    }

    else
    {
        temp = head;
        head = head->next;
    }

    delete(temp);
}
char peek()
{
    if(head==NULL)
    {
        return NULL;
    }
    return head->data;
}
int main()
{
    string exp,result;
    getline(cin,exp);
    int l = exp.length();
    int choice;
    char *e = &exp[0];
    while(l!=0)
    {
        if(isalpha(*e)||isdigit(*e))
        {
            result = result + *e;
        }
        else if(*e=='(')
        {
            push(*e);
        }
        else if(*e==')')
        {
            while(head!=NULL)
            {
                if(peek()=='(')
                {
                    pop();
                    break;
                }
                result = result + peek();
                pop();
            }
        }
        else
        {
            while(head!=NULL && peek()!= '(' && precedence(peek(),*e))
            {
                result = result + peek();
                pop();
            }
            push(*e);
        }
        e++;
        l--;
    }
    while(head!=NULL)
    {
        result = result + peek();
        pop();
    }
    cout << result;
}
bool precedence(char ch1,char ch2)
{
    int pre1 = pre(ch1);
    int pre2 = pre(ch2);
    if(pre1>=pre2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int pre(char ch)
{
    switch(ch)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    }
}


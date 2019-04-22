#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node* insert(Node *,int);
Node* Delete(Node *,int);
Node* findmax(Node *);
bool search(Node *,int);
void inorder(Node *);
void preorder(Node *);
void postorder(Node *);
Node* getNode(int);
int main()
{
    Node *root = NULL;
    bool flag = true;
    int choice,n;
    while(flag)
    {
        cout << "\n1.Insert 2.Delete 3.Search 4.Inorder 5.Preorder 6.Postorder 7.Exit\nEnter Choice :";
        cin >> choice;
        switch(choice)
        {
        case 1:
        {
            cout << "Enter the value to be inserted:";
            cin >> n;
            root = insert(root,n);
            break;
        }
        case 2:
        {
            cout << "Enter the value to be deleted:";
            cin >> n;
            root = Delete(root,n);
            break;
        }
        case 3:
        {
            cout << "Enter the value to be searched:";
            cin >> n;
            if(search(root,n)==true)
            {
                cout << "Found";
            }
            else
            {
                cout << "Not";
            }
            break;
        }
        case 4:
        {
            inorder(root);
            break;
        }
        case 5:
        {
            preorder(root);
            break;
        }
        case 6:
        {
            postorder(root);
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
Node* getNode(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* insert(Node *root,int x)
{
    if(root==NULL)
    {
        root = getNode(x);
    }
    else if(x <= root->data)
    {
        root->left = insert(root->left,x);
    }
    else if(x > root->data)
    {
        root->right = insert(root->right,x);
    }
    return root;
}
Node* Delete(Node *root,int x)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(x < root->data)
    {
        root->left = Delete(root->left,x);
    }
    else if(x > root->data)
    {
        root->right = Delete(root->right,x);
    }
    else
    {
        if(root->left==NULL&&root->right==NULL)
        {
            Node *temp = root;
            root = NULL;
            delete(temp);
        }
        else if(root->left==NULL)
        {
            Node *temp = root;
            root = root->right;
            delete(temp);
        }
        else if(root->right==NULL)
        {
            Node *temp = root;
            root = root->left;
            delete(temp);
        }
        else
        {
            Node *temp = findmax(root->left);
            root->data = temp->data;
            root->left = Delete(root->left,temp->data);
            delete(temp);
        }
        return root;
    }
}
Node* findmax(Node* temp)
{
    while(temp->right!=NULL)
    {
        temp = temp->right;
    }
    return temp;
}
bool search(Node *root,int x)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==x)
    {
        return true;
    }
    else if(x > root->data)
    {
        return search(root->right,x);
    }
    else
    {
        return search(root->left,x);
    }
}
void inorder(Node *temp)
{
    if(temp==NULL)
    {
        return;
    }
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}
void preorder(Node *temp)
{
    if(temp==NULL)
    {
        return;
    }
    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(Node *temp)
{
    if(temp==NULL)
    {
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}

//Not an 100% correct Max Heap implementation but stills this code manages to build max_heap and pops hightest element
#include<iostream>
using namespace std;

struct Node
{
    int data,height;
    Node *left;
    Node *right;
};

int arr[100],k=0,z=0;

int height(struct Node *N)
{
    if (N == NULL)
        return -1;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

struct Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left   = NULL;
    temp->right  = NULL;
    temp->height = 0;
    return(temp);
}

struct Node* rightRotate(struct Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node* leftRotate(struct Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int data)
{

    if (node == NULL)
        return(newNode(data));

    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(struct Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        arr[k++] = root->data;
        inOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        root->data=arr[z++];
    }
}

struct Node *pop(struct Node *T)
{
    if(T==NULL)
    {
        return T;
    }
    else if(T->left==NULL&&T->right==NULL)
    {
        Node *temp = T;
        T = NULL;
        delete(temp);
    }
    else if(T->right==NULL&& T->left!=NULL)
    {
        Node *temp = T;
        T = T->left;
        delete(temp);
    }
    else if(T->left==NULL&& T->right!=NULL)
    {
        Node *temp = T;
        T = T->right;
        delete(temp);
    }
    else if(T->left!=NULL && T->right!=NULL)
    {
        T->data = T->right->data;
        T->right = pop(T->right);
    }
    return T;
}

int main()
{
    struct Node *root = NULL;
    bool flag = true;
    int choice,n,time = 1;
    while(flag)
    {
        cout << "\n1.Insert 2.Pop_High_Priority 3.Exit \nEnter Choice :";
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
            if(time==1)
            {
                inOrder(root);
                postOrder(root);
                time++;
            }
            if(root==NULL)
            {
                cout << "Empty !";
            }
            else
            {
                cout << root->data << " is popped !";
                root = pop(root);
            }
            break;
        }
        case 3:
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

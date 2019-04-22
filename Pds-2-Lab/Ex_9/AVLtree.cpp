#include<iostream>
using namespace std;
struct Node
{
    int data,height;
    Node *left;
    Node *right;
};

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

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        cout <<root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node *root)
{
    if(root != NULL)
    {
        cout <<root->data << " ";
        inOrder(root->left);
        inOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if(root != NULL)
    {
        cout <<root->data << " ";
        postOrder(root->left);
        postOrder(root->right);
    }
}

struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}
struct Node* Delete(struct Node* root, int data)
{

    if (root == NULL)
        return root;

    if ( data < root->data )
        root->left = Delete(root->left, data);

    else if( data > root->data )
        root->right = Delete(root->right, data);

    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :
                                             root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp;
            delete(temp);
        }
        else
        {
            // node with two children: Get the inorder

            struct Node* temp = minValueNode(root->right);


            root->data = temp->data;


            root->right = Delete(root->right, temp->data);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
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


int main()
{
  	struct Node *root = NULL;
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
            inOrder(root);
            break;
        }
        case 5:
        {
            preOrder(root);
            break;
        }
        case 6:
        {
            postOrder(root);
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


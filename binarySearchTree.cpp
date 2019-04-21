#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = NULL;

    return node;
}
/*
Node* insert(Node* root, int key)
{
    if (root == NULL)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}
*/
void getBST(int arr[], int low, int high, Node* &root)
{
    if (low > high)
        return;

    int mid = (low + high) / 2;

    root = newNode(arr[mid]);

    getBST(arr, low, mid - 1, root->left);
    getBST(arr, mid + 1, high, root->right);
}

Node* convertTosorted(int arr[], int n)
{
    sort(arr, arr + n);

    Node *root = NULL;
    getBST(arr, 0, n-1, root);

    return root;
}

void inorder(Node* root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void LevelOrder(Node *root)
{
    if(root == NULL) return;
    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty())
    {
        Node* current = Q.front();
        Q.pop();
        cout<<current->data<<" ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
    }
}


bool Search(Node* root,int data)
{
    if(root == NULL)
    {
        return false;

    }
    else if(root->data == data)
    {
        return true;
    }
    else if(data <= root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
}
int main()
{
    int arr[] = { 99,65,120,45,36,96,100,12,88};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* root = convertTosorted(arr, n);

    inorder(root);
    cout<<endl;
    LevelOrder(root);
    int x;
    while(!0)
    {
        cout<<"\nEnter Element to Search :"<<endl;
        cin>>x;
        cout<<endl<<Search(root,x);
    }

    return 0;
}

#include<bits/stdc++.h>
typedef struct node
{
    int data;
    node * left;
    node * right;
    node(int val = 0)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
}node;

void insert(node ** root, int val)
{
    if(*root == NULL)
        *root = new node(val);
    else if((*root)->data <= val)
        insert(&((*root)->right), val);
    else if((*root)->data > val)
        insert(&((*root)->left), val);
}

node * getBST(int * arr, int size)
{
    node * root = NULL;
    for(int i = 0; i < size; i++)
        insert(&root, arr[i]);
    return root;
}

void inOrderTraversal(node * root)
{
    if(root && root->left)
        inOrderTraversal(root->left);
    if(root)
        std::cout<<root->data<<" , ";
    if(root && root->right)
        inOrderTraversal(root->right);

}
void LevelOrder(node *root) {
	if(root == NULL) return;
	queue<node*> Q;
	Q.push(root);

	while(!Q.empty()) {
		node* current = Q.front();
		Q.pop();
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}
int main()
{
    int arr[] = {15, 10, 20, 8, 12, 16, 25};
    node * root = getBST(arr, sizeof(arr)/sizeof(int));
    inOrderTraversal(root);
    std::cout<<std::endl;
    return 0;
}

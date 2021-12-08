#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left, *right;
};
int c=0;

// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// A utility function to search a given value in a BST
struct node* search(struct node* root, int key)
{
    if (root == NULL || root->key==key)
        return root;
    else if (root->key>key)
        return search(root->right, key);
 	else
        return search(root->left, key);
}

// A utility function to insert a new node with given key in the BST
struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
// A utility function to find the minimum value in the BST
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
// A utility function to delete the key and returns the new root in the BST
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else 
	{
        if (root->left == NULL) 
		{
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
		{
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 		struct node* temp = minValueNode(root->right);
 		root->key = temp->key;
 		root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
// A utility function to find the minimum and maximum key value in the BST
void min_max(struct node* node)
{
		struct node* min=node;
		struct node* max=node;
		while(min->left!=NULL)
			min=min->left;
		while(max->right!=NULL)
			max=max->right;
		printf("\nThe minimum value present in the given BST is: %d ",min->key);
		printf("\nThe maximum value present in the given BST is: %d ",max->key);	
}
// A utility function to find the kth minimum key value in the BST
void kth_min(struct node* root, int k)
{
	if(root==NULL)
		return;
	else
	{
		kth_min(root->left,k);
		c++;
		if(c==k)
			printf("\nThe Kth minimum value in the BST for k=%d is: %d",k,root->key);
		kth_min(root->right,k);
	}
}
// A utility function to find the kth minimum key value in the BST
void kth_max(struct node* root, int k)
{
    struct node* curr = root;
    struct node* Klargest = NULL;
 
    int count = 0;
    while (curr != NULL)
	{
        if (curr->right == NULL)
		{
 		    if (++count == k)
                Klargest = curr;
 		    curr = curr->left;
        }
        else
		{
            struct node* succ = curr->right;
             while (succ->left != NULL && succ->left != curr)
                succ = succ->left;
            if (succ->left == NULL) 
			{
 			    succ->left = curr;
                curr = curr->right;
            }
            else 
			{
                succ->left = NULL;
                if (++count == k)
                   Klargest = curr;
                curr = curr->left;
            }
        }
    }
    printf("\nThe Kth Largest value in the BST for k=%d is: %d",k,Klargest->key);
}
	

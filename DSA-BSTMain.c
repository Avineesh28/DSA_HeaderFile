#include "DSA-BST.h"
int main()
{
    /* Let us create a default BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node* root = NULL;
	root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Inorder traversal of the default Binary Search Tree \n");
    inorder(root);
 	printf("\nWelcome!\nPlease Enter\n1 - To insert element in the BST\n2 - To delete element in the BST\n3 - To determine the Minimum and maximum element in the BST\n4 - To determine the kth minimum element\n5 - To determine the kth maximum element\nOr any other number to exit\n");
	int choice;
 	scanf("%d",&choice);
	int flag=0;
	int k;
	while(flag==0)
	{
		switch(choice)
		{
			case 1: if(root!=NULL)
					{
						printf("Enter the value to be inserted\n");
						int t;
						scanf("%d",&t);
						struct node* temp=search(root,t);
						if(temp==NULL)						
						{
							insert(root,t);
							printf("\nInserted\n");
							printf("\nInorder traversal of the BST \n");
							inorder(root);
							printf("\n");
						}
						else
						printf("Value already present\n");
					}
					break;
			case 2: if(root!=NULL)
					{
						printf("Enter the value to be deleted\n");
						int t;
						scanf("%d",&t);
						struct node* temp=search(root,t);
						deleteNode(root,t);
						printf("\nDeleted\n");
						printf("\nInorder traversal of the BST \n");
						inorder(root);
						printf("\n");
					}
					break;
			case 3: min_max(root);
					printf("\n");
					break;
			case 4:	printf("Enter the value of k\n");
					scanf("%d",&k);
					kth_min(root,k);
					printf("\n");
					break;
			case 5: printf("Enter the value of k\n");
					scanf("%d",&k);
					kth_max(root,k);
					printf("\n");
					break;
			default:printf("\nThank You!\n");
					flag=1;
		}
		if(flag==0)
		{
			printf("\nEnter Choice\n");
			scanf("%d",&choice);
		}
	} 	
    return 0;
}

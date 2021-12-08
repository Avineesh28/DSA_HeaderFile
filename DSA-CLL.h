#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
	int info;
	struct node* next;
};
int c=0;
struct node* head = NULL;
void addNodeB();
void addNodeP(int);
void addNodeE();
void delNodeB();
void delNodeP(int);
void delNodeE();
void display();
void search(int);

void addNodeB()
{
	int t;
	printf("Enter the value\n");
	scanf("%d",&t);
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->info=t;
	if(head!=NULL)
	{
		struct node* temp1=head;
		while(temp1->next!=head)
			temp1=temp1->next;
		temp1->next=temp;
		temp->next=head;
		head=temp;
	}
	else
	{
		temp->next=temp;
		head=temp;
	}

	c++;
}
void addNodeE()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value\n");
	int v;
	scanf("%d",&v);
	temp->info=v;
	if(c==0)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		struct node *temp1=head;	
		while(temp1->next!=head)
			temp1=temp1->next;
		temp1->next=temp;
		temp->next=head;	
	} 
	c++;	
}
void addNodeP(int p)
{
	int t;
	printf("Enter the value\n");
	scanf("%d",&t);
	int c=1;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->info=t;
	if(head != NULL)
	{
		struct node* temp1=head;
		while(c<p-1)
		{
			temp1=temp1->next;
			c++;
		}
		c--;
		temp->next=temp1->next;
		temp1->next=temp;
	}
	else
		temp->next=temp;	
	c++;
}
void delNodeB()
{
	struct node *temp=head;
	if(head!=NULL)
	{
		while(temp->next!=head)
			temp=temp->next;
		if(temp==head)
			head=NULL;
		else
		{
			temp->next=head->next;
			head=head->next;
		}
	}
	else
		printf("List Empty\n");
	c--;
				
}
void delNodeE()
{
	if(head!=NULL)
	{
		struct node *temp1=head;	
		while(temp1->next->next!=head)
			temp1=temp1->next;
		temp1->next=head;
	}
	else if(c==1)
	{
		head=head->next;
	}
	else
		printf("List Empty\n");
		c--;
}
void delNodeP(int p)
{
	int c=1;
	struct node *temp=head;
	while(c!=p-1)
	{
		temp=temp->next;
		c++;
	}
	c=1;
	temp->next=temp->next->next;
	c--;
}
void search(int item)
{
    struct node *ptr;
    int i=0,flag=1;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        if(head->info == item)
        {
        	printf("Item found at location %d\n",i+1);
        	flag=0;
        }
        else
        {
        	while (ptr->next != head)
        	{
	            if(ptr->info == item)
	            {
	                printf("Item found at location %d \n",i+1);
	                flag=0;
	                break;
	            }
	            else
	            {
	                flag=1;
	            }
	            i++;
	            ptr = ptr -> next;
	        }
	    }
     	if(flag != 0)
       	    printf("Item not found\n");
    }
}
void display()
{
	if(head!=NULL)
	{
		printf("Circular Linked List:\n\t==>");
		struct node *temp=head;
		while(temp->next!=head)
		{
			printf("%d-->",temp->info);
			temp=temp->next;
		}
		printf("%d==>\n",temp->info);
	}
	else
		printf("List is Empty");
}

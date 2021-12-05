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
void display()
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

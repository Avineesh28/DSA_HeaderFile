#include "DSA.h"
int main()
{
	int choice;
	printf("Welcome!\nEnter-\n1\t-\t to Add a Node in the beggining\n2\t-\t to Add a Node in the end\n3\t-\t to Add a Node at a specific position\n4\t-\t to Delete a Node from the beggining \n5\t-\t to Delete a Node from the end \n6-\t-\t to Delete a Node at a specific position\n7-\t-\t to display the list\n8-\t-\t to search a value in the list\nOr Any character to exit\n");
	scanf("%d",&choice);
	int flag=0;
	while(flag==0)
	{
		switch(choice)
		{
			case 1: addNodeB();
					break;
			case 2: addNodeE();
					break;	
			case 3: 
					{
						int p;
						printf("Enter the desired positon\n");
						display();
						scanf("%d",&p);
						if(p>c)
							printf("Invalid position\n");
						else	
						{
							if(p==1)
								addNodeB();
							else if(p==c)
								addNodeE();
							else
								addNodeP(p);
						}
						break;
					}
			case 4:	delNodeB();
					break;
			case 5: delNodeE();
					break;
			case 6: 
					{
						int p;
						printf("Enter the desired positon\n");
						display();
						scanf("%d",&p);
						if(p>c+1)
							printf("Invalid position\n");
						else	
						{
							if(p==1)
								delNodeB();
							else if(p==c+1)
								delNodeE();
							else
								delNodeP(p);
						}
						break;
					}
			case 7: display();
				break;
			case 8: 
					{
						int p;
						printf("Enter the search value\n");
						search(p);
						break;
					}	
			default:printf("Thank You!\n");
					flag=1;
		}
		if(flag==0)
		{
			printf("Enter Choice\n");
			scanf("%d",&choice);
		}	
	}
	return 1;
}

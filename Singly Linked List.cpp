#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);

int main()
{
	int c;
	do{
		printf("\n\n ****MAIN MENU****");
		printf("\n 1: Create a Linked List");
		printf("\n 2: Display the list");
		printf("\n 13: Exit");
		printf("\n\n Enter your choice");
		scanf("%d",&c);
		switch(c)
		{
			case 1: start = create_ll(start);
			printf("\nLinked List Created\n");
			break;
			case 2: start = display(start);
			break;
		}
	}while(c!=13);
	getch();
	return 0;
}

struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter -1 to end");
	printf("\n Enter the data");
	scanf("%d", &num);
	while(num!=-1)
	{
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	if(start==NULL)
	{
		new_node -> next = NULL;
		start = new_node;
		}	
	else
	{
		ptr = start;
		while(ptr->next != NULL)
		{
			ptr= ptr->next;
		}
		ptr->next = new_node;
		new_node->next = NULL;
	}
	printf("\n enter the data :");
	scanf("%d",&num);
}
	return start;
}
	
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr != NULL)
	{
		printf("\t %d",ptr->data);
		ptr = ptr->next;
	}
	return start;
}
	


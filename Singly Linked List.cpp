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
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);

int main()
{
	int c;
	do{
		printf("\n\n ****MAIN MENU****");
		printf("\n 1: Create a Linked List");
		printf("\n 2: Display the list");
		printf("\n 3: Insert an element at beginning of the list");
		printf("\n 4: Insert an element at end of the list");
		printf("\n 5: Insert an element before an element of the list");
		printf("\n 6: Insert an element after an element of the list");
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
			case 3: start = insert_beg(start);
			break;
			case 4: start = insert_end(start);
			break;
			case 5: start = insert_before(start); break;
			case 6: start = insert_after(start); break;
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
	
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	printf("\n enter the data :");
	scanf("%d",&num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = start;
	start = new_node;
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n enter the data :");
	scanf("%d",&num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = NULL;
	ptr = start;
	while(ptr->next != NULL)
	ptr= ptr->next;
	ptr->next = new_node;
	return start;
}

struct node *insert_before(struct node *start)
{
	struct node *new_node, *ptr, *preptr;
	int num;
	printf("\n enter the data :");
	scanf("%d",&num);
	int val;
	printf("\n enter the data of the element before which element has to be inserted :");
	scanf("%d",&val);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr= start;
	preptr= ptr;
	while(ptr->data != val)
	{
		preptr = ptr;
		ptr= ptr->next;
	}
	preptr->next = new_node;
	new_node -> next = ptr;
	return start;
}

struct node *insert_after(struct node *start)
{
	struct node *new_node, *ptr, *preptr;
	int num;
	printf("\n enter the data :");
	scanf("%d",&num);
	int val;
	printf("\n enter the data of the element after which element has to be inserted :");
	scanf("%d",&val);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr= start;
	preptr= ptr;
	while(ptr->data != val)
	{
		preptr = ptr;
		ptr= ptr->next;
	}
	preptr->next = new_node;
	new_node -> next = ptr;
	return start;
}

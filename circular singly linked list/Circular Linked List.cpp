#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_list(struct node *);


int main()
{
	int c;
	do{
		printf("\n\n ****MAIN MENU****");
		printf("\n 1: Create a Linked List");
		printf("\n 2: Display the list");
		printf("\n 3: Insert an element at the beginning");
		printf("\n 4: Insert an element at the end");
		printf("\n 5: Delete an element from the beginning");
		printf("\n 6: Delete an element from the end");
		printf("\n 7: Delete the list");
	
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
			case 3: start = insert_beg(start); break;
			case 4: start = insert_end(start); break;
			case 5: start = delete_beg(start); break;
			case 6: start = delete_end(start); break;
			case 7: start = delete_list(start); break;
		
			
		}
	}while(c!=13);
	getch();
	return 0;
}

struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n enter -1 to end");
	printf("\n enter data to be entered");
	scanf("%d",&num);
	while(num!=-1)
	{
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	if(start == NULL)
	{
		new_node -> next = new_node;
		start = new_node;
		}	
	else{
		ptr = start;
		while(ptr->next!=start)
		ptr=ptr->next;
		
		ptr->next=new_node;
		new_node->next=start;
	}
	printf("\n enter data to be entered");
	scanf("%d",&num);
	}
	return start;
}

	
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr->next != start)
	{
		printf("\t %d",ptr->data);
		ptr = ptr->next;
	}
	printf("\t %d",ptr->data);
	return start;
}

struct node *insert_beg(struct node *start)
{ struct node *new_node, *ptr;
int num;
printf("\n enter a number");
scanf("%d",&num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
	ptr = start;
	while(ptr -> next != start)
	ptr = ptr->next;
	
	ptr->next = new_node;
	new_node->next=start;
	start = new_node;
	
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *new_node, *ptr;
int num;
printf("\n enter a number");
scanf("%d",&num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
	ptr = start;
	while(ptr -> next != start)
	ptr = ptr->next;
	
	ptr->next = new_node;
	new_node->next=start;
	
	return start;
}

struct node *delete_beg(struct node *start)
{  struct node *ptr;

	ptr = start;
	while(ptr -> next != start)
	ptr = ptr->next;
	
	ptr->next = start->next;
free(start);
start = ptr->next;	
	return start;
}

struct node *delete_end(struct node *start)
{  struct node *ptr, *preptr;

	ptr = start;
	while(ptr -> next != start)
	{
		preptr = ptr;
		ptr = ptr->next;
	}
	
	preptr->next = ptr->next;
free(ptr);	
	return start;
}

struct node *delete_list(struct node *start)
{  struct node *ptr;

		ptr = start;
		while(ptr->next!= start)
			start = delete_end(start);
			start == NULL;
			
	return start;
} 

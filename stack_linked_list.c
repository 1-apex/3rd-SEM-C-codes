#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

void peek(struct node *q)
{
	if(q == NULL)
	{
		printf("Top of stack = -1\n");
	}
	else
	{
		printf("\nTop of Stack : %d\n", q->data);
	}
	
	if(q == NULL)
	{
		printf("\nNo data present in the stack!!\n");
	}
	else
	{
		printf("\nStack : \n");
		while(q != NULL)
		{
			printf("%d\n", q->data);
			q = q->next;
		}
	}
}

void push(struct node **q, int num)
{
	// insert at beginning logic 

	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	if(p == NULL)
	{
		printf("\nStack is full!! or Stack overflow!!\n");
	}
	{
		p->data = num;
		p->next = *q;
		*q = p;
	}
	peek(*q);
}

void pop(struct node **q)
{
	struct node *r;
	
	if(*q == NULL)
	{
		printf("\nNo data present in stack to pop!!\n");
	}
	else
	{
		r = *q;
		*q = r->next;
		free(r);
	
		peek(*q);
	}
}

void main()
{
	int choice, data, res;
	struct node *top;
	top = NULL;
	
	printf("\nOpeartions : \n");
	printf(" 1. Push \n 2. Pop \n 3. Peek \n 4. Exit \n");
	
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("\nEnter the data to insert in stack : ");
				scanf("%d", &data);
				
				push(&top, data);
				break;
			
			case 2:				
				pop(&top);
				break;
			
			case 3:
				peek(top);
				break;
				
			case 4:
				exit(0);
				break;
			
			default:
			 	printf("Enter a valid option!!\n");
			 	break;
		}
	}
}

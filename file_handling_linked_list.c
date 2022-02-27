#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

void write_file(FILE *fp, struct node *q)
{
	struct node *r;
	r = q;
	if(fp == NULL)
	{
		fp = fopen("linked_list_data.txt", "w");
		
		while(r != NULL)
		{
			fprintf(fp, "%d\t", r->data);
			r = r->next;
		}
	}
	
	else
	{
		fp = fopen("linked_list_data.txt", "a");
		
		printf("\nNew data : \n");		
		while(q->next != NULL)
		{
			fprintf(fp, "%d\t", q->data);
			q = q->next;
		}
	}
	
}

void read_file(FILE *fp)
{
	char s[100];
	fp = fopen("linked_list_data.txt", "r");
	
	fgets(s, 10, fp);
	puts(s);
}	

void display(struct node *q)
{
	if(q == NULL)
	{
		printf("List is empty!\n");
	}
	else
	{
		while(q != NULL)
		{
			printf(" %d \t", q->data);
			q = q->next;
		}
	}
}

void insert_at_beg(struct node **q, int num, FILE *fp)
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	p->data = num;
	p->next = *q;
	*q = p;
	
	display(*q);
}	

void insert_at_end(struct node **q, int num, FILE *fp)
{
	struct node *p, *r;
	r = *q;
	fp = fopen("linked_list_data.txt", "r");
	if(*q == NULL)	
	// if(fp == NULL)
	{
		printf("List is empty!!");
		insert_at_beg(q, num, fp);
	}
	else
	{
		while(r->next != NULL)
		{
			r = r->next;
		}			
		p = (struct node *)malloc(sizeof(struct node));
		p->data = num;
		p->next = r->next;
		r->next = p;
		
		display(*q);
	}
}

void main()
{
	struct node *head;
	FILE *fp;
	int choice, data;
	head = NULL;
	printf(" 1. Insert at beginning \n 2. Insert at end \n 3. Display \n 4. Input into file \n 5. Exit \n");
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("\nEnter the data to insert at beginning : ");
				scanf("%d", &data);
				
				insert_at_beg(&head, data, fp);
				break;
			case 2:
				printf("\nEnter the data to insert at end : ");
				scanf("%d", &data);
				
				insert_at_end(&head, data, fp);
				break;
			case 3:
				display(head);
				read_file(fp);
				break;
			case 4:
				write_file(fp, head);
				break;
			case 5:
				exit(0);
				break;
				
			default:
				printf("Invalid Input!!\n");
				break;
		}
	}
}

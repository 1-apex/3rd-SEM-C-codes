/*
	Pratham
	Program for setting up the shop : " Seller side code "
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct shop
{
	int id;
	char name[20];
	float price;
	float gst;
	int quantity;
	struct shop *next;
};

void display(struct shop *q)
{
	if(q == NULL)
	{
		printf("Shop empty!!\n");
	}
	else
	{
		printf("Your shop : \n");
		printf("ID \t   Name   \t Price   \t Quantity \n");
		while(q != NULL)
		{
			printf("%d \t   ", q->id);
			printf("%s   \t ", q->name);
			printf("%.2f   \t ", q->price);
			printf("%d \n", q->quantity);
			
			q = q->next;
		}
	}
}

void insert_item(struct shop **q)
{
	struct shop *p, *r;
	int id, quantity;
	float price, gst;
	char name[20];
	
	printf("Enter the name of the product : ");
	scanf("%s", name);
	
	printf("Enter the ID for the product : ");
	scanf("%d", &id);
	
	printf("Enter the quantity to store : ");
	scanf("%d", &quantity);
	
	printf("Enter the price or the product : ");
	scanf("%f", &price);
				
	printf("Enter the GST applicable for the product : ");
	scanf("%f", &gst);
	
	// applied the logic of inserting at end
	
	r = *q;
	if(*q == NULL)
	{
		p = (struct shop *)malloc(sizeof(struct shop));
		strcpy(p->name, name);
		p->id = id;
		p->price = price;
		p->gst = gst;
		p->quantity = quantity;
	
		p->next = *q;
		*q = p;
	}
	else
	{
		while(r->next != NULL)
		{
			r = r->next;
		}
		
		p = (struct shop *)malloc(sizeof(struct shop));
		strcpy(p->name, name);
		p->id = id;
		p->price = price;
		p->gst = gst;
		p->quantity = quantity;
	
		p->next = r->next;
		r->next = p;
	}
}

void remove_item(struct shop **q, int data)
{
	struct shop *r, *p;
	int flag = 0, count = 0;
	r = *q;
	p = r;
	
	// count is kept for counting the shop items
	
	if(*q == NULL)
	{
		printf("\nThere are no items in the shop to delete!!\n");	
	}
	else
	{
		if(r->next == NULL)			// if there is only one item or element present in the shop
		{
			*q = NULL;		
		}
		else
		{
			while(r->next != NULL)			// if there are few items present in the shop
			{
				if(r->id == data && count == 0)			// if the item to be removed is the first item from the shop
				{
					*q = r->next;
					free(r);
					break;
				}	
				else if(r->id == data && count != 0)			// general item removal logic
				{
					p->next = r->next;
					free(r);
					break;
				}
				else			// if the item to remove is not found in the shop
				{
					flag = 1; 
				}
				p = r;	
				r = r->next;
				count ++;		
			}
			if(flag == 1)
			{
				printf("Item not found in the shop to delete!!\n");		
			}	
			else
			{
				printf("Item found and removed from the shop!!\n");
			}
		}
	}
}

void main()
{
	struct shop *head;
	int choice, data;
	
	head = NULL;
	
	printf("Operations : \n");
	printf(" 1. Add to shop\n");
	printf(" 2. Remove from shop\n");
	printf(" 3. Display shop list \n");
	printf(" 4. Exit \n");
	
	while(1)
	{
		printf("Enter the choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				insert_item(&head);
				break;
			
			case 2:
				printf("Enter the product ID you want to remove from the shop : ");
				scanf("%d", &data);
				
				remove_item(&head, data);
				break;
			
			case 3:
				display(head);
				break;
				
			case 4:
				exit(0);
				break;
		}
	}
}

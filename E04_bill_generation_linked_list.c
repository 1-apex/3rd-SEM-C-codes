#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct shopping_cart
{
	char name[20];
	float price;
	int quantity;
	struct shopping_cart *next;
};

void display_shopping_cart(struct shopping_cart *q)
{
	if(q == NULL)
	{
		printf("Your cart is empty!!\n");
	}
	else
	{
		printf("\nYour cart : \n");
		printf(" Name   \t Price   \t Quantity \n");

		while(q != NULL)
		{	
			printf(" %s    \t ", q->name);
			printf("%.2f    \t ", q->price);
			printf("%d \n", q->quantity);
			
			q = q->next;
		}
	}
}

void add_to_cart(struct shopping_cart **q)
{
	struct shopping_cart *p, *r;
	int quantity;
	char name[20];
	float price, gst;
	
	r = *q;
	
	printf("Enter name of the product : ");
	scanf("%s", name);
	
	printf("Enter the price of the product : ");
	scanf("%f", &price);
	
	printf("Enter the quantity of the product to buy :");
	scanf("%d", &quantity);
	
	// 15% gst applicable on a single purchase
	gst = price * 0.15;
	
	p = (struct shopping_cart *)malloc(sizeof(struct shopping_cart));		
	strcpy(p->name, name);
	p->quantity = quantity;
	p->price = (quantity * price) + (gst * quantity);
		
	if(*q == NULL)
	{		
		p->next = NULL;
		*q = p;
	}
	else
	{
		while(r->next != NULL)
		{
			r = r->next;
		}
		p->next = NULL;
		r->next = p; 
	}
}

void remove_from_cart(struct shopping_cart **q)
{
	struct shopping_cart *r, *p;
	int flag = 0, count = 0, compare;
	char name[20];
	
	printf("Enter the product name ot remove from cart : ");
	scanf("%s", name);
	
	r = *q;
	p = r;
	
	// count is kept for counting the in cart items
	
	if(*q == NULL)
	{
		printf("\nThere are no items in the shop to delete!!\n");	
	}
	else
	{
		compare = strcmp(name, r->name);
		if(r->next == NULL && compare == 0)			// if there is only one item or element present in the cart
		{
			*q = NULL;		
		}
		else
		{
			while(r->next != NULL)			// if there are few items present in the cart
			{
				compare = strcmp(name, r->name);
				if(compare == 0 && count == 0)			// if the item to be removed is the first item from the cart
				{
					*q = r->next;
					free(r);
					break;
				}	
				else if(compare == 0 && count != 0)			// general item removal logic
				{
					p->next = r->next;
					free(r);
					break;
				}
				else			// if the item to remove is not found in the cart
				{
					flag = 1; 
				}
				p = r;	
				r = r->next;
				count ++;		
			}
			if(flag == 1)
			{
				printf("\nItem not found in the cart to delete!!\n");		
			}	
			else
			{
				printf("\nItem found and removed from the cart!!\n");
			}
		}
	}
}

int bill_generation(struct shopping_cart *q)
{
	int sum = 0;
	if(q == NULL)
	{
		printf("No item in the cart to bill!!\n");
	}
	else
	{
		while(q != NULL)
		{
			sum = sum + q->price;
			q = q->next;
		}
	}
	return sum;
}

void main()
{
	struct shopping_cart *head;
	int choice, data, bill;
	
	head = NULL;
	
	printf("----- Welcome -----\n");
	printf(" 1. Add to cart \n 2. Remove from cart \n 3. Proceed to pay \n 4. Display shopping cart \n 5. Exit");
	
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				add_to_cart(&head);
				break;
			
			case 2:
				remove_from_cart(&head);
				break;
				
			case 3:
				bill = bill_generation(head);
				printf("\nTotal Bill : %d\n", bill);
				break;
				
			case 4:
				display_shopping_cart(head);
				break;
				
			case 5:
				exit(0);
				break;
				
			default : 
				printf("Invalid option selected!!\n");
				break;
		}
	}
}

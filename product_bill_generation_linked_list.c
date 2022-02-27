#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct shopping_list
{
	int id;
	char name[20];
	float price;
	int quantity;
	struct shop *next;
};

struct shop
{
	int id;
	char name[20];
	float price;
	float gst;
	int quantity;
	struct shop *next;
};

// Consumers part code

void display_cart(struct shopping_list *q)
{
	if(q == NULL)
	{
		printf(" Cart Empty!!\n");
	}
	else
	{
		printf("\nYour cart : \n\n");
		printf("ID \t   Name   \t Price   \t Quantity \n");

		while(q != NULL)
		{		
			printf("%d \t   ", q->id);
			printf("%s   \t ", q->name);
			printf("%.2f   \t ", q->price);
			printf("%d \n", q->quantity);
			
			q = q->next;
		}
		printf("\n");
	}
}

void add_to_cart(struct shopping_list **q, struct shop *s, int id, int quantity)
{
	struct shopping_list *p, *r;
	int flag = 0;
	
	p = (struct shopping_list *)malloc(sizeof(struct shopping_list));
	r = *q;
	
	while(s != NULL)
	{
		if(s->id == id && *q == NULL)
		{
			p->id = id;
			strcpy(p->name, s->name);
			p->quantity = quantity;
			p->price = (quantity) * (s->price) + (s->gst);
			p->next = *q;
			*q = p;
			
			break;
		}
		else if(s->id == id)
		{
			while(r->next != NULL)
			{
				r = r->next;
			}
			
			p->id = id;
			strcpy(p->name, (s->name));
			p->quantity = quantity;
			p->price = (quantity) * (s->price) + (s->gst);
			p->next = r->next;
			r->next = p;
			
			break;
		}
		else
		{
			flag = 1;
		}
		s = s->next;
	}
	
	if(flag == 1)
	{
		printf("\nEnter the correct ID of the product!!\n");
	}
	else
	{	
		printf("\nItem added to cart successfully!!\n");
	}
}

void remove_from_cart(struct shopping_list **q, int id)
{
	struct shopping_list *r, *p;
	int flag = 0, count = 0;
	r = *q;
	p = r;
	
	// count is kept for counting the in cart items
	
	if(*q == NULL)
	{
		printf("\nThere are no items in the shop to delete!!\n");	
	}
	else
	{
		if(r->next == NULL)			// if there is only one item or element present in the cart
		{
			*q = NULL;		
		}
		else
		{
			while(r->next != NULL)			// if there are few items present in the cart
			{
				if(r->id == id && count == 0)			// if the item to be removed is the first item from the cart
				{
					*q = r->next;
					free(r);
					break;
				}	
				else if(r->id == id && count != 0)			// general item removal logic
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

int total_bill(struct shopping_list *q)
{
	float sum = 0;
	if(q == NULL)
	{
		printf("Failed! Your cart is empty!!\n");
		return 0;
	}
	else
	{
		while(q != NULL)
		{
			sum = sum + (q->price);		
			q = q->next;
		}
		return sum;
	}
}

// Sellers part code

void display_shop(struct shop *q)
{
	if(q == NULL)
	{
		printf("Shop empty!!\n");
	}
	else
	{
		printf("\nYour shop : \n");
		printf("ID \t   Name   \t Price   \t Quantity \n");
		while(q != NULL)
		{
			printf("%d \t   ", q->id);
			printf("%s   \t ", q->name);
			printf("%.2f   \t ", q->price);
			printf("%d \n", q->quantity);
			
			q = q->next;
		}
		printf("\n");
	}
}

void insert_item_to_shop(struct shop **q)
{
	struct shop *p, *r;
	int id, price, quantity;
	float gst;
	char name[20];
	
	printf("\nEnter the name of the product : ");
	scanf("%s", name);
	
	printf("Enter the ID for the product : ");
	scanf("%d", &id);
	
	printf("Enter the quantity to store : ");
	scanf("%d", &quantity);
	
	printf("Enter the price or the product : ");
	scanf("%d", &price);
				
	gst = price * 0.15;			// applying 15% gst on the retailing price
	printf("As per the price, GST applicable for the product is : %.2f\n", gst);
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

void remove_item_from_shop(struct shop **q, int data)
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
				printf("\nItem not found in the shop to delete!!\n");		
			}	
			else
			{
				printf("\nItem found and removed from the shop!!\n");
			}
		}
	}
}


void main()
{
	struct shopping_list *head;
	struct shop *top;
	int choice, data, id, quantity;
	int option;
	float n;
	
	head = NULL;
	top = NULL;
	
	Label :
	printf("\nWhat should we know you as : \n");
	printf(" 1. Buyer / Consumer \n 2. Seller / Shopkeeper \n 3. Exit \n");
	printf("Enter the option : ");
	scanf("%d", &option);
	
	switch(option)
	{
		case 1:
			printf("\n\n ----- Welcome ----- \n\n");
			
			printf(" Choose a option : \n");
			
			printf(" 1. Add item to shopping list\n");
			printf(" 2. Remove item from the shopping list\n");
			printf(" 3. Display shopping list\n");
			printf(" 4. Display shop\n");
			printf(" 5. Request for the total bill\n");
			printf(" 6. Exit being consumer\n\n");
			
			while(1)
			{
				printf("\nEnter your choice : ");
				scanf("%d", &choice);
				
				switch(choice)
				{
					case 1:
						printf("\nEnter the product ID you want to buy : ");
						scanf("%d", &id);
						
						printf("Enter the quantity to buy : ");
						scanf("%d", &quantity);
						
						add_to_cart(&head, top, id, quantity);
						break;
						
					case 2:
						printf("Enter the product ID you want to remove from the cart : ");
						scanf("%d", &data);

						remove_from_cart(&head, data);
						break;
					
					case 3:
						display_cart(head);
						break;
						
					case 4:
						display_shop(top);
						break;
					
					case 5:
						n = total_bill(head);
						printf("\nTotal Bill Amount = %.2f\n", n);
						break;
					
					case 6:
						goto Label;
						break;	
				}
			}
			break;
			
		case 2:
			printf("\nChoose a option : \n");
			
			printf(" 1. Add to shop\n");
			printf(" 2. Remove from shop\n");
			printf(" 3. Display shop list \n");
			printf(" 4. Exit being seller \n");
			
			while(1)
			{
				printf("\nEnter your choice : ");
				scanf("%d", &choice);
				
				switch(choice)
				{
					case 1:
						insert_item_to_shop(&top);
						break;
					
					case 2:
						printf("Enter the product ID you want to remove from the shop : ");
						scanf("%d", &data);
						
						remove_item_from_shop(&top, data);
						break;
					
					case 3:
						display_shop(top);
						break;
						
					case 4:
						goto Label;
						break;
				}
			}
			break;
		
		case 3:
			printf("\n------ Thank you for visiting ------\n");
			exit(0);
			break;
		
		default:
			printf("\nChoose a valid option!!\n");
			break;
	}
	
}

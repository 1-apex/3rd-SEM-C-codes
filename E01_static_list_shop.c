#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cart
{
	int id;
	char product_name[20];
	float price;
	int quantity;
}c[5];

int count_cart()
{
	int i, count = 0;
	for(i = 0; i < 5; i++)
	{
		if(c[i].id != -1)
		{
			count ++;
		}
	}
	
	return count;
}

void display()
{
	int i, flag = 0;

	for(i = 0; i < 5; i++)
	{
		if(c[i].id != -1)
		{
			flag = 1;
			
			printf("\nYour cart : \n");
			
			printf("ID\tProduct\t\tPrice\t  Quantity\n");
			
			for(i = 0; i < 5; i++)
			{
				if(c[i].id != -1)
				{
					printf("%d\t", c[i].id);
					printf("%s\t\t", c[i].product_name);
					printf("%.2f\t  ", c[i].price);
					printf("%d\n", c[i].quantity);
				}
			}
			printf("\n");
		}
	}
	if(flag == 0)
	{
		printf("Your cart is empty!!\n");
	}		
}

void add_to_cart()
{
	int i, choice, count, flag = 0;
	float price;
	count = count_cart();
	
	for(i = 0; i < 5; i++)
	{
		if(c[i].id == -1)
		{
			printf("Enter the product name : ");
			scanf("%s", c[count].product_name);
			
			printf("Enter the ID of product : ");
			scanf("%d", &c[count].id);
			
			printf("Enter the price of product : ");
			scanf("%f", &price);

			printf("Enter the quantity to buy : ");
			scanf("%d", &c[count].quantity);
		
			c[count].price = (price) * ((float)c[count].quantity);
			
			flag = 0;
			break;
		}
		else
		{
			flag = 1;
		}
	}
	if(flag == 1)
	{
		printf("Your cart is full !\n");
	}
}

void remove_from_cart(int data)
{
	int i, flag = 0;
	char name[20];
		
	for(i = 0; i < 5; i++)
	{
		if(c[i].id == data)
		{
			strcpy(name, c[i].product_name);
			c[i].id = -1;
			flag = 0;
			break;
		}
		else
		{
			flag = 1;
		}
	}
	if(flag == 1)
	{
		printf("\nProduct with that ID isn't present in the cart!!\n");
	}
	else
	{
		printf("\nData deleted from the cart : %d :: %s\n", data, name);
	}
}

void main()
{
	int choice, data, i, flag = 0;
	
	for(i = 0; i < 5; i++)
	{
		c[i].id = -1;
	}
	
	printf("\n----- Welcome -----\n");
	printf(" 1. Add to cart \n 2. Remove from cart \n 3. Display shopping cart \n 4. Exit \n");
	
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				add_to_cart();
				break;
			
			case 2:
				printf("\nEnter the ID of product you want to remove fomr the cart : ");
				scanf("%d", &data);
				
				remove_from_cart(data);
				break;
			
			case 3:
				display();
				break;
			
			case 4:
				exit(0);
				break;
			
			default :
				printf("\nPlease enter a valid choice !!\n");	
				break;
		}
	}
}	

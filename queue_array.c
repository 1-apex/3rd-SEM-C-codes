# include<stdio.h>
# include<stdlib.h>
#define max 5

void display(int *a, int front, int rear)
{
	if(front == -1 || rear == -1)
	{
		printf("Queue is empty!!\n");
	}
	for(int i = front; i <= rear; i++)
	{
		printf("%d\t", a[i]);
	}
}

int enqueue(int *a, int data, int *front, int *rear)
{
	if(*rear == max - 1)
	{
		printf("Queue oveflow !!\n");
	}
	else if(*front == -1 && *rear == -1)
	{
		*front = 0;
		(*rear)++;
		a[*rear] = data;
	}
	else
	{
		(*rear)++;
		a[*rear] = data;
	}
}

void main()
{
	int array[5];
	int front;
	int rear;
	int choice, data, n;
	
	front = -1;
	rear = -1;
	
	printf(" 1. Enqueue \n 2. Display \n 3. Exit \n\n");
	
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("\nEnter the data you want to insert : ");
				scanf("%d", &data);
				
				enqueue(array, data, &front, &rear);
				break;
			
			case 2:
				display(array, front, rear);
				break;
				
			case 3:
				exit(0);
				break;

			default:
				printf("Invalid choice!! \n");
				break;
		}
	}	 
}

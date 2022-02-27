#include<stdio.h>
#include<stdlib.h>
#define max 5

void display(int *a, int front, int rear)
{
	int i;
	printf("\n");
	for(i = 0; i < max; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void enqueue(int *array, int *front, int *rear, int data)
{
	int i, flag = 0;
	
	// for the initial or the first element insertion
	if((*rear) == -1 && (*front) == -1)
	{
		(*front) = 0;
		(*rear) ++;
		array[(*rear)] = data;	
	}
	
	// normal queue logic applied
	else if((*front) <= (*rear))
	{
		if((*rear) == max-1)
		{
			printf("\nQueue is full !!\n");
		}
		else
		{
			(*rear) ++;
			array[(*rear)] = data;
		}
	}
	
	// few elements deleted and rear is at last position 
	if((*rear) == (max - 1) && (*front) > 0)
	{
		(*rear) = 0;			// reinitialize rear to 0
		array[(*rear)] = data;
	}
	else if((*rear) < (*front))
	{
		(*rear) ++;
		array[(*rear)] = data;

		if((*rear) == (*front)-1)		// we cannot collide the front and rear so -1 is used......if we do so then the rear and front will reinitialize to -1
		{
			printf("\nQueue full now !!\n");
		}
	}

	printf("\nFront = %d\n", (*front));
	printf("Rear = %d\n", (*rear));
}

int dequeue(int *array, int *front, int *rear)
{
	int n; 
	
	if((*front) == -1 && (*rear) == -1)
	{
		printf("\nQueue is empty !!\n");
		return 0;
	}

	if((*rear) == (*front))
	{
		n = array[(*front)];
		array[(*front)] = -1;
		
		(*front) = -1;
		(*rear) = -1;
		
		return n;
	}
	else	if(((*front) == (max - 1)) && ((*rear) < (*front)))
	{
		n = array[*front];
		array[*front] = -1;
		(*front) = 0;
		
		return n;
	}
	else
	{
		n = array[(*front)];
		array[(*front)] = -1;
		(*front) ++;
		
		return n;
	}
	
	
	printf("\nFront = %d\n", (*front));
	printf("Rear = %d\n", (*rear));
}

void main()
{
	int array[5];
	int front, rear;
	int choice, data, i, n;
	
	for(i = 0; i < max; i++)
	{
		array[i]= -1;
	}
	
	front = -1;
	rear = -1;
	
	printf("\nOperations : \n");
	printf(" 1. Enqueue \n 2. Dequeue \n 3. Display \n 4. Exit \n");
	
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("\nEnter the data to enqueue : ");
				scanf("%d", &data);
				
				enqueue(array, &front, &rear, data);
				break;
			
			case 2:
				n = dequeue(array, &front, &rear);
				printf("\nData dequeued : %d\n", n);
				break;
			
			case 3:
				display(array, front, rear);
				break;
			
			case 4:
				exit(0);
				break;
			
			default:
				printf("\nEnter a valid chocie!!\n");
				break;	
		}
	}
}

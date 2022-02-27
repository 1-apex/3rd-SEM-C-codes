# include<stdio.h>
# include<stdlib.h>
# define max 5

struct queue
{
	int array[5];
	int front;
	int rear;
};

void display(struct queue *q)
{
	if(q->front == -1 || q->rear == -1)
	{
		printf("Queue is empty!!\n");
	}
	else
	{
		for(int i = q->front; i <= q->rear; i++)
		{
			printf("%d\t", q->array[i]);
		}
	}
}

int enqueue(struct queue *q, int item)
{
	if(q->rear == max - 1)
	{
		printf("\nQueue overflow\n");
	}	
	else
	{
		q->rear++;
		q->array[q->rear] = item;
		if(q->front == -1)
		{
			q->front = 0;
		}
	}
}

int dequeue(struct queue *q)
{
	int data;
	if(q->front == -1)
	{
		printf("No data present to delete!!\n");
	}
	if(q->front == q->rear)
	{
		printf("Reinitialize front and rear!!\n");
		q->front = 0;
		q->rear = 0;
	}
	else
	{
		data = q->array[q->front];
		q->front++;
	}	
	return data;
}

void main()
{
	struct queue q;
	int choice, data, n;
	
	q.front = -1;
	q.rear = -1;
	
	printf(" 1. Enqueue \n 2. Display \n 3. Dequeue \n 4. Exit \n\n");
	
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("\nEnter the data you want to insert : ");
				scanf("%d", &data);
				
				enqueue(&q, data);
				break;
			
			case 2:
				display(&q);
				break;
				
			case 3:
				n = dequeue(&q);
				printf("Data deleted : %d\n", n);
				break;	
		
			case 4:
				exit(0);
				break;

			default:
				printf("Invalid choice!! \n");
				break;
		}
	}	 
}

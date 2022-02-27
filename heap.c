#include<stdio.h>
#include<stdlib.h>

void display(int *array)
{
	int i;
	
	printf("\nArray : ");
	for(i = 1; i < 10; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int counter(int *array)
{
	int i, count = 0;
	
	for(i = 1; i < 10; i++)
	{
		if(array[i] != -1)
		{	
			count++;
		}
		else
		{
			break;
		}
	}
	
	return count;
}

// in insertion of data / element in heap we follow reheap up 

void insert(int *array, int n)
{
	int i, temp, pos, k;
	
	array[0] = 10000000;			// declaring random value for a reason :)
	
	//printf("\n----------------------------------------------------------------");
	
	for(i = 1; i < 10; i++)
	{
		if(array[i] == -1)
		{
			array[i] = n;
			
			if(i == 1)
			{
				printf("\nRoot node !!\n");	
			}
			else
			{
				printf("\nParent node = %d\n", array[i/2]);
				
				if(array[i/2] < array[i])
				{
					while(array[i/2] < array[i])
					{
						printf("\nSwapping the node with parent node for maintaining heap rules !\n");
						printf("\nParent node :: %d\n", array[i/2]);
					
						temp = array[i];
						array[i] = array[i/2];
						array[i/2] = temp;
						
						i = i/2;
					}
					
					if(array[i/2] > array[i])
					{
						printf("\nRight position for the inserted data element !\n");
						break;
					}
				}	
				else if(array[i/2] > array[i])
				{
					printf("\nRight position for the inserted data element !\n");
					break;
				}
			}

			break;
		}
	}
	
	//printf("----------------------------------------------------------------\n");
}

// while deletion of the data / element we follow reheap down

int delete(int *array)
{
	// dd : data deleted
	// c : position return of last element 
	// r : root position
	
	int c, temp, dd, r;
	
	c = counter(array);
	printf("\nNumber of data elements present : %d\n", c);
	
	if(c == 0)
	{
		return 1;
	}
	else
	{
		// for max heap we delete the maximum node 
		dd = array[1];
		array[1] = -1;
		
		// swapping the last node with the root node
		printf("\nLast node : %d\n", array[c]);
		temp = array[1];
		array[1] = array[c];
		array[c] = temp;
		
		printf("\nArray now : ");
		display(array);
		
		// logic for reheap down
		// checking the child nodes
		// child 1: 2r+1
		// child 2: 2r+2
		
		r = 1;

		if(array[(2*r) + 1] > array[(2*r) + 2] && array[1] < array[(2*r) + 1])
		{
			temp = array[1];
			array[1] = array[(2*r) + 1];
			array[(2*r) + 1] = temp;
		}
		else if(array[(2*r) + 1] < array[(2*r) + 2] && array[1] < array[(2*r) + 2])
		{
			temp = array[1];
			array[1] = array[(2*r) + 2];
			array[(2*r) + 2] = temp;
		}
		
		r = 1;
		
		// checking the heap property
		if(array[r] < array[(2*r) + 1] || array[r] < array[(2*r) + 2])
		{
			printf("\nHeap property is not followed !\n");
		}
		return dd;
	}
}

void main()
{
	int array[10];
	int n, choice, data, i, d;
	
	for(i = 0; i < 10; i++)
	{
		array[i] = -1;
	}
	
	printf(" 1. Insert \n 2. Delete \n 3. Display \n 4. Exit \n");
	
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("\nEnter the data to insert : ");
				scanf("%d", &data);
				
				insert(array, data);
				break;
				
			case 2:
				d = delete(array);
				
				if(d == 1)
				{
					printf("\nNo data present in heap to delete !\n");
				}
				else
				{
					printf("\nData : %d : Deleted successfully\n", d);
				}
				break;
				
			case 3:
				display(array);
				break;
				
			case 4:
				exit(0);
				break;
		}
	}
}

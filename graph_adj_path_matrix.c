#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i, j, k, n, flag = 0;
	
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	
	int adj_matrix[n][n];
	int path_matrix[n][n];
	
// ADJACENCY MATRIX

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("\nEnter the node status for nodes :: %d and %d : ", i, j);
			scanf("%d", &adj_matrix[i][j]);
		}
	}
	
	// printing the adjacency matrix
	printf("\nAdjacency Matrix : \n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ", adj_matrix[i][j]);
		}
		printf("\n");
	}

// PATH MATRIX
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(k = 0; k < n; k++)
			{
				if(i==j)
				{
					path_matrix[i][j] = 1;
				}
				else if(adj_matrix[i][j] == 1)
				{
					path_matrix[i][j] = 1;				
				}
				else if(adj_matrix[i][k] == 1 && adj_matrix[k][j] == 1)
				{
					path_matrix[i][j] =  1;
				}
				/*
				else
				{
					path_matrix[i][j] = 0;	
				}
				*/
			}
		}
	}
	
	// printing the path matrix
	printf("\nPath Matrix : \n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ", path_matrix[i][j]);
		}
		printf("\n");
	}
}

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i, j, k, n, flag = 0, c;
	
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	
	int adj_matrix[n][n];
	
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
	
	// checking the connected and non connected nodes

	printf("\nEnter the node to check the connected and not connected nodes : ");
	scanf("%d", &c);
	
	printf("\nConected nodes : ");
	i = c;
	for(j = 0; j < n; j++)
	{
		if(adj_matrix[i][j] == 1)
		{
			printf("%d ", j+1);
		}
	}
	
	printf("\nNot connected nodes : ");
	i = c;
	for(j = 0; j < n; j++)
	{
		if(adj_matrix[i][j] == 0)
		{
			printf("%d ", j+1);
		}
	}
}

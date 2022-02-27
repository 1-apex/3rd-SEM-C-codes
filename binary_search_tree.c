#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *left;
	int data;
	struct node *right;
};

int search_node(struct node *r, int data)
{
	if(r == NULL)
	{
		// tree is empty
		return 0;
	}
	else
	{
		if(data == (r->data))
		{
			printf("Data present ! \n");
			return 1;
		}
		else if(data >= (r->data))
		{
			r = r->right;
			search_node(r, data);
		}
		else if(data < (r->data))
		{
			r = r->left;
			search_node(r, data);
		}
		else
		{
			return 0;
		}
	}
}

void add_node(struct node **root, int item)
{
	struct node *p, *r;
	r = *root;
	
	p = (struct node *)malloc(sizeof(struct node));
	p->data = item;
	p->left = NULL;
	p->right = NULL;

	if(*root == NULL)
	{
		printf("Data inserted at the root : %d\n", item);
		*root = p;
	}
	else
	{
		if(item >= (r->data))
		{
			if((r->right) == NULL)
			{
				printf("\nParent node : %d\n", r->data);
				r->right = p;				
				printf("\nData inserted right : %d\n", item);
			}
			else
			{
				printf("\nParent node : %d\n", r->data);
				r = r->right;
				
				add_node(&r, item);
			}
		}
		else if(item < (r->data))
		{
			if((r->left) == NULL)
			{
				printf("\nParent node : %d\n", r->data);
				r->left = p;
				printf("\nData inserted left : %d\n", item);
			}
			else
			{
				printf("\nParent node : %d\n", r->data);
				r = r->left;
				
				add_node(&r, item);
			}
		}
	}
}

void delete_node(struct node **root, int data)
{
	int search, flag, max, min;
	struct node *r;
	struct node *current_node, *parent_node;
	
	r = *root;
	parent_node = NULL;
	current_node = *root;
	
	search = search_node(*root, data);

	if(search == 0)
	{
		printf("Data not found in the tree !! \n");
	}
	else
	{
		// only root node with no child logic
		if((*root)->left == NULL && (*root)->right == NULL && (*root)->data == data)
		{
			current_node = *root;
			*root = NULL;
			free(current_node);
		}
		
		// root node with left subtree
		// getting the max value data from the left subtree
		if((*root)->left != NULL && (*root)->data == data)
		{
			parent_node = *root;
			current_node = (*root)->left;
			max = current_node->data;
			
			printf("Max start = %d", max);
				
			if(current_node->right != NULL)
			{
				while(current_node->right != NULL)
				{
					parent_node = current_node;
					current_node = current_node->right;
				}
				max = current_node->data;
				printf("Max now = %d", max);
				parent_node->right = NULL;
			}
			(*root)->data = max;
		}
		
		// leaf node logic
		while(current_node->data != data)
		{
			if(data < (current_node->data))
			{
				parent_node = current_node;
				current_node = parent_node->left;
				flag = 0;
			}
			else if(data >= (current_node->data))
			{
				parent_node = current_node;
				current_node = parent_node->right;
				flag = 1;
			}
		}
		if((current_node->left) == NULL && (current_node->right) == NULL && flag == 0)
		{
			parent_node->left = NULL;
			free(current_node);
		}
		else if((current_node->left) == NULL && (current_node->right) == NULL && flag == 1)
		{
			parent_node->right = NULL;
			free(current_node);
		}
		
		// internal node logic
		
		// internal node has one child at left and that child has no subtree present
		else if((current_node->left) != NULL && (current_node->right) == NULL && flag == 0)
		{
			current_node->data = current_node->left->data;
			free(current_node->left);
		}
		
		// internal node has one child at right and that child has no subtree present
		else if((current_node->left) == NULL && (current_node->right) != NULL && flag == 0)
		{
			current_node->data = current_node->right->data;
			free(current_node->right);
		}
	}
}

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", (root->data));
        preorder((root->left));
        preorder((root->right));
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder((root->left));
        postorder((root->right));
        printf("%d ", (root->data));
    }
}

void main()
{
	struct node *root;
	int choice, data, a;
	
	root = NULL;
	
	printf("\nOperations : \n");
	printf(" 1. Add a node \n 2. Delete a node \n 3. Inorder \n 4. Exit \n");
	
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the data to insert : ");
				scanf("%d", &data);
				
				add_node(&root, data);
				break;
			
			case 2:
				printf("Enter the data you want to delete : ");
				scanf("%d", &data);
				
				delete_node(&root, data);
				break;
			
			case 3:
				if(root == NULL)
				{
					printf("Tree is empty !!\n");
				}
				else
				{
					printf(" Inorder : ");
					inorder(root);
					printf("\n Preorder :");
					preorder(root);
					printf("\n Postorder :");
					postorder(root);
				}
				break;
			
			case 4:
				exit(0);
				break;
		}
	}
}

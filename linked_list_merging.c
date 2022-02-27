#include<stdio.h>
#include<stdlib.h>

struct node1            //declaring the list 1
{
    int data1;
    struct node1 *next1;
};

struct node2            //declaring the list 2
{
    int data2;
    struct node2 *next2;
};

struct merging_node         //declaring the merging list
{
    int data_m;
    struct merging_node *next_m;
};

//function declaration for displaying the list 1
void display_list1(struct node1 *q1)            
{
    if(q1 == NULL)          //checking whether the list is empty or not
    {
        printf("List is empty!\n");
    }
    else
    {
        while (q1 != NULL)          //loop until the last node->next == NULL
        {
            printf("%d\n", q1->data1);          //printing the data
            q1 = q1->next1;         //incrementing the q1 or shifting to next node
        }
    }
}

//function declaration for displaying the list 2
void display_list2(struct node2 *q2)
{
    if(q2 == NULL)          //checking whether the list is empty or not
    {
        printf("List is empty!\n");
    }
    else
    {
        while (q2 != NULL)          //loop until the last node->next == NULL
        {
            printf("%d\n", q2->data2);          //printing the data
            q2 = q2->next2;         //incrementing the q2 or shifting to next node
        }
    }
}

//function declaration for displaying the merged list 
void display_merged_list(struct merging_node *p_m)
{
    if (p_m == NULL)          //checking whether the list is empty or not
    {
        printf("No data in the lists to merge!");
    }
    else
    {
        while (p_m != NULL)          //loop until the last node->next == NULL
            {
                printf("%d\n", p_m->data_m);          //printing the data
                p_m = p_m->next_m;         //incrementing the q2 or shifting to next node
            }
    }
}

//inserting the elements in list 1
void element_list1(struct node1 **q1, int num)
{
    if (*q1 == NULL)            //checking if the list is null
    {    
        struct node1 *p;
        p = (struct node1 *)malloc(sizeof(struct node1));           //creating the new node 
        p->data1 = num;         //storing the data 
        p->next1 = NULL;            //storing the null in next     
        *q1 = p;            //storing the address of new node to head
    }
    else
    {
        struct node1 *p, *r;
        r = *q1;            //storing the head in r
        while (r->next1 != NULL)            //traversing till the last node filled   
        {
            r = r->next1;
        }
        p =  (struct node1 *)malloc(sizeof(struct node1));          //creating the new node
        p->data1 = num;         //storing the data
        p->next1 = r->next1;            //storing the NULL of previous node to the new node->next
        r->next1 = p;           //storing the address of new node to the previous node
    }
    display_list1(*q1);
}

//
void element_list2(struct node2 **q2, int num)
{
    if (*q2 == NULL)
    {    
        struct node2 *p;
        p = (struct node2 *)malloc(sizeof(struct node2));

        p->data2 = num;
        p->next2 = NULL;
        *q2 = p;
    }
    else
    {
        struct node2 *p, *r;
        r = *q2;
        while (r->next2 != NULL)   
        {
            r = r->next2;
        }
        p =  (struct node2 *)malloc(sizeof(struct node2));
        p->data2 = num;
        p->next2 = r->next2;
        r->next2 = p;
    }
    display_list2(*q2);
}

void merge_lists(struct merging_node **q_m, struct node1 *q1, struct node2 *q2)
{
    struct merging_node *p_m, *r_m;
    r_m = *q_m;

    while (q1 != NULL && q2 != NULL)
    {
        if (r_m == NULL)            //checking if list is empty
        {
            r_m = (struct merging_node *)malloc(sizeof(struct merging_node));           //allocating memory 
            p_m = r_m;          //storing the    
        }
        else
        {
            p_m->next_m = (struct merging_node *)malloc(sizeof(struct merging_node));
            p_m = p_m->next_m;
		}
        if (q1->data1 > q2->data2)
        {
            p_m->data_m = q2->data2;
            q2 = q2->next2;
        }
        else if(q1->data1 < q2->data2)
        {
            p_m->data_m = q1->data1;
            q1 = q1->next1;
        }
        else
        {
            p_m->data_m = q1->data1;
            q1 = q1->next1;
            q2 = q2->next2;
        }
    }
    
    while(q1 != NULL)
    {
    	p_m->next_m = (struct merging_node *)malloc(sizeof(struct merging_node));
    	p_m = p_m->next_m;
    	p_m->data_m = q1->data1;
    	q1 = q1->next1;
	}
    while(q2 != NULL)
    {
    	p_m->next_m = (struct merging_node *)malloc(sizeof(struct merging_node));
    	p_m = p_m->next_m;
    	p_m->data_m = q2->data2;
    	q2 = q2->next2;
	}
	p_m->next_m = NULL;
    display_merged_list(r_m);
}

int main()
{
    int choice, data;
    struct node1 *head1;
    struct node2 *head2;
    struct merging_node *head_m;
    head_m = NULL;
    head1 = NULL;
    head2 = NULL;

    printf("Options : \n");
    printf(" 1. Enter the elements of LIST 1\n 2. Display the LIST 1\n 3. Enter the elements of LIST 2\n 4. Display the LIST 2\n 5. Merge Lists and Display\n");
    while(1)
    {    
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:         //inserting the data in LIST 1
            printf("Enter the element : ");
            scanf("%d", &data);

            element_list1(&head1, data);
            break;
        
        case 2:         //displaying the LIST 1 data
            display_list1(head1);
            break;

        case 3:         //inserting the data in LIST 2
            printf("Enter the element : ");
            scanf("%d", &data);

            element_list2(&head2, data);
            break;
        
        case 4:         //displaying the LIST 2 data
            display_list2(head2);
            break;

        case 5:         //merging the two linked list
            merge_lists(&head_m, head1, head2);
            break;

        case 6:
            exit(0);

        default:
            printf("Please enter a valid choice.\n");
            break;
        }
    }
}

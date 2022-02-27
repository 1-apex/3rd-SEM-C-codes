#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// display function
void display(struct node *q)
{
    struct node *r;
    r = q;
    if (r == NULL)
    {
        printf("\nList is empty!!\n");
    }
    else
    {
        while (r != q)
        {
            printf("%d\n", r->data);
            r = r->next;
        }
    }   
}

// insert data at the beginning of the circular list
void insert_at_beg(struct node **q, int num)
{
    struct node *p, *r;
    r = *q;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = num;
    p->next = *q;
    while (r->next != *q)
    {
        r = r->next;
    }
    r->next = p;
    *q = p;

    display(*q);
}

void main()
{
    struct node *head;
    int choice, data;
    head = NULL;

    printf("Operations : \n");
    printf("1. Insert at beginning \n 2. Display \n 3. Exit \n");

    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data to insert at beginning : ");
            scanf("%d", &data);

            insert_at_beg(&head, data);
            break;

        case 2:
            display(head);
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("\nEnter a valid option!!\n");
            break;
        }
    }
}
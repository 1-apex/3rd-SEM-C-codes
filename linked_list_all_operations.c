/*
Prathamesh Patil
Program : C Code for Linked List all operations
*/

#include <stdio.h>
#include <stdlib.h>

// declaring a struct node
struct node
{
    int data;
    struct node *next;
};

// display list function declaration
void display_list(struct node *p)
{
    if (p == NULL) // checking whether the list is empty of not
    {
        printf("\nList is empty!!\n"); // if empty printing "empty list"
    }
    else
    {
        while (p != NULL) // lopp until p==NULL
        {
            printf("%d\n", p->data); // printing the data from the node
            p = p->next;             // pointing to the next node
        }
    }
}

// counting the list elements
int counter_list(struct node *q)
{
    int count = 0;
    while (q != NULL)
    {
        count++;
        q = q->next;
    }
    //printf("Count of elements : %d\n", count);
    return count;
}

// insert at beginning function declartion
void insert_at_beg(struct node **q, int num)
{
    struct node *p;                                 // declaring the new variable (pointer to structure) for new node : p
    p = (struct node *)malloc(sizeof(struct node)); // allocating the memory to p node
    p->data = num;                                  // assigning the value num for the data of new node
    p->next = *q;                                   //*p was first NULL ...... so passing the NULL to the next of new node
    *q = p;                                         //*q i.e head ...... giving it the address of new node

    display_list(*q);
}

// insert at ending of list function declaration
void insert_at_end(struct node **q, int num)
{
    struct node *p, *r; // declaring two pointers
    if (*q == NULL)     // checking if head i.e *q is NULL ....... means the list is empty(no nodes present)
    {
        // functtion called :-  insert_at_beg(*q, num);

        struct node *p;                                 // declaring the new variable (pointer to structure) for new node : p
        p = (struct node *)malloc(sizeof(struct node)); // allocating the memory to p node
        p->data = num;                                  // assigning the value num for the data of new node
        p->next = *q;                                   //*p was first NULL ...... so passing the NULL to the next of new node
        *q = p;                                         //*p i.e head ...... giving it the address of new node

        
    }
    else
    {
        r = *q;                 // giving the head value to the r pointer variable
        while (r->next != NULL) // running the loop until NULL occurs
        {
            r = r->next; // storing the last value or address in r
        }
        p = (struct node *)malloc(sizeof(struct node)); // allocating memory for the new node
        p->data = num;                                  // assgining the value num for the data of new node
        p->next = NULL;                                 // as it is at end....pointing the node to NULL or we can also pass the r->next value as it contains NULL 
        r->next = p;                                    // last value gets changed to/ points to p(new node)
    }

    display_list(*q);
}

// insert at a specific position of list
void insert_at(struct node **q, int num, int position)
{
    int count = 1, total_elements;
    struct node *r;
    total_elements = counter_list(*q);

    if (position == 1)
    {
        // code of insert_at_beginning

        struct node *p;
        p = (struct node *)malloc(sizeof(struct node));
        p->data = num;
        p->next = *q;
        *q = p;

        display_list(*q);
    }
    else if (position < total_elements)
    {
        r = *q;
        while (count != position - 1)
        {
            count++;     // this counter will help to traverse to the position
            r = r->next; // this will store the address of the previous node of position
        }
        struct node *p;                                 // declaration of new node
        p = (struct node *)malloc(sizeof(struct node)); // allocating the memory for new node p
        p->data = num;                                  // assigning the value num for the data of new node
        p->next = r->next;                              // storing the address of the next node to the new node
        r->next = p;                                    // passing the address of new node to the previous node of position
        
        display_list(*q);
    }
    else if (position == (total_elements+1))
    {
        insert_at_end(q, num);
    }
    else
    {
        printf("\nPlease enter a valid position !!\n");
    }
}

// insert after a specified position in the list
void insert_after(struct node **q, int position)
{
    int count = 1, data;
    struct node *r;
    int total_elements;
    total_elements = counter_list(*q);
    r = *q;
    printf("\nEnter the data to insert after : ");
    scanf("%d", &data);

    if (r == NULL)
    {
        printf("\nAdding data to the first position, as list is empty.\n");
        // code of insert_at_beginning

        struct node *p;
        p = (struct node *)malloc(sizeof(struct node));
        p->data = data;
        p->next = *q;
        *q = p;
    
        display_list(*q);
    }
    else
    {
        if (position > total_elements)
        {
            printf("\nEnter a valid position!!\n");
        }
        else
        {
            while (count != position)
            {
                r = r->next;
                count++;
            }
            if (r->next == NULL)
            {
                insert_at_end(q, data);
            }
            else
            {
                struct node *p;
                p = (struct node *)malloc(sizeof(struct node));
                p->data = data;
                p->next = r->next;
                r->next = p;

                display_list(*q);
            }
        }
    }
}

// insert before a specified position in the list
void insert_before(struct node **q, int position)
{
    int count = 1, data;
    struct node *r;
    r = *q;
    printf("\nEnter the data to insert before : ");
    scanf("%d", &data);
    int total_elements = counter_list(*q);

    if (r == NULL)
    {
        printf("\nAdding data to the first position, as list is empty.\n");
        // code of insert_at_beginning

        struct node *p;
        p = (struct node *)malloc(sizeof(struct node));
        p->data = data;
        p->next = *q;
        *q = p;
        
        display_list(*q);
    }
    else
    {
        if (position == 1)
        {
            insert_at_beg(q, data);
        }
        else if (position > total_elements)
        {
            printf("\nLess elements present in the list!!\n");
            printf("Please enter a valid position!!\n");
        }
        else
        {
            while (count != (position-1))
            {
                r = r->next;
                count++;
            }
            struct node *p;
            p = (struct node *)malloc(sizeof(struct node));
            p->data = data;
            p->next = r->next;
            r->next = p;

            display_list(*q);
        }
    }
}

// inserting data after the specific data in the list
void insert_after_data(struct node **q)
{
    int data_traverse, data_input, count = 0, flag = 0;
    struct node *p;
    printf("\nEnter the data (traverse) : ");
    scanf("%d", &data_traverse);

    p = *q;

    if (p == NULL)
    {
        display_list(*q);
    }
    else
    {
        while (p != NULL)
        {
            if (p->data == data_traverse)
            {
                
                if (p->next == NULL)
                {   
                    printf("\nEnter the data to input after the data %d : ", data_traverse);
                    scanf("%d", &data_input);
                    insert_at_end(q, data_input);
                }
                else
                {
                    insert_after(q, count+1);
                }
                flag = 1;
            }
            count ++;
            p = p->next;   
        }
    }
    if (flag == 0)
    {
        printf("\nData not found in the list for performing insert after!!\n");
    }
}

// inserting data before the specific data in the list
void insert_before_data(struct node **q)
{
    int data_traverse, data_input, count = 0, flag = 0;
    struct node *p;
    printf("\nEnter the data (traverse) : ");
    scanf("%d", &data_traverse);

    p = *q;

    if (p == NULL)
    {
        display_list(*q);
    }
    else
    {
        while (p != NULL)
        {
            if (p->data == data_traverse)
            {
                if (count == 0)
                {
                    printf("\nEnter the data to input before the data %d : ", data_traverse);
                    scanf("%d", &data_input);
                    insert_at_beg(q, data_input);
                }
                else
                {
                    insert_before(q, count+1);
                }
                flag = 1;
            }
            count ++;
            p = p->next;   
        }
    }
    if (flag == 0)
    {
        printf("\nData not found in the list for performing insert before!!\n");
    }
}

// deleting the data at beginning in the list
void delete_at_beg(struct node **q)
{
    struct node *r;
    r = *q; // storing address of head in variable r

    if (r == NULL) // checking whether head contain NULL (i.e list is empty)
    {
        printf("\nNo data to delete!\n");
    }
    else
    {
        *q = r->next; // storing the next node(second node) value to head
        free(r);      // free or delete r (i.e first node)
    }
    display_list(*q);
}

// deleting the data at end in the list
void delete_at_end(struct node **q)
{
    struct node *r, *s;

    if (*q == NULL) // checking whether the list is empty or not
    {
        printf("\nNo data to delete!\n");
    }
    else
    {
        s = *q;                 // storing head in the s variable
        while (s->next != NULL) // running the loop until we reach null
        {
            r = s;       // storing the last second node in r variable
            s = s->next; // incrementing the s to next node
        }
        r->next = NULL; // storing NULL to the second last node->next
        free(s);        // free or delete the last node s
    }
    display_list(*q);
}

// deleting the data at the specified position
void delete_at_pos(struct node **q, int position)
{
    struct node *p, *r;
    int total_elements, count = 1;
    r = *q;
    total_elements = counter_list(*q);
    if (*q == NULL)
    {
        printf("\nNo data to delete!\n");
    }
    else
    {
        if (position > total_elements)
        {
            printf("\nLess elements are present!\n");
        }
        else
        {
            while (count != position)
            {
                p = r;
                r = r->next;
                count++;
            }
            p->next = r->next;
            free(r);
        }
    }
    display_list(*q);
}

// deleting the data after the specified position
void delete_after_pos(struct node **q, int position)
{
    struct node *r, *p;
    int total_elements, count = 0;
    r = *q;
    total_elements = counter_list(*q);

    if (r == NULL) // checking whether the list is empty or not
    {
        printf("\nNo data to delete!\n");
    }
    else
    {
        if (position > total_elements)
        {
            printf("\nLess elements presnt in the list!!\n");
        }
        else if (position == total_elements)
        {
            printf("\nEntered position is the last element!!\n");
            printf("No data available to delete !!\n");
        }
        else
        {
            while (count != position-1) // traversing till the position == count
            {
                p = r;       // storing the last second node's of position address to p
                count++;     // incrementing count by 1
                r = r->next; // increment or traversing to the next node
            }
            p->next = r->next; // storing the address of next node to the previous node of deletinh node
            free(r);           // free or delete the last node r
        }
    }
    display_list(*q);
}

// deleting the data before the specified position
void delete_before_pos(struct node **q, int position)
{
    struct node *r, *p;
    int total_elements, count = 0;
    r = *q;
    total_elements = counter_list(*q);

    if (r == NULL) // checking whether the list is empty or not
    {
        printf("No data to delete!\n");
    }
    else
    {
        if (position > total_elements)
        {
            printf("\nLess elements presnt in the list!!\n");
        }
        else
        {
            if (position == 1)
            {
                printf("\nEntered position is the first element!!\n");
                printf("No data available to delete !!\n");
            }
            else if (position == 2)
            {
                delete_at_beg(q);
            }
            else
            {
                while (count != position - 2) // traversing till the position == count
                {
                    p = r;       // storing the last second node's of position address to p
                    r = r->next; // increment or traversing to the next node
                    count++;     // incrementing count by 1
                }
                p->next = r->next; // storing the address of next node to the previous node of deleting node
                free(r);           // free or delete the last node r
            
                display_list(*q);
            }
        }
    }
}

// deleting the data using the user input data
void delete_using_data(struct node **q)
{
    struct node *r;
    int data, flag = 0, count = 0;
    printf("Enter the data to delete : ");
    scanf("%d", &data);

    r = *q;
    if (*q == NULL)
    {
        printf("\nList is already empty!!\n");
    }
    else
    {
        while (r != NULL)
        {
            if (r->data == data)
            {
                delete_at_pos(q, count+1);
                flag = 1;
                break;
            }
            count ++;
            r = r->next;
        }
    }
    if (flag == 0)
    {
        printf("\nData not found in the list for performing delete operation!!\n");
    }
    
} 

// deleting the data before the specified data in the list
void delete_before_specific_data(struct node **q)
{
    int data, count = 0, flag = 0;          //data is for traversing the list
    struct node *p;
    printf("Enter the data to delete data before it : ");
    scanf("%d", &data);

    p = *q;
    if (p == NULL)
    {
        printf("\nNo data to delete.....as ");
        display_list(*q);
    }
    else
    {
        while (p != NULL)
        {
            if (p->data == data)
            {
                if (count == 0)
                {
                    printf("\nNo data present before to delete as its first element in list!!\n");
                }
                else
                {
                    delete_at_pos(q, count);
                }
                flag = 1;
            }
            count ++;
            p = p->next;   
        }
    }
    if (flag == 0)
    {
        printf("\nData not found in the list for performing delete before!!\n");
    }
}

// deleting the data after the specified data in the list
void delete_after_specific_data(struct node **q)
{
    int data, count = 0, flag = 0;
    struct node *p;
    printf("Enter the data to delete data after it : ");
    scanf("%d", &data);

    p = *q;
    if (p == NULL)
    {
        printf("\nNo data to delete.....as ");
        display_list(*q);
    }
    else
    {
        while (p != NULL)
        {
            if (p->data == data)
            {
                delete_at_pos(q, count+2);
                flag = 1;
            }
            count ++;
            p = p->next;   
        }
    }
    if (flag == 0)
    {
        printf("Data not found in the list for performing delete after!!\n");
    }
}

//delete all data from the list
void delete_all(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is already empty!!\n");
    }
    else
    {
        *q = NULL;          // declaring the head NULL so that the link breaks of the list
        printf("\nDeleted all data from the list!\n");
        // ask sir about this logic

        // while (r->next != NULL)
        // {
        //     free(r);
        //     r = r->next;
        // }
    }
}

// searching the data using the position in the list
void search_by_pos(struct node *q, int position)
{
    int count = 0;

    if (q == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        while (count != position - 1)
        {
            q = q->next;
            count++;
        }
        if (q == NULL)
        {
            printf("Less elements present!\n");
        }
        else
        {
            printf("Data at position %d = %d\n", position, q->data);
        }
    }
}

// searching the data
void search_by_data(struct node *q, int num)
{
    int count = 1;
    int flag = 0;
    while (flag == 0)
    {
        if (q->data == num)
        {
            printf("Data %d fount at : %d position\n", num, count);
            flag = 1;
        }
        else
        {
            count++;
            q = q->next;
        }
    }
}

// counting the repitition of the data in the list
void data_frequency(struct node *q)
{
    int count = 0, data;
    printf("Enter the data to check its frequency : ");
    scanf("%d", &data);

    while (q != NULL)
    {
        if (q->data == data)
        {
            count ++;           
        }
        q = q->next;
    }
    printf("\nFrequency of the data %d : %d\n", data, count);
}

// searching the max data in the list
int max_data(struct node *q)
{
    int max;
    max = q->data;
    while (q != NULL)
    {
        if (max < q->data)
        {
            max = q->data;
        }
        q = q->next;
    }
    return max;
}

// searching the min data in the list
int min_data(struct node *q)
{
    int min;
    min = q->data;
    while (q != NULL)
    {
        if (min > q->data)
        {
            min = q->data;
        }
        q = q->next;
    }
    return min;
}

// sorting the list in ascending order
void ascending(struct node **q)
{
    struct node *r, *p;
    int temp;
    r = *q;         // assigning the value of head to r
    while (r->next != NULL)         // loop 1: for considering a single element from list
    {
        p = r;          // assgning the value of r to p
        while (p != NULL)           // loop 2: for comparing the remaining elements from the list to the element that we got from loop 1
        {
            if (r->data >= p->data)         // if greater we use the swap logic
            {
                temp = r->data;            
                r->data = p->data;         
                p->data = temp;            
            }
            p = p->next;            // incrementing the p for the while loop 2
        }
        r = r->next;            // incrementing the r for the while loop 1
    }
    display_list(*q);
}

// sorting the list in decsending order
void descending(struct node **q)
{
    struct node *r, *p;
    int temp;
    r = *q;         // assigning the value of head to r
    while (r->next != NULL)         // loop 1: for considering a single element from list
    {
        p = r;          // assgning the value of r to p
        while (p != NULL)           // loop 2: for comparing the remaining elements from the list to the element that we got from loop 1
        {
            if (r->data <= p->data)         // if greater we use the swap logic
            {
                temp = r->data;            
                r->data = p->data;         
                p->data = temp;            
            }
            p = p->next;            // incrementing the p for the while loop 2
        }
        r = r->next;            // incrementing the r for the while loop 1
    }
    display_list(*q);
}

// sorting the list data 
void sort_list(struct node **q)
{
    struct node *r;
    int sorting_option;
    r = *q;

    if (r == NULL)
    {
        printf("\nList is empty!!\n");
    }
    else
    {
        printf("\nChoose the sorting you wanna perform of the list : \n");
        printf(" 1. Ascending \n 2. Descending \n");
        
        printf("\nEnter your sorting_option : ");
        scanf("%d", &sorting_option);

        if (sorting_option == 1)
        {
            ascending(q);
        }
        else if (sorting_option == 2)
        {
            descending(q);
        }
        else
        {
            printf("\nPlease Enter a valid sorting_option!\n");
        }
    }
}

// main body
int main()
{
    struct node *head; // declaring the head for the list
    head = NULL;
    int data;
    int choice, position, total_elements, max, min;
    
    printf("--------------------------------------------------------------------\n");
    printf("       Sr.No. \t Operation \n");
    printf("--------------------------------------------------------------------\n");
    printf(" \t 1 \tInsert at beginning \n \t 2 \tInsert at end \n \t 3 \tInsert at \n \t 4 \tInsert after \n \t 5 \tInsert before \n");
    printf(" \t 6 \tInsert after specific node data\n \t 7 \tInsert before specific node data \n");
    printf(" \t 8 \tvDelete at beginning \n \t 9 \tDelete at end \n \t 10 \tDelete at \n  \t 11 \tDelete after \n  \t 12 \tDelete before \n");
    printf("  \t 13 \tDelete specific value \n  \t 14 \tDelete before specfic data \n  \t 15 \tDelete after specific data \n  \t 16 \tDelete all data \n");
    printf("  \t 17 \tSearch by position \n  \t 18 \tSearch by data \n  \t 19 \tCount the list elements \n  \t 20 \tFrequency of data \n  \t 21 \tFind maximum \n  \t 22 \tFind minimum \n");
    printf("  \t 23 \tSort \n  \t 24 \tDisplay list \n  \t 25 \tExit \n");

    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // inserting data at beginning
            printf("Enter the data to insert at beginning : ");
            scanf("%d", &data);

            insert_at_beg(&head, data); // passing the "address of head" and the "data" to function
            break;

        case 2: // inserting at the end
            printf("Enter the data to insert at end : ");
            scanf("%d", &data);

            insert_at_end(&head, data);
            break;

        case 3: // inserting at the specified location
            printf("Enter the position to insert : ");
            scanf("%d", &position);

            printf("Enter the data to insert : ");
            scanf("%d", &data);

            insert_at(&head, data, position);
            break;

        case 4: // inserting after a specific position
            printf("Enter the position to insert after : ");
            scanf("%d", &position);
            
            insert_after(&head, position);
            break;

        case 5: // inserting before the specified position
            printf("Enter the position to insert before : ");
            scanf("%d", &position);

            insert_before(&head, position);
            break;

        case 6: // inserting data after the specific data in the list
            insert_after_data(&head);
            break;

        case 7: // inserting data before the specific data in the list
            insert_before_data(&head);
            break;

        case 8: // deleting data at the beginning
            delete_at_beg(&head);
            break;

        case 9: // deleting data at the end
            delete_at_end(&head);
            break;

        case 10: // deleting data at a specified position
            printf("Enter the position to delete data : ");
            scanf("%d", &position);

            delete_at_pos(&head, position);
            break;

        case 11: // delete data after a specified position
            printf("Enter the position to delete data after position : ");
            scanf("%d", &position);

            delete_after_pos(&head, position);
            break;

        case 12: // delete data before a specified position
            printf("Enter the position to delete data before position : ");
            scanf("%d", &position);

            delete_before_pos(&head, position);
            break;

        case 13: // delete specific data using data
            delete_using_data(&head);
            break; 

        case 14: // delete data before specific data
            delete_before_specific_data(&head);
            break;

        case 15: // delete data after specific data            
            delete_after_specific_data(&head);
            break;

        case 16: // delete all data
            delete_all(&head);
            break;

        case 17: // searching the data at specified position
            printf("Enter the position to search in the list : ");
            scanf("%d", &position);

            search_by_pos(head, position);
            break;

        case 18: // searching the data using data in list
            printf("Enter the data to search in the list : ");
            scanf("%d", &data);

            search_by_data(head, data);
            break;

        case 19: // counting the list elements
            total_elements = counter_list(head);
            printf("Count of elements : %d\n", total_elements);
            break;

        case 20: // counting the repitition of the data
            data_frequency(head);
            break;

        case 21: // find maximum in the list
            max = max_data(head);
            printf("\nMaximum data in the list : %d\n", max);
            break;

        case 22: // find minimum in the list
            min = min_data(head);
            printf("\nMinimum data in the list : %d\n", min);
            break;

        case 23: // sorting the list
            sort_list(&head);
            break;

        case 24: // displaying the list
            display_list(head); // passing the address of head to the function
            break;

        case 25: // exiting the loop
            exit(0); // using the exit() function to exit the loop
            break;

        default: // if user inputs a invalid choice
            printf("\nPlease enter a valid choice!\n");
            break;
        }
    }

    return 0;
}
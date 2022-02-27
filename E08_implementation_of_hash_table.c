#include<stdio.h>
#include<stdlib.h>

struct employee 
{
    int id;
    char name[30];
    float salary;
}e[10];

// hash function
int hash(int num)
{   
    int key;
    key = num % 10;
    return key;
}

// display function 
void display()
{
    for (int i = 0; i < 10; i++)
    {
        printf("\nEmployee %d :\n", i+1);
        printf("ID : %d\n", e[i].id);
        printf("Name : %s\n", e[i].name);
        printf("Salary : %.2f\n", e[i].salary);
    }
    
}

// insert function
void insert(int data)
{
    int key, flag = 0, n;
    key = hash(data);
    n = key;
    if (e[key].id == -1)
    {
        e[key].id = data;
        printf("Enter the name : ");
        scanf("%s", &e[key].name);
        printf("Enter the slaray : ");
        scanf("%f", &e[key].salary);
    }
    else if (e[key].id != -1)
    {
        for (int i = n; i < 10; i++)
        {
            if (e[key + i].id == -1)
            {
                e[key + i].id = data;
                printf("Enter the name : ");
                scanf("%s", &e[key + i].name);
                printf("Enter the slaray : ");
                scanf("%f", &e[key + i].salary);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            for (int j = 0; j < key; j++)
            {
                if (e[j].id == -1)
                {
                    e[j].id = data;
                    printf("Enter the name : ");
                    scanf("%s", &e[j].name);
                    printf("Enter the slaray : ");
                    scanf("%f", &e[j].salary);
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 2;
                }
            }
        }
        if (flag == 2)
        {
            printf("\nList is full.....no space to input the data\n");
        }
    }
}

// searching the list element
void search(int num)
{
    int flag=0;
    for (int i = 0; i < 10; i++)
    {
        if (e[i].id == num)
        {
            printf("Data found !!\n");
            printf("ID : %d\n", e[i].id);
            printf("Name : %s\n", e[i].name);
            printf("Salary : %.2f\n", e[i].salary);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Data was not found !!\n");
    }
}

void main()
{
    //struct employee e[10];
    int choice, data;
    for (int i = 0; i < 10; i++)
    {
        e[i].id = -1;
    }
    
    printf("Operations: \n");
    printf(" 1. Insert \n 2. Search \n 3. Display \n 4. Exit \n");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the ID : ");
            scanf("%d", &data);
            insert(data);
            break;
        
        case 2:
            printf("Enter the ID to search : ");
            scanf("%d", &data);
            search(data);
            break;
        
        case 3:
            display();
            break;
        
        case 4:
            exit(0);
            break;

        default:
            printf("\nEnter a valid choice!!\n");
            break;
        }
    }
    
}
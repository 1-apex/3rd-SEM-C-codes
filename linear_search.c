#include<stdio.h>

//linear search by position function declaration
void linear_search_by_position(int array[], int size, int position)
{
    for (int i = 0; i < size; i++)
    {
        if (position > size || position < 0)            //check whether teh position exceeds the array size
        {
            printf("Please enter a valid position!\n");
            break;
        }
        if (array[position] == array[i])
        {
            printf("Data at position %d : %d\n", position, array[i]);
        }
    }
}

void linear_search_by_data(int array[], int size, int data)
{
    int flag; 
    for (int i = 0; i < size; i++)
    {
        if (data == array[i])
        {
            printf("Data found at position : %d\n", i);
        }
    }
}

int main()
{
    int array[5] = {1,2,3,4,5};
    int size = 5, position, choice, data;

    printf("1. Search by position\n2. Search by data\n");

    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the position to search data : ");
        scanf("%d", &position);

        linear_search_by_position(array, size, position);
        break;
    
    case 2:
        printf("Enter the data to search : ");
        scanf("%d", &data);

        linear_search_by_data(array, size, data);
        break;

    default:
        printf("Invalid choice!!\n");
        break;
    }
    
    return 0;
}
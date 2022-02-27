/*
In quick sort,
we consider 0th index as our pivot and then on that basis compare and swap the elements
------------use of recursive function----------- 
*/

#include <stdio.h>

//function declaration of displaying the array
void display(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

//function declaration of the partitioned array
int partition(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (array[i] <= pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    } while (i < j);

    // swap array[low] and array[j]
    temp = array[low];
    array[low] = array[j];
    array[j] = temp;

    return j;
}

void qucik_sort(int array[], int low, int high)
{
    int partition_index; // index of pivot after partition

    if (low < high)
    {
        partition_index = partition(array, low, high);
        qucik_sort(array, low, partition_index - 1);  // sort left sub array
        qucik_sort(array, partition_index + 1, high); // sort right sub array
    }
}

//main body
int main()
{
    int array[] = {3, 5, 2, 13, 12};
    int size = 5;

    display(array, size);           // before sorting
    qucik_sort(array, 0, size - 1); // calling the sorting function
    display(array, size);           // after sorting

    return 0;
}

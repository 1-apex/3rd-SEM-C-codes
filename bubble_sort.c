/*
In bubble sort ,
each element is compared with the adjacent element and then swapped if lower/higher
*/

#include <stdio.h>

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

void bubble_sort(int array[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    int array[5] = {23, 15, 29, 11, 1};
    int size = 5;

    bubble_sort(array, size);
    display(array, size);

    return 0;
}
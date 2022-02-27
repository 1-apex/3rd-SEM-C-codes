#include <stdio.h>

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

void insertion_sort(int array[], int size)
{
    int hole, value, i;
    for (i = 0; i < size; i++)
    {
        value = array[i];
        hole = i;
        while (hole > 0 && array[hole - 1] > value)
        {
            array[hole] = array[hole - 1];
            hole = hole - 1;
        }
        array[hole] = value;
    }
}

int main()
{
    int array[5] = {23, 15, 29, 11, 1};
    int size = 5;

    insertion_sort(array, size);
    display(array, size);

    return 0;
}
//practical 10 (i) bubble sort 

#include <stdio.h>

int main()
{
    int a[5] = {50, 20, 40, 10, 30};
    int i, j, temp;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);

    return 0;
}

/*
logic for this sorting method

Compare two adjacent elements.



If the first element is greater than the second, swap them.



Repeat until the largest element moves to the end.



Continue until the array is sorted.*/
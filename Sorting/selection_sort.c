//practical 10 (ii) selection sort

#include <stdio.h>

int main()
{
    int a[5] = {50, 20, 40, 10, 30};
    int i, j, min, temp;

    for (i = 0; i < 4; i++)
    {
        min = i;

        for (j = i + 1; j < 5; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("Sorted array: ");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);

    return 0;
}

/*Selection Sort — Basic Logic
1. Assume the first element is the smallest.
2. Search the remaining array for the smallest element.
3. Swap the smallest element with the first element of the unsorted part.
4. Repeat for the remaining elements until sorted.*/
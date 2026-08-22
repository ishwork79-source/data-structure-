#include <stdio.h>

// Call by Value
void callByValue(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;

    printf("Inside Call by Value:\n");
    printf("a = %d, b = %d\n", a, b);
}

// Call by Reference
void callByReference(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    printf("Inside Call by Reference:\n");
    printf("a = %d, b = %d\n", *a, *b);
}

int main()
{
    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    printf("\nBefore Call by Value:\n");
    printf("x = %d, y = %d\n", x, y);

    callByValue(x, y);

    printf("After Call by Value:\n");
    printf("x = %d, y = %d\n", x, y);

    printf("\nBefore Call by Reference:\n");
    printf("x = %d, y = %d\n", x, y);

    callByReference(&x, &y);

    printf("After Call by Reference:\n");
    printf("x = %d, y = %d\n", x, y);

    return 0;
}
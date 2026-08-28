#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push a value into stack
void push(int value)
{
    stack[++top] = value;
}

// Pop a value from stack
int pop()
{
    return stack[top--];
}

// Perform operation
int calculate(int a, int b, char operator)
{
    switch (operator)
    {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;

        case '%':
            return a % b;

        default:
            return 0;
    }
}

int main()
{
    char postfix[MAX];
    int i;
    int a, b, result;

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        // If operand, push it into stack
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }

        // If operator, perform calculation
        else
        {
            b = pop();
            a = pop();

            result = calculate(a, b, postfix[i]);

            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}
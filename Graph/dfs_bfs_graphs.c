//practical 9 Develop a program to implement and demonstrate DFS and 
//BFS graph traversal techniques.


#include <stdio.h>

int a[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0}
};

int visited[5];

void DFS(int v)
{
    int i;
    printf("%d ", v);

    visited[v] = 1;

    for (i = 0; i < 5; i++)
    {
        if (a[v][i] == 1 && !visited[i])
            DFS(i);
    }
}

void BFS(int start)
{
    int queue[5], front = 0, rear = 0;
    int i, v;

    for (i = 0; i < 5; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < 5; i++)
        {
            if (a[v][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i;

    printf("DFS Traversal: ");
    for (i = 0; i < 5; i++)
        visited[i] = 0;
    DFS(0);

    printf("\nBFS Traversal: ");
    BFS(0);

    return 0;
}
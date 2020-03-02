#include <stdbool.h>
#include <stdio.h>

#define SIZE 6

int graph[][SIZE] = {{0,1,1,0,0,0},
                     {0,0,0,0,0,0},
                     {0,0,0,0,1,1},
                     {0,0,0,0,0,0},
                     {0,0,0,0,0,0},
                     {0,0,0,0,0,0},
                    };

void DFS(int v, bool visited[]);

void dfs(int v)
{
    bool visited[SIZE];
    for(int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    DFS(v, visited);
}

void DFS(int v, bool visited[])
{
    visited[v] = true;
    for(int i = 0; i < SIZE; i++)
    {
        if(!visited[i] && graph[v][i])
            DFS(i,visited);

    }
    printf("Task %d --> ",v);
}

int main()
{
    dfs(0);
    printf("Done\n");
}

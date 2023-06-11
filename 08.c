#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int vex;//顶点数
    int arc;//弧度数
    int distance[100][100];
} Graph;

int getmin(Graph G, int* d, int* s)
{
    int min = 10000;
    int index, i;
    for(i = 0; i < G.vex; i++)
    {
        if(!s[i] && d[i] < min)
        {
            min = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(Graph G, int index)
{
    int i, j;
    int* s = (int*)malloc(sizeof(int) * G.vex);
    int* p = (int*)malloc(sizeof(int) * G.vex);
    int* d = (int*)malloc(sizeof(int) * G.vex);
    for(i = 0; i < G.vex; i++)
    {
        if(i == index)
            s[i] = 1;
        else
            s[i] = 0;

        if(G.distance[index][i] > 0 && G.distance[index][i] != 10000)
            p[i] = index;
        else
            p[i] = -1;

        d[i] = G.distance[index][i];
    }
    for(i = 0; i < G.vex - 1; i++)
    {
        int index = getmin(G, d, s);
        s[index] = 1;
        for(j = 0; j < G.vex; j++)
        {
            if(!s[j] && (d[index] + G.distance[index][j] < d[j]))
            {
                d[j] = d[index] + G.distance[index][j];
                p[j] = index;
            }
        }
    }

    for(i = 0; i < G.vex; i++)
        printf("%d\n", d[i]);
}

int main()
{
    int n, x, y;
    scanf("%d", &n);
    Graph G;
    G.vex = n;
    for(x = 0; x < n; x++)
    {
        for(y = 0; y < n; y++)
        {
            scanf("%d", &G.distance[x][y]);
        }
    }
    dijkstra(G, 0);
    return 0;
}

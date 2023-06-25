//dijkstra算法

#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int vex;    //顶点数量
    int arc;    //边数量
    int distance[100][100];
} Graph;

/*
    找到还没有被选中的且路径长度最短的一条路径
    返回其顶点下标，做为新的中转点
*/
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

/*
    index是起始点
    一共三个数组，s p d
    s数组表示此路径是否已被选中，选中为1，未选中为0
    p数组存储路径中转点的数组下标
    d数组存储起点到每一点的最短路径
*/
void dijkstra(Graph G, int index)
{
    int i, j, num = 0;
    int* s = (int*)malloc(sizeof(int) * G.vex);
    int* p = (int*)malloc(sizeof(int) * G.vex);
    int* d = (int*)malloc(sizeof(int) * G.vex);
    //将三个数组初始化
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
        //表示此边已被选中
        s[index] = 1;
        for(j = 0; j < G.vex; j++)
        {
            //如果路径小于则更新
            if(!s[j] && (d[index] + G.distance[index][j] < d[j]))
            {
                d[j] = d[index] + G.distance[index][j];
                p[j] = index;
            }
        }
    }

    for(i = 0; i < G.vex; i++)
    {
        if(i == index)
            s[i] = 1;
        else
            s[i] = 0;
    }
    for(i = 1; i < G.vex; i++)
    {
        if(d[i] == 10000)
            num++;
    }
    for(i = 0; i < G.vex - num - 1; i++)
    {
        int index = getmin(G, d, s);
        s[index] = 1;
        printf("%d %d %d\n", 1, index + 1, d[index]);
    }
    for(i = 1; i < G.vex; i++)
    {
        if(d[i] == 10000)
            printf("%d %d %d", 1, i + 1, -1);
    }
}

int main()
{
    int n, m, x, y, start, end, distance;
    scanf("%d %d", &n, &m);
    Graph G;
    G.vex = n, G.arc = m;
    for(x = 0; x < n; x++)
    {
        for(y = 0; y < n; y++)
        {
            G.distance[x][y] = 10000;
        }
    }
    for(x = 0; x < G.arc; x++)
    {
        scanf("%d %d %d", &start, &end, &distance);
        G.distance[start - 1][end - 1] = distance;
    }
    dijkstra(G, 0);
    return 0;
}

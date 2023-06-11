#include <stdio.h>
#include <stdlib.h>

typedef struct adjmatrix
{
    int vex;//顶点数
    int arc;//弧度数
    int distance[100][100];
} adjmatrix;

void floyd(adjmatrix G, int P[100][100], int D[100][100])
{
    int a, b, c;
    for (a = 0; a < G.vex; a++) {
        for (b = 0; b < G.vex; b++) {
            D[a][b] = G.distance[a][b];
            P[a][b] = b;
        }
    }

    for (c = 0; c < G.vex; c++) {
        for (a = 0; a < G.vex; a++) {
            for (b = 0; b < G.vex; b++) {
                if (D[a][b] > (D[a][c] + D[c][b])) {
                    D[a][b] = D[a][c] + D[c][b];
                    P[a][b] = P[a][c];
                }
            }
        }
    }
}

int main()
{
    int n, x, y, m;
    scanf("%d", &n);
    //path是从a到b的最短路径，shortpath是从a到b的最短路径长度
    int path[100][100];
    int shortpath[100][100];
    adjmatrix G;
    G.vex = n;
    for(x = 0; x < n; x++)
    {
        for(y = 0; y < n; y++)
        {
            scanf("%d", &G.distance[x][y]);
        }
    }
    floyd(G, path, shortpath);
    scanf("%d", &m);
    int xx[100], yy[100];
    for(n = 0; n < m; n++)
    {
        scanf("%d %d", &xx[n], &yy[n]);
    }
    for(n = 0; n < m; n++)
    {
        printf("%d\n", shortpath[xx[n]][yy[n]]);
    }
    return 0;
}

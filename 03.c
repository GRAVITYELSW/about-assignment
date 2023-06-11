//Ï¡Êè¾ØÕó×ªÖÃ
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Triple
{
    int row, col;
    int e;
} Triple;

typedef struct Tsmatrix
{
    Triple data[1000];
    int row, col, len;
} Tsmatrix;

void fasttranspose(Tsmatrix A, Tsmatrix* B)
{
    int col, t, p, q;
    int num[1000], position[1000];
    B->len = A.len, B->col = A.row, B->row = A.col;
    if(B->len)
    {
        for(col = 0; col < A.col; col++)
        {
            num[col] = 0;
        }
        for(t = 0; t < A.len; t++)
        {
            num[A.data[t].col]++;
        }
        position[0] = 0;
        for(col = 1; col < A.col; col++)
        {
            position[col] = position[col - 1] + num[col - 1];
        }
        for(p = 0; p < A.len; p++)
        {
            col = A.data[p].col;
            q = position[col];
            B->data[q].row = A.data[p].col;
            B->data[q].col = A.data[p].row;
            B->data[q].e = A.data[p].e;
            position[col]++;
        }
    }
}

int main()
{
    int n, m, i =0;
    scanf("%d %d", &n, &m);
    Tsmatrix A;
    A.row = n;
    A.col = m;
    int row, col, data;
    while(1)
    {
        scanf("%d", &row);
        getchar();
        scanf("%d", &col);
        getchar();
        scanf("%d", &data);
        getchar();
        if(row == 0 && col == 0 && data == 0)
            break;
        A.data[i].row = row;
        A.data[i].col = col;
        A.data[i].e = data;
        i++;
    }
    A.len = i;
    Tsmatrix* B = (Tsmatrix*)malloc(sizeof(Tsmatrix));

    fasttranspose(A, B);
    int j;
    for(j = 0; j < i; j++)
    {
        printf("%d %d %d\n", B->data[j].row, B->data[j].col, B->data[j].e);
    }
    free(B);
    return 0;
}


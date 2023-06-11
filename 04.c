//œ° Ëæÿ’Ûº”∑®
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
    Triple data[500];
    int row, col, len;
} Tsmatrix;

int addmatrix(Tsmatrix A, Tsmatrix B, Tsmatrix *C, int t1, int t2)
{
    int i = 1, j = 1, k = 0;
    while(i <= t1 && j <= t2)
    {
        if(A.data[i].row < B.data[j].row)
            C->data[k++] = A.data[i++];
        else if(A.data[i].row > B.data[j].row || A.data[i].col > B.data[j].col)
            C->data[k++] = B.data[j++];
        else if(A.data[i].col == B.data[j].col)
        {
            if(A.data[i].e + B.data[j].e != 0)
            {
                C->data[k].row = A.data[i].row;
                C->data[k].col = A.data[i].col;
                C->data[k].e = A.data[i].e + B.data[j].e;
                k++;
            }
            i++, j++;
        }
        else
            C->data[k++] = A.data[i++];
    }
    while(i <= t1)
        C->data[k++] = A.data[i++];
    while(j <= t2)
        C->data[k++] = B.data[j++];
    return k;
}

int main()
{
    int m, n, t1, t2, i;
    int row, col, data;
    scanf("%d %d %d %d", &m, &n, &t1, &t2);
    Tsmatrix A, B;
    Tsmatrix* C = (Tsmatrix*)malloc(sizeof(Tsmatrix));
    A.row = m, B.row = m, C->row = m;
    A.col = n, B.col = n, C->col = n;
    A.len = t1, B.len = t2;
    for(i = 1; i <= t1; i++)
    {
        scanf("%d %d %d", &row, &col, &data);
        A.data[i].row = row, A.data[i].col = col, A.data[i].e = data;
    }
    for(i = 1; i <= t2; i++)
    {
        scanf("%d %d %d", &row, &col, &data);
        B.data[i].row = row, B.data[i].col = col, B.data[i].e = data;
    }
    int t3;
    t3 = addmatrix(A, B, C, t1, t2);
    for(i = 0; i < t3; i++)
    {
        printf("%d %d %d\n", C->data[i].row, C->data[i].col, C->data[i].e);
    }
    free(C);
    return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Triple
{
    int row, col;
    int e;
} Triple;

typedef struct matrix
{
    Triple data[500];
    int m, n, len;
} matrix;

int matrix_input(matrix* A)
{
    int m, n;
    scanf("%d %d", &m, &n);
    A->m = m, A->n = n;
    int t = 0;
    while(1)
    {
        int a, b, c;
        scanf("%d", &a);
        getchar();
        scanf("%d", &b);
        getchar();
        scanf("%d", &c);
        getchar();
        if(a == 0 && b == 0 && c == 0)
            break;
        A->data[t].row = a, A->data[t].col = b, A->data[t].e = c;
        t++;
    }
    return t;
}

void transpose(matrix* A, int t)
{
    int tem, i = 0, j = 0;
    Triple node;
    for(i = 0; i < t; i++)
    {
        tem = A->data[i].row;
        A->data[i].row = A->data[i].col;
        A->data[i].col = tem;
    }

    for(i = 0; i < t - 1; i++)
        for(j = 0; j < t - 1 - i; j++)
        {
            if(A->data[j].row > A->data[j+1].row)
            {
                node = A->data[j];
                A->data[j] = A->data[j+1];
                A->data[j+1] = node;
            }
        }
}

int multiply(matrix* A, matrix* B, matrix*C, int t1, int t2)
{
    int s1, s2, x, t = 0, i = 0, j = 0;
    C->m = A->m;
    C->n = B->n;
    for(i = 1; i <= A->m; i++)
    {
        for(j = 1;j <= B->n; j++)
        {
            s1 = 0, s2 = 0,x = 0;
            while(s1 < t1 && A->data[s1].row != i)
                s1++;
            while(s2 < t2 && B->data[s2].row != j)
                s2++;
            while(s1 < t1 && s2 < t2 && A->data[s1].row == i && B->data[s2].row == j)
            {
                if(A->data[s1].col == B->data[s2].col)
                {
                    x += A->data[s1].e * B->data[s2].e;
                    s1++, s2++;
                }
                else if(A->data[s1].col < B->data[s2].col)
                    s1++;
                else
                    s2++;
            }
            if(x)
            {
                C->data[t].row = i, C->data[t].col = j, C->data[t].e = x;
                t++;
            }
        }
    }
    return t;
}

int main()
{
    matrix* A =(matrix*)malloc(sizeof(matrix));
    matrix* B =(matrix*)malloc(sizeof(matrix));
    matrix* C =(matrix*)malloc(sizeof(matrix));
    int t1, t2, t3, i;

    t1 = matrix_input(A);
    t2 = matrix_input(B);
    transpose(B, t2);

    t3 = multiply(A, B, C, t1, t2);

    for(i = 0; i < t3; i++)
        printf("%d %d %d\n", C->data[i].row, C->data[i].col, C->data[i].e);

    return 0;
}

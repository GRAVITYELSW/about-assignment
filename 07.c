#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct node
{
    int val;
    int lchild;
    int rchild;
    int parent;
    char e;
} node, HTree;
typedef char** treecode;

void select(HTree* tree, int n, int* s1, int* s2)
{
    int i, v1, v2;
    for(i = 1; i <= n; i++)
    {
        if(tree[i].parent == 0)
        {
            if(*s1 == 0)
            {
                *s1 = i;
                v1 = tree[i].val;
            }
            else if(*s2 == 0)
            {
                if(tree[i].val < v1)
                {
                    *s2 = *s1;
                    v2 = v1;
                    *s1 = i;
                    v1 = tree[i].val;
                }
                else
                {
                    *s2 = i;
                    v2 = tree[i].val;
                }
            }
            else if(tree[i].val < v1)
            {
                *s2 = *s1;
                v2 = v1;
                *s1 = i;
                v1 = tree[i].val;
            }
            else if(tree[i].val < v2)
            {
                *s2 = i;
                v2 = tree[i].val;
            }
        }
    }
}

void creatHTree(HTree* tree, int n)
{
    int i, val;
    char e;
    for(i = 1; i <= n; i++)
    {
        scanf("%c ", &e);
        tree[i].e = e;
    }
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &val);
        tree[i].val = val;
        tree[i].parent = 0, tree[i].lchild = 0, tree[i].rchild = 0;
    }
    for(i = n + 1; i < 2 * n; i++)
    {
        tree[i].val = 0, tree[i].parent = 0, tree[i].lchild = 0, tree[i].rchild = 0;
    }
    for(i = n + 1; i < 2 * n; i++)
    {
        int s1 = 0, s2 = 0;
        select(tree, i - 1, &s1, &s2);
        tree[i].val = tree[s1].val + tree[s2].val;
        tree[s1].parent = i, tree[s2].parent = i;
        tree[i].lchild = s1, tree[i].rchild = s2;
    }
}

void creatcode(HTree* tree, int n, treecode sc)
{
    int i, start, c, p;
    char* cd;
    cd = (char*)malloc(n * sizeof(char));
    cd[n - 1] = '\0';
    for(i = 1; i <= n; i++)
    {
        start = n - 1;
        c = i, p = tree[i].parent;
        while(p != 0)
        {
            --start;
            if(tree[p].lchild == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            c = p;
            p = tree[p].parent;
        }
        sc[i] = (char*)malloc((n - start) * sizeof(char));
        strcpy(sc[i], &cd[start]);
    }
    free(cd);
}

void decode(HTree* tree, char coding[], int n, int len)
{
    int i, head, next, round;
    head = round = 2 * n - 1;
    for(i = 0; i < len; i++)
    {
        if(coding[i] == '0')
        {
            next = tree[round].lchild;
            round = next;
        }
        if(coding[i] == '1')
        {
            next = tree[round].rchild;
            round = next;
        }
        if(tree[next].lchild == 0 && tree[next].rchild == 0)
        {
            printf("%c", tree[next].e);
            round = head;
        }

    }
}

int main()
{
    int n, i, j, k, m, p = 0;
    scanf("%d ", &n);
    if(n < 1)
    {
        printf("error");
        return 0;
    }
    else
    {
        HTree* tree = (HTree*)malloc(2 * n * sizeof(node));
        creatHTree(tree, n);
        treecode sc = (char**)malloc((n + 1) * sizeof(char*));
        creatcode(tree, n, sc);
        getchar();

        char arr[101], coding[500];
        fgets(arr, 101, stdin);
        int len = strlen(arr);
        for(i = 0; i < len; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(tree[j].e == arr[i])
                {
                    printf("%s", sc[j]);
                    m = strlen(sc[j]);
                    for(k = 0; k < m; k++)
                    {
                        coding[k + p] = sc[j][k];
                    }
                    p += m;
                }
            }
        }
        printf("\n");
        decode(tree, coding, n, p);

        return 0;
    }
}

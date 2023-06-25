//二叉排序树的插入和删除

#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int data;
    struct treenode* lchild;
    struct treenode* rchild;
} treenode;

void creattree(treenode** t)
{
    int data;
    scanf("%d", &data);
    if(data == -1)
    {
        *t = NULL;
    }
    else
    {
        *t = (treenode*)malloc(sizeof(treenode));
        (*t)->data = data;
        creattree(&((*t)->lchild));
        creattree(&((*t)->rchild));
    }
}

void inorder(treenode* t, int data[], int* i)
{
    if(t)
    {
        inorder(t->lchild, data, i);
        data[*i] = t->data;
        (*i)++;
        inorder(t->rchild, data, i);
    }
}

void findkey(int data[], int len, int a, int b)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(data[i] > a && data[i] < b)
            printf("%d ", data[i]);
    }
    printf("\n");
}

void insertkey(int data[], int len, int key)
{
    int i, count = 0;
    for(i = 0; i < len; i++)
    {
        if(count == 0)
        {
            if(key < data[i])
            {
                printf("%d ", key);
                count = 1;
            }
        }
        printf("%d ", data[i]);
    }
    printf("\n");
}

void deletekey(int data[], int len, int key)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(data[i] != key)
            printf("%d ", data[i]);
    }
}

int main()
{
    int data[100];
    int a, b, in, de, i = 0;
    treenode* t;
    creattree(&t);
    inorder(t, data, &i);
    scanf("%d %d", &a, &b);
    scanf("%d", &in);
    scanf("%d", &de);

    findkey(data, i, a, b);
    insertkey(data, i, in);
    deletekey(data, i, de);

    return 0;
}
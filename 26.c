//二叉排序树的合并

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

void mergetree(int data1[], int data2[], int len1, int len2)
{
    int i = 0, j = 0;
    while(i < len1 && j < len2)
    {
        if(data1[i] <= data2[j])
        {
            printf("%d ", data1[i]);
            i++;
        }
        else
        {
            printf("%d ", data2[j]);
            j++;
        }
    }
    while(i < len1)
    {
        printf("%d ", data1[i]);
        i++;
    }
    while(j < len2)
    {
        printf("%d ", data2[j]);
        j++;
    }
}

int main()
{
    int data1[100], data2[100];
    int i1 = 0, i2 = 0;
    treenode* t1;
    treenode* t2;
    creattree(&t1);
    creattree(&t2);
    inorder(t1, data1, &i1);
    inorder(t2, data2, &i2);
    mergetree(data1, data2, i1, i2);
    return 0;
}
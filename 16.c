//计算二叉树叶子结点数目
//利用递归，如果此节点左子树和右子树均为NULL则返回加一

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode
{
    char data;
    struct treenode* lchild;
    struct treenode* rchild;
} treenode;

void creattree(treenode** t, char data[], int *index)
{
    if(data[*index] == '#')
    {
        *t = NULL;
        (*index)++;
    }
    else
    {
        *t = (treenode*)malloc(sizeof(treenode));
        (*t)->data = data[*index];
        (*index)++;
        creattree(&((*t)->lchild), data, index);
        creattree(&((*t)->rchild), data, index);
    }
}

int leafnode(treenode* t, int *num)
{
    if(t)
    {
        if(t->lchild == NULL && t->rchild == NULL)
            return (*num)++;
        leafnode(t->lchild, num);
        leafnode(t->rchild, num);
    }
    else
        return *num;
}

int main()
{
    char data[100];
    fgets(data, 100, stdin);

    treenode* t;
    int index = 0;
    int num = 0;
    creattree(&t, data, &index);
    leafnode(t, &num);
    printf("%d", num);
    return 0;
}

//输出以二叉树表示的算术表达式
//先序输入，中序输出

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

void inorder(treenode* t)
{
    if(t)
    {
        inorder(t->lchild);
        printf("%c", t->data);
        inorder(t->rchild);
    }
}

int main()
{
    char data[100];
    fgets(data, 100, stdin);

    treenode* t;
    int index = 0;
    creattree(&t, data, &index);
    inorder(t);
    return 0;
}

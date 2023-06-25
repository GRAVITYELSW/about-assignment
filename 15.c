//构建二叉树的二叉链表存储形式
//先序遍历输出
//以广义表形式输入

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

void preorder(treenode* t)
{
    if(t)
    {
        printf("%c", t->data);
        if(t->lchild == NULL && t->rchild != NULL)
        {
            printf("#");
            preorder(t->rchild);
        }
        else if(t->rchild == NULL && t->lchild != NULL)
        {
            preorder(t->lchild);
            printf("#");
        }
        else
        {
            preorder(t->lchild);
            preorder(t->rchild);
        }
    }
}

int main()
{
    int i, j = 0;
    char start[100];
    char data[100];
    fgets(start, 100, stdin);
    int len = strlen(start) - 1;
    for(i = 0; i < len; i++)
    {
        if(start[i] >= 'A' && start[i] <= 'Z')
        {
            data[j] = start[i];
            j++;
            if(start[i + 1] == ',' || start[i + 1] == ')')
            {
                data[j] = '#', data[j + 1] = '#';
                j += 2;
            }
        }
        if(start[i] == '#')
        {
            data[j] = start[i];
            j++;
        }
    }
    treenode* t;
    int index = 0;
    creattree(&t, data, &index);
    preorder(t);
    return 0;
}

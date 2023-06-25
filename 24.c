//二叉排序树的判定
//数字按先序输入，构建二叉树
//中序输出，判断输出是否为升序，若为升序则yes，否则no

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

void judgebst(int data[], int len)
{
    int i;
    for(i = 0; i < len - 1; i++)
    {
        if(data[i] > data[i + 1])
        {
            printf("no");
            return;
        }
    }
    printf("yes");
}

int main()
{
    int data[100];
    int i = 0;
    treenode* t;
    creattree(&t);
    inorder(t, data, &i);
    judgebst(data, i);
    return 0;
}

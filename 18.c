//由先序和中序转后序

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode
{
    char data;
    struct treenode* lchild;
    struct treenode* rchild;
} treenode;

char pre[100], in[100];

void post(int root, int start, int end)
{
    if(start > end)
        return;
    int i = start;
    while(i < end && in[i] != pre[root])
        i++;
    post(root + 1, start, i - 1);
    post(root + 1 - start + i, i + 1, end);
    printf("%c", pre[root]);
}

int main()
{
    fgets(pre, 100, stdin);
    fgets(in, 100, stdin);
    int len = strlen(pre) - 2;
    post(0, 0, len);
    return 0;
}
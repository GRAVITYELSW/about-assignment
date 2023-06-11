#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node* pre;
    struct Node* next;
} Node;

Node* initlist()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->pre = NULL;
    node->data = 2;
    return node;
}

void tailinsert(Node* list, int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    while(list->next != NULL)
    {
        list = list->next;
    }
    list->next = node;
    node->pre = list;
}

void printlist(Node* list, int n)
{
    printf("%d.", list->data);
    list = list->next;
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d", list->data);
        list = list->next;
    }
    printf("\n");
}

int main()
{
    int n, i;
    scanf("%d", &n);
    Node* num = initlist();
    Node* sum = initlist();
    for(i = 0; i < 600; i++)
    {
        tailinsert(num, 0);
        tailinsert(sum, 0);
    }
    Node* headn = num;
    Node* heads = sum;
    while(num->next != NULL)
    {
        num = num->next;
    }
    Node* numtail = num;
    while(sum->next != NULL)
    {
        sum = sum->next;
    }
    Node* sumtail = sum;
    int temp = 0, ret = 0, t = 3;
    for(i = 1; i < 10000; i++, t = 2 * i + 1)
    {
        Node* tempnum = numtail;
        Node* tempsum = sumtail;
        ret = 0;
        while(tempnum)
        {
            temp = tempnum->data * i + ret;
            tempnum->data = temp % 10;
            ret = temp / 10;
            tempnum = tempnum->pre;
        }
        ret = 0;
        tempnum = headn;
        while(tempnum)
        {
            temp = tempnum->data + ret * 10;
            ret = temp % t;
            tempnum->data = temp / t;
            tempnum = tempnum->next;
        }
        ret = 0;
        tempnum = numtail;
        while(tempsum && tempnum)
        {
            temp = tempnum->data + tempsum->data + ret;
            ret = temp / 10;
            tempsum->data = temp % 10;
            tempsum = tempsum->pre;
            tempnum = tempnum->pre;
        }
    }
    printlist(heads, n);

    return 0;
}


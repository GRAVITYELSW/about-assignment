//线性表的就地逆置

#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void insertlist(Node* list, int x)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = x;
    node->next = NULL;
    while(list->next != NULL)
    {
        list = list->next;
    }
    list->next = node;
}

void printlist(Node* head)
{
    Node* list = head;
    while(list->next != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

void reversearr(int a[], int e)
{
    int i = 0, temp;
    for(i = 0; i < e / 2; i++)
    {
        temp = a[i];
        a[i] = a[e - 1 - i];
        a[e - 1 - i] = temp;
    }
}

Node* reverselist(Node* list)
{
    Node* head = list;
    list = list->next;
    Node* after = list->next;
    head->next = NULL;
    while(after)
    {
        list->next = head;
        head = list;
        list = after;
        after = after->next;
    }
    list->next = head;
    return list;
}

int main()
{
    int e, i = 0;
    scanf("%d", &e);
    int a[1000];
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = e;
    head->next = NULL;
    for(i = 0; i < e; i++)
    {
        scanf("%d", &a[i]);
        insertlist(head, a[i]);
    }
    reversearr(a, e);
    Node* list = reverselist(head);
    for(i = 0; i < e; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printlist(list);
    return 0;
}
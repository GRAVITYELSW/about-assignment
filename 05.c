//单链表的删除

#include<stdio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void initlist(Node* list, int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    while(list->next !=NULL)
    {
        list = list->next;
    }
    list->next = node;
}

int main()
{
    int a, b, c, i, same[100], k = 0, m, n, q;
    scanf("%d %d %d", &a, &b, &c);

    Node* ha = (Node*)malloc(sizeof(Node));
    Node* hb = (Node*)malloc(sizeof(Node));
    Node* hc = (Node*)malloc(sizeof(Node));

    ha->data = a;
    ha->next = NULL;
    for(i = 0; i < a; i++)
    {
        scanf("%d", &m);
        initlist(ha, m);
    }
    scanf("%d", &n);
    hb->data = n;
    hb->next = NULL;
    for(i = 0; i < b - 1; i++)
    {
        scanf("%d", &n);
        initlist(hb, n);
    }
    scanf("%d", &q);
    hc->data = q;
    hc->next = NULL;
    for(i = 0; i < c - 1; i++)
    {
        scanf("%d", &q);
        initlist(hc, q);
    }

    Node* headc = hc;
    while(hb)
    {
        while(hc)
        {
            if(hb->data == hc->data)
            {
                same[k] = hb->data;
                k++;
            }
            hc = hc->next;
        }
        hc = headc;
        hb = hb->next;
    }
    Node* heada = ha;
    while(ha->next != NULL)
    {
        for(i = 0; i < k; i++)
        {
            if(same[i] == ha->next->data)
            {
                Node* delete_node = ha->next;
                ha->next = ha->next->next;
                free(delete_node);
            }
        }
        ha = ha->next;
    }
    ha = heada->next;
    while(ha)
    {
        printf("%d ", ha->data);
        ha = ha->next;
    }

    return 0;
}
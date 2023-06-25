//LOCATE操作

#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    char data;
    int freq;
    struct Node* pre;
    struct Node* next;
} Node;

Node* initlist()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = head;
    head->pre = head;
    head->data = '0';
    head->freq = 0;
    return head;
}

void tailinsert(Node* list, char data)
{
    Node* head = list;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = 0;
    while(list->next != head)
    {
        list = list->next;
    }
    node->next = head;
    node->pre = list;
    list->next = node;
    head->pre = node;
}

void paixu(Node* list)
{
    Node* head = list;
    Node* head2 = list->next;
    list = list->next->next;
    while(list != head)
    {
        if(list->freq > list->pre->freq)
        {
            Node* cha = list;
            list->pre->next = list->next;
            list->next->pre = list->pre;
            while(head2 != head)
            {
                if(cha->freq >= head->next->freq)
                {
                    cha->pre = head;
                    cha->next = head->next;
                    head->next->pre = cha;
                    head->next = cha;
                    break;
                }
                if(cha->freq < head2->freq && cha->freq >= head2->next->freq)
                {
                    cha->next = head2->next;
                    cha->pre = head2;
                    head2->next->pre = cha;
                    head2->next = cha;
                    break;
                }
                if(cha->freq < head->pre->freq)
                {
                    cha->next = head;
                    cha->pre = head->pre;
                    head->pre->next = cha;
                    head->pre = cha;
                    break;
                }
                head2 = head2->next;
            }
            head2 = head->next;
        }
        list = list->next;
    }
}

void LOCATE(Node* list, char data)
{
    Node* head = list;
    list = list->next;
    while(list != head)
    {
        if(list->data == data)
        {
            list->freq++;
            break;
        }
        list = list->next;
    }
    paixu(head);
}

void printlist(Node* list)
{
    Node* head = list;
    list = list->next;
    while(list != head)
    {
        printf("%c ", list->data);
        list = list->next;
    }
}

int main()
{
    int m, n, i;
    char data;
    scanf("%d %d", &m, &n);
    char arr[n];
    Node* list = initlist();
    for(i = 0; i < m; i++)
    {
        scanf(" %c", &data);
        tailinsert(list, data);
    }
    for(i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i]);
    }
    for(i = 0; i < n; i++)
    {
        LOCATE(list, arr[i]);
    }
    printlist(list);
    return 0;
}
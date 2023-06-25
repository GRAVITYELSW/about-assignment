//单链表的归并

#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void initlist(Node* head, int x)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->data = x;
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next = node;
}

Node* mergelist(Node* a, Node* b)
{
    Node* head1 = a;
    Node* head2 = b;
    while(a)
    {
        while(b)
        {
            if(b == head2 && a->data <= b->data)
            {
                head1 = a->next;
                a->next = b;
                head2 = a;
                break;

            }
            if(b->next == NULL && a->data > b->data)
            {
                head1 = a->next;
                b->next = a;
                a->next = NULL;
                break;
            }
            if(b != head2 && b->next != NULL && a->data > b->data && a->data <= b->next->data)
            {
                head1 = a->next;
                a->next = b->next;
                b->next = a;
                break;
            }
            b = b->next;
        }
        a = head1;
        b = head2;
    }
    return head2;
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

void printlist(Node* list)
{
    Node* head = list;
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    Node* head1 = (Node*)malloc(sizeof(Node));
    Node* head2 = (Node*)malloc(sizeof(Node));
    head1->next = NULL;
    head2->next = NULL;

    int a, i;
    scanf("%d", &a);
    head1->data = a;
    for(i = 0; i < m - 1; i++)
    {
        scanf("%d", &a);
        initlist(head1, a);
    }
    scanf("%d", &a);
    head2->data = a;
    for(i = 0; i < n - 1; i++)
    {
        scanf("%d", &a);
        initlist(head2, a);
    }

    Node* before = mergelist(head1, head2);
    Node* after = reverselist(before);
    printlist(after);
    return 0;
}
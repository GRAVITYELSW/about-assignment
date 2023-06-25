//循环队列

#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int* data;
    int len;
    int front;
    int rear;
} queue;

queue* initqueue(int n)
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->len = n + 1;
    q->front = 0;
    q->rear = 0;
    q->data = (int*)malloc(sizeof(int)*q->len);
    return q;
}

void printqueue(queue* q, int chu)
{
    int a = q->front;
    while(q->data[a] != chu)
    {
        a++;
    }
    a++;
    int head = q->data[a];
    while(a != q->rear)
    {
        printf("%d ", q->data[a]);
        a++;
    }
    printf("\n%d", head);
}

int main()
{
    int n;
    scanf("%d", &n);
    queue* q = initqueue(n);
    while(1)
    {
        scanf("%d", &q->data[q->rear]);
        q->rear++;
        char a = getchar();
        if(a == '\n')
            break;
    }
    char b[10];
    fgets(b, 10, stdin);
    int chu;
    scanf("%d", &chu);
    printqueue(q, chu);
    return 0;
}
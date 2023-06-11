#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Node
{
	int i, j, x;
	struct Node *down, *right;
} Node;

typedef struct Crosslist
{
	int row, col;
	struct Node *chead, *rhead;
} Crosslist;

void insert(Crosslist* list, int i, int j, int x)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->i = i, node->j = j, node->x = x;
	node->down = NULL, node->right = NULL;
	Node *p = &list->rhead[i];
	if (p->right == NULL)
    {
		p->right = node;
	}
	else
    {
		while (p->right != NULL && p->right->j < j)
		{
			p = p->right;
		}
		if (p->right == NULL)
		{
			p->right = node;
		}
        else if (p->right->j == j)
        {
			p->right->x += node->x;
			if (p->right->x == 0)
			{
                Node *tem, *a = &list->chead[j];
                while (a->down->i != i)
                {
                    a = a->down;
                }
                tem = a->down;
                a->down = a->down->down;
                a = &list->rhead[i];
                while (a->right->j != j)
                {
                    a = a->right;
                }
                a->right = tem->right;
                free(tem);
			}
			free(node);
		}
		else
        {
			node->right = p->right;
			p->right = node;
		}
	}

	p = &list->chead[j];
	if (p->down == NULL)
    {
		p->down = node;
	}
	else
    {
		while (p->down != NULL && p->down->i < i)
        {
			p = p->down;
		}
		if (p->down == NULL)
        {
			p->down = node;
		}
		if (p->down != NULL && node != NULL && p->down->i > i)
        {
			node->down = p->down;
			p->down = node;
		}
	}
}

int main()
{
	Crosslist list;
	int t1, t2, t, i, j, x, k;
	scanf("%d %d %d %d", &list.row, &list.col, &t1, &t2);
	t = t1 + t2;
	list.chead = (Node*)malloc(sizeof(Node) * list.col);
	list.rhead = (Node*)malloc(sizeof(Node) * list.row);
	memset(list.chead, 0, sizeof(Node) * list.col);
	memset(list.rhead, 0, sizeof(Node) * list.row);

	for(k = 0; k < t; k++)
    {
        scanf("%d %d %d", &i, &j, &x);
        i--, j--;
		insert(&list, i, j, x);
    }

	for (i = 0; i < list.row; i++)
    {
		Node* node = list.rhead[i].right;
		while (node != NULL)
        {
			printf("%d %d %d\n", node->i + 1, node->j + 1, node->x);
			node = node->right;
		}
	}
	return 0;
}


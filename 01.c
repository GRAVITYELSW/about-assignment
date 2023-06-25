//顺序表的插入运算

#include <stdio.h>
#include <stdlib.h>

void arrinsert(int l[], int e, int x)
{
    int i = 0, j = 0;
    if(x <= l[0])
    {
        for(j = e; j > 0; j--)
        {
            l[j] = l[j - 1];
        }
        l[0] = x;
    }
    else if(l[e - 1] <= x)
    {
        l[e] = x;
    }
    else
    {
       for(i = 0; i < e - 1; i++)
       {
            if(x > l[i] && x <= l[i + 1])
            {
                for(j = e; j > i; j--)
                {
                    l[j] = l[j - 1];
                }
                l[i + 1] = x;
                break;
            }
       }
    }
}

int main()
{
    int e, x;
    scanf("%d", &e);
    int l[1000];
    int i = 0;
    for(i = 0; i < e; i++)
    {
        scanf("%d", &l[i]);
    }
    scanf("%d", &x);
    arrinsert(l, e, x);
    for(i = 0; i <= e; i++)
    {
        printf("%d ", l[i]);
    }
    return 0;
}
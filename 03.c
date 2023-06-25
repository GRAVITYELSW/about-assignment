//顺序表的删除

#include <stdio.h>

int main()
{
    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);
    int a[100], b[100], c[100], d[100];
    int i = 0, j = 0, k = 0, s = 0;
    for(i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    for(i = 0; i < p; i++)
    {
        scanf("%d", &c[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < p; j++)
        {
            if(b[i] == c[j])
            {
                d[k] = b[i];
                k++;
                break;
            }
        }
    }

    for(i = 0; i < k; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(d[i] == a[j])
            {
                for(s = j;s < m; s++)
                {
                    a[s] = a[s + 1];
                }
                m--;
            }
        }
    }
    for(i = 0; i < m; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
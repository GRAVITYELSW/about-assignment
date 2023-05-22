#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *a, *b;
    a = fopen("DATA5613.TXT", "r");
    b = fopen("DATA5613.CPP", "r");
    int i = 0, j = 0, k, l;
    char m[1000][1000], n[1000][1000];
    while(!feof(a))
    {
        if(fgets(m[i], 999, a) == NULL)
            continue;
        i++;
    }
    while(!feof(b))
    {
        if(fgets(n[j], 999, b) == NULL)
            continue;
        j ++;
    }
    int big = (i > j)? i : j;
    for(k = 0; k < big; k++)
    {
        for(l = 0; l < 1000; l++)
        {
            if(m[k][l] != n[k][l])
                printf("%d %d", k, l);
        }
    }
    return 0;
}

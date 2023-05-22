#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *p;
    p = fopen("/DATA5610.TXT", "r");
    int i = 0, j, a = 0, b = 0, c = 0;
    char arr[1000][1000];
    while (!feof(p))
    {
        if(fgets(arr[i], 999, p) == NULL)
            continue;
        i++;
    }
    int k = 0;
    for(k = 0; k < 1000; k++)
    {
        for(j = 0; j < 1000; j++)
        {
            if((arr[k][j] == 'i' || arr[k][i] == 'I') && arr[k][j+1] == 'f')
                a++;
            if((arr[k][j] == 'f' || arr[k][j] == 'F') && arr[k][j+1] == 'o' && arr[k][j+2] == 'r')
                b++;
            if((arr[k][j] == 'W' || arr[k][j] == 'w') && arr[k][j+1] == 'h' && arr[k][j+2] == 'i' && arr[k][j+3] == 'l' && arr[k][j+4] == 'e')
                c++;
        }
    }
    printf("%d %d %d", a, c, b);
    fclose(p);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void replace(char *str, char *fstr, char *rstr)
{
    int a = strlen(str);
    int b = strlen(fstr);
    int c = strlen(rstr) - 1;
    int i, j, count = 0, k;
    for(i = 0; i < a; i++)
    {
        count = 0;
        if(str[i] != fstr[0])
            printf("%c", str[i]);
        else
        {
            for(j = 0; j < b; j++)
            {
                if(str[i + j] == fstr[j])
                {
                    count++;
                }
            }
            if(count == b)
            {
                for(k = 0; k < c; k++)
                {
                    printf("%c", rstr[k]);
                }
                i = i + b - 1;
            }
            else
            {
                int t = i;
                for( ; i < t + b; i++)
                {
                    printf("%c", str[i]);
                }
                i = i - 1;

            }
        }
    }
}
int main()
{
    char str[100], fstr[100], rstr[100];
    fgets(str, 100, stdin);
    fgets(fstr, 100, stdin);
    fgets(rstr, 100, stdin);
    replace(str, fstr, rstr);
    return 0;
}

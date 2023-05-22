#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char* cpsource, char ch)
{
    int len = strlen(cpsource) - 1;
    int count = 0, i, j;
    int num = 0;
    for(i = 0; i < len; i++)
    {
        if(cpsource[i] == ch)
        {
            for(j = i; j <= len; j++)
            {
                if(cpsource[j] != ch)
                {
                    count = j - i;
                    num = (num > count)? num: count;
                    break;
                }
            }
        }
    }
    for(i = 1; i <= num; i++)
    {
        printf("%c", ch);
    }
}
int main()
{
    char arr[1000], a;
    fgets(arr, 1000, stdin);
    scanf("%c", &a);
    search(arr, a);
    return 0;
}

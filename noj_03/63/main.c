#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i, j = 0;
void fun(char* s, char* t)
{
    int len = strlen(s);
    for(i = 1; i < len; i += 2)
    {
        if(s[i] % 2 != 0)
        {
            t[j] = s[i];
            j++;
        }
    }
}
int main()
{
    char a[100], b[100];
    fgets(a, 100, stdin);
    fun(a, b);
    for(i = 0; i < j; i++)
    {
        printf("%c", b[i]);
    }
    return 0;
}






























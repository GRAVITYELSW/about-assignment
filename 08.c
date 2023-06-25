//逆波兰式

#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000];
    char num[1000], opera[1000];
    fgets(a, 1000, stdin);
    int len = strlen(a);
    int i = 0, j = 0, k = -1;
    while (i < len && a[i] != '\n' && a[i] != '\0')
    {
        if ((a[i] >= '0' && a[i] <= '9') || (a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
        {
            num[j] = a[i];
            i++;
            j++;
        }
        else if (k == -1)
        {
            opera[++k] = a[i];
            i++;
        }
        else
        {
            if (a[i] == '(')
            {
                opera[++k] = a[i];
                i++;
            }
            else if (a[i] == ')')
            {
                while (k>= 0 && opera[k] != '(')
                {
                    num[j] = opera[k];
                    j++;
                    k--;
                }
                i++;
                k--;
            }
            else if (a[i] == '+' || a[i] == '-')
            {
                if (opera[k] == '(')
                {
                    opera[++k] = a[i];
                    i++;
                }
                else if (opera[k] == '*' || opera[k] == '/')
                {
                    num[j] = opera[k];
                    opera[k] = a[i];
                    j++;
                    k--;
                }
                else
                {
                    opera[++k] = a[i];
                    i++;
                }
            }
            else
            {
                opera[++k] = a[i];
                i++;
            }
        }
    }
    while (k >= 0)
    {
        num[j] = opera[k];
        j++;
        k--;
    }
    int ll = 0;
    for (ll = 0; ll < j; ll++)
    {
        printf("%c", num[ll]);
    }
    return 0;
}
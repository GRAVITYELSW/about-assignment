//表达式括号匹配

#include <stdio.h>
#include <string.h>
 
int main()
{
	int i=0, b=0, c=0, d=0;
	char a[1000];
	scanf("%s",a);
	int len = strlen(a);
	for (i = 0; i < len; i++)
	{
		if (a[i] == '(')
		{
			b++;
		}
		else if (a[i] == '[')
		{
			c++;
		}
		else if (a[i] == '{')
		{
			d++;
		}
		else if (a[i] == ')')
		{
			b--;
		}
		else if (a[i] == ']')
		{
			c--;
		}
		else if (a[i] == '}')
		{
			d--;
		}
		else
		{
			continue;
		}
	}
	if (b == 0 && c == 0 && d == 0) 
	    printf("yes");
	else 
	    printf("no");
	return 0;
}
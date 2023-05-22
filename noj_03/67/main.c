#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[100], s2[110];
    int cnt = 0;
    FILE *in, *out;
    in = fopen("DATA5612.CPP", "r");
    if(in != NULL)
    {
        out = fopen("DATA5612.TXT", "w");
        while(!feof(in))
        {
            if(fgets(s1, sizeof(s1) - 1, in) == NULL)
                continue;
            sprintf(s2, "%04d %s", ++cnt, s1);
            fputs(s2, out);
        }
        fclose(out);
        fclose(in);
    }
    return 0;
}

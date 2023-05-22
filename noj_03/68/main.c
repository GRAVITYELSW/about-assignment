#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int num;
    char name[12];
    int score;
};
int main()
{
    int n;
    scanf("%d", &n);
    struct student stu, max;
    FILE *p;
    p = fopen("DATA5614.DB", "wb+");
    while(n--)
    {
        scanf("%d %s %d", &stu.num, stu.name, &stu.score);
        fwrite(&stu, sizeof(struct student), 1, p);
    }
    rewind(p);
    max.score = 0;
    while(!feof(p))
    {
        fread(&stu, sizeof(struct student), 1, p);
        if(stu.score > max.score)
        {
            max.score = stu.score;
            max.num = stu.num;
            strcpy(max.name, stu.name);
        }
    }
    fclose(p);
    printf("%d %s %d", max.num, max.name, max.score);
    return 0;
}

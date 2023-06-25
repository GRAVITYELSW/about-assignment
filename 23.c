//构造哈希表

#include <stdio.h>
#include <stdlib.h>

int* initlist()
{
    int* list = (int*)malloc(sizeof(int) * 11);
    int i;
    for(i = 0; i < 11; i++)
    {
        list[i] = 0;
    }
    return list;
}

int hash(int data)
{
    return (3 * data) % 11;
}
int hash_(int data)
{
    return data % 11;
}

//线性探测法
void puthashlist(int* list, int data, int* asl)
{
    int index = hash(data);
    (*asl)++;
    if(list[index] != 0)
    {
        int count = 1;
        while(list[index] != 0)
        {
            index = hash_(hash(data) + count);
            count++;
            (*asl)++;
        }
    }
    list[index] = data;
}

int main()
{
    int* list = initlist();
    int data[8] = {22,41,53,46,30,13,01,67};
    int i, asl = 0;
    for(i = 0; i < 8; i++)
    {
        puthashlist(list, data[i], &asl);
    }
    printf("%d", asl / 8);
    return 0;
}
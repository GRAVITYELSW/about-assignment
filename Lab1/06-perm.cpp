#include <iostream>
#include <vector>
using namespace std;

int n;
char a[27] = {"abcdefghijklmnopqrstuvwxyz"};
void swap(int i, int j)
{
    char ch;
    ch = a[i];
    a[i] = a[j];
    a[j] = ch;
}
void perm(int i)
{
    if(i == n)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[j];
        }
        cout << endl;
    }
    else 
    {
        for(int k = i; k < n; k++)
        {
            swap(i, k); //交换2者的值
            perm(i + 1);
            swap(i, k); //交换回来
        }
    }
}
int main()
{
    cin >> n;
    perm(0);
    return 0;
}
//求第k小数

#include <iostream>
using namespace std;

int partition(int arr[], int i, int j)
{
    int x = arr[i];
    while(i < j)
    {
        while (i < j && arr[j] >= x)
        {
            j--;
        }
        if(i < j)
        {
            arr[i] = arr[j];
            i++;
        }
        while(i < j && arr[i] < x)
        {
            i++;
        }
        if(i < j)
        {
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = x;
    return i;
}

void quicksort(int arr[], int i, int j)
{
    if(i < j)
    {
        int index = partition(arr, i , j);
        quicksort(arr, i, index - 1);
        quicksort(arr, index + 1, j);  
    }
}

int main()
{
    int n, k;
    int num[10000];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cin >> k;
    quicksort(num, 0, n - 1);
    cout << num[k - 1];
    return 0;
}
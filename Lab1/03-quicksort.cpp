#include <iostream>
using namespace std;

//划分左右子表，i是前面的指针，j是后面的指针
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
    int n, i = 0;
    int arr[10000];
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
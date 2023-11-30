#include <iostream>
using namespace std;

void merge(int a[], int low, int mid, int high)
{
    int* tmp = new int[high - low + 1];
    int i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
        {
            tmp[k] = a[i];
            i++, k++;
        }
        else
        {
            tmp[k] = a[j];
            j++, k++;
        }
    }
    while(i <= mid)
    {
        tmp[k] = a[i];
        i++, k++;
    }
    while(j <= high)
    {
        tmp[k] = a[j];
        j++, k++;
    }
    for(k = 0, i = low; i <= high; i++, k++)
    {
        a[i] = tmp[k];
    }
    delete[] tmp;
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
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
    mergesort(arr, 0, n - 1);
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
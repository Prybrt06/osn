#include <stdio.h>

void Merge(int arr[], int low, int high, int mid)
{
    int left = mid - low + 1;
    int right = high - mid;
    int Larr[left], Rarr[right];
    for (int i = 0; i < left; i++)
        Larr[i] = arr[low + i];
    for (int i = 0; i < right; i++)
        Rarr[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = low;
    while (i < left || j < right)
    {
        if (Larr[i] <= Rarr[j])
            arr[k++] = Larr[i++];
        else
            arr[k++] = Rarr[j++];
    }
    while (i < left)
        arr[k++] = Larr[i++];
    while (j < right)
        arr[k++] = Rarr[j++];
}

void MergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, high, mid);
}

void BubbleSort(int arr[],int n)
{
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf(" %d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf(" %d", &arr[i]);
    MergeSort(arr, 0, n - 1);
    // BubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

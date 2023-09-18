#include <stdio.h>
#include <stdlib.h>

int binarysearch(int arr[], int ele,int size )
{
    int mid, low,high;
low=0;
high=size-1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == ele)
        {
            printf("Element found at position %d", mid+1);
            return 0;
        }
        else
        {
            if (arr[mid] < ele)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    printf("Element not found");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size=sizeof(arr)/sizeof(int);
    binarysearch(arr,0,size);
     return 0;
}
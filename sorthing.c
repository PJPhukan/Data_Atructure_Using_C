#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void display(int *A, int n);
void seletion_sort(int *A, int n); // not Stable,  not adaptive ,time complexsity O(n^2)
void bubble_sort(int *A, int n);   // Stable, by default not adaptive but we can make it adaptive,time complexsity O(n^2)
void bubble_sortAdap(int *A, int n);
void insertion_sort(int *A, int n); // stable,adaptive,time complexity O(n^2)
void quickshort(int A[], int low, int high);
void margaeshort(int A[], int low, int high);
void countsort(int A[],int n);


int main()
{
    int A[] = {2, 0, 1, 13, 5, 23, 5, 7};
    int n = 8;
    printf("Before sorthing the Array...\n");
    display(A, n);
    printf("\nAfter sorthing the Array...\n");
    countsort(A,n);
        // margaeshort(A, 0, n - 1);
        // quickshort(A, 0, n - 1);
        // seletion_sort(A, n);
        // bubble_sort(A, n);
        // bubble_sortAdap(A, n);
        // insertion_sort(A,n);
        display(A, n);
    return 0;
}

void display(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
}
void seletion_sort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}
void bubble_sort(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int temp;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
void bubble_sortAdap(int *A, int n)
{

    int temp, adaptive = 0;
    for (int i = 0; i < n - 1; i++)
    {
        adaptive = 1;
        printf("\nNumeber of pass = %d\n", i);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                adaptive = 0;
            }
        }
        if (adaptive)
        {
            return;
        }
    }
}
void insertion_sort(int *A, int n)
{
    int j, key;
    for (int i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
int partition(int *A, int low, int high)
{
    int pivote = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivote)
        {
            i++;
        }
        while (A[j] > pivote)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void quickshort(int A[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickshort(A, low, partitionIndex - 1);
        quickshort(A, partitionIndex + 1, high);
    }
}
void marge(int *A, int low, int mid, int high){
    int i = low, j = mid + 1, B[high + 1], k = 0;
    while (i <= mid && j <= high)
    {
        if (A[i] > A[j])
        {
            B[k] = A[j];
            k++, j++;
        }
        else
        {
            B[k] = A[i];
            k++, i++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++, i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++, j++;
    }

    for (i = low, k = 0; i <= high;i++,k++)
    {
        A[i] = B[k];
    }}
void margaeshort(int A[], int low, int high){
    if (high == low)
    {
        return;
    }
    int mid = (low + high) / 2;
    margaeshort(A, low, mid);
    margaeshort(A, mid + 1, high);
    marge(A, low, mid, high);}
int maxterm (int A[],int n){
    int max=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(max<A[i]){
            max=A[i];
        }
    }
    return max;
    
}
void countsort(int A[], int n)
{
    int max=maxterm(A,n),i,j;
    int* count=(int*)malloc((max+1)*sizeof(int));
    for ( i = 0; i < max+1; i++)
    {
        count[i]=0;
    }
    
    for ( i = 0; i < n; i++)
    {
        count[A[i]]=count[A[i]]+1;
    }
    j=0;
    i=0;
    while (i<=max)
    {
        if(count[i]>0){
            A[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
        }
    }
    
}
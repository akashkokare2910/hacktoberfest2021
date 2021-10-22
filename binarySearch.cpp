#include <iostream>
#include <stdio.h>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;

};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

// Iterative way
int binarySearch(struct Array arr, int key )
{
    int low, mid, high;
    low=0;
    high= arr.length - 1;
    while(low <= high )
    {
        mid = (low + high) / 2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            high = mid - 1;
        else
            low  = mid + 1;
    }
return -1;
}

// Recursive way 

int RBinSearch(int a[], int low, int high, int key)
{
    int mid;

    if(low <= high)
    {
        mid = (low + high) / 2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return RBinSearch(a, low, mid-1, key);
        else
            return RBinSearch(a, mid+1, high, key);
    }
    return -1;
} 
int main()
{
    // struct Array arr{{2,4,6,8,10,12,14,16,18,20,22},20,11};   // Iterative way 
    // printf("%d", binarySearch(arr,19));
    
    struct Array arr{{2,4,6,8,10,12,14,16,18,20,22},20,11};
    printf("%d", RBinSearch(arr.A, 0, arr.length, 19));
    Display(arr);
    return 0;

}
#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int l, int r, int x)
{

    if (r >= l)
    {
        int mid = l + (r - l)/2;

        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid-1, x);
        }

        return binarySearch(arr, mid +1, r, x);
        
    }

    return -1;  
        
}



int main()
{
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int x = 500;

    int result = binarySearch(arr, 0, n-1, x);
    
    if (result == - 1)
    {
        printf("The element is not present in the array");
    }
    else
    {
        printf("The array is present at index value %d", result);
    }

    return 0;
}

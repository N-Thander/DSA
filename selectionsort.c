#include<stdio.h>
#include<stdlib.h>

void swap(int* xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for ( i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }

            if (min_idx != i)
            {
                swap(&arr[min_idx], &arr[i]);
            }
            
        }
    }

}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    
}


int main()
{
    int members;
    printf("Enter the no of elements of the array: ");
    scanf("%d", &members);

    int arr[members];

    for (int i = 0; i < members; i++)
    {
        printf("Enter values: ");
        scanf("%d", &arr[i]);
    }

    printf("The array is: \n");
    printArray(arr, members);


    selectionSort(arr, members);

    printf("The sorted array is :");
    printArray(arr, members);  

    return 0;

}

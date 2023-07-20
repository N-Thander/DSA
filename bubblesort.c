#include<stdio.h>
#include<stdlib.h>

void swap(int* xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }            
        }        
    }    
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i< size; i++)
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


    bubbleSort(arr, members);

    printf("The sorted array is :");
    printArray(arr, members); 



    return 0;
}

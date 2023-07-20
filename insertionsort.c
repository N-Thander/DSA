#include<stdio.h>


void insertionSort(int arr[], int n)
{
    int i, key, j;
    for ( i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1; 
        }
        arr[j + 1] = key;        
    }

}

void printArray(int arr[], int n)
{
    int i;
    for ( i = 0; i < n; i++)
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

    insertionSort(arr, members);

    printf("The sorted array is: ");
    printArray(arr, members);

    return 0;
}

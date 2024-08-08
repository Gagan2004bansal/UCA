#include <stdio.h>
void SelectionSort(int *arr, int n);
int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i<n; i++){
        int input;
        scanf("%d", &input);
        arr[i] = input;
    }

    SelectionSort(arr, n);

    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
void SelectionSort(int *arr, int n)
{
    for(int i = 0; i<n-1; i++)
    {
        int minIndex = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
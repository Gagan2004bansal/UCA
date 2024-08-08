#include <stdio.h>
#include <stdbool.h>
void BubbleSort(int *arr, int n);
int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i<n; i++){
        int input;
        scanf("%d", &input);
        arr[i] = input;
    }

    BubbleSort(arr, n);

    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
void BubbleSort(int *arr, int n){
    for(int i = 0; i<n-1; i++){
        bool swapped = false;
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swapped = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(swapped == false){
            return;
        }
    }
}

// done on 8 August 2024
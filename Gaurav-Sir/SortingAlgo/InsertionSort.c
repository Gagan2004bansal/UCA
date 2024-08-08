#include <stdio.h>
void InsertionSort(int *arr, int n);
int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i<n; i++){
        int input;
        scanf("%d", &input);
        arr[i] = input;
    }

    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
void InsertionSort(int *arr, int n){
    
}
#include <stdio.h>
void MergeSort(int *arr, int *aux, int s, int e);
int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i<n; i++){
        int input;
        scanf("%d", &input);
        arr[i] = input;
    }

    MergeSort(arr, arr, 0, n-1);

    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("/n");

    return 0;
}
void MergeSort(int *arr, int* aux, int s, int e){
    if(s > e){
        return;
    }

    int mid = s + (e - s)/2;

    MergeSort(arr, aux, s, mid);
    MergeSort(arr, aux, mid+1, e);

    MergeArr(arr, aux, s, mid, e);
}
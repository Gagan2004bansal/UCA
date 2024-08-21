#include <stdio.h>
void swap(int a, int b){
    int temp = a;
    a = b;
    b = a;
}
void quicksort_rec(int *arr, int left, int right){
    if(left >= right) return;

    int pivot = arr[left];
    int i = left + 1;

    for(int j = left + 1; j<=right; j++){
        if(arr[j] < pivot){
            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[left], arr[--i]);

    quicksort_rec(arr, left, i-1);
    quicksort_rec(arr, i+1, right);
}
void quick_sort(int n, int *arr){
    quicksort_rec(arr, 0, n-1);
}
int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i = 0; i<n; i++){
        int input;
        scanf("%d", &input);
        
    }
    return 0; 
}


// 13 August 2024 


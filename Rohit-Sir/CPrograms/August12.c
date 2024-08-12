// #include<stdio.h>
// int add(int a, int b){
//     return (a + b);
// }
// int subtract(int a, int b){
//     return (a - b);
// }
// int multiply(int a, int b){
//     return (a * b);
// }
// int divide(int a, int b){
//     return (a/b);
// }
// int performOpr(int a, int b, int(*operation)(int, int)){
//     return operation(a, b);
// }
// int main(){
//     int a, b;
//     scanf("%d", &a);
//     scanf("%d", &b);

//     int ans = performOpr(a, b, multiply); 
//     printf("%d \n", ans);

//     return 0;
// }


#include <stdio.h>
#include <stdbool.h>
void sort(int n, int *arr, void (*compare)(int, int*)){
    compare(n, arr);
}
void sortAsc(int n, int *arr){
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
    }
}
void sortDsc(int n, int *arr){
    for(int i = 0; i<n-1; i++){
        bool swapped = false;
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] < arr[j+1]){
                swapped = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i<n; i++){
        int input;
        scanf("%d", &input);
        arr[i] = input;
    }

    sort(n, arr, sortDsc);

    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
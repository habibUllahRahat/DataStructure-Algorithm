#include <stdio.h>

void selectionSort(int a[], int n) {
    int j, i;

    for(i = 0;  i < n - 1 ; i++) {
        int currIndex = i;
        for(j = i + 1;  j < n ; j++) {
            if(a[j] < a[currIndex]) {
                currIndex = j;
            }
        }
        if(currIndex != i) {
            a[i] += a[currIndex];
            a[currIndex] = a[i] - a[currIndex];
            a[i] -= a[currIndex];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
#include <stdio.h>

void insertionSort(int a[], int n) {
    int j, i;

    for(i = 1;  i < n ; i++) {
        int currIndexValue = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > currIndexValue) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = currIndexValue;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
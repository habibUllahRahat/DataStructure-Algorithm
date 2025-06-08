#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *num;
    int *currTop;
} ex;

ex CreateEx(int size) {
    ex arr;
    arr.num = (int *)malloc(sizeof(int) * size);
    arr.currTop = arr.num;
}


int main() {
    int n;
    scanf("%d", &n);
    printf("%d", n);
    return 0;
}
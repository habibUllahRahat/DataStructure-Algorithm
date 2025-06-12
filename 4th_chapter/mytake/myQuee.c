#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *data;
    int tail;
} Quee;
Quee* CreateQuee(int size) {
    if(size < 1) {
        printf("Size Should be > 1");
        return NULL;
    }
    Quee * q = (Quee*)malloc(sizeof(Quee));
    if(q == NULL) {
        printf("Error while creating q");
        return NULL;
    }
    q->data = (int*)malloc(size * sizeof(int));
    if(q->data == NULL) {
        printf("Error while allocating memory for q->data");
        return NULL;
    }
    q->tail = 0;
    return q;
}

void enquee(int item, Quee*q, int*size) {
    if(q->tail + 1 == *size) {
        q->data = realloc(q->data, (*size + 1) * sizeof(int));
        if(q->data == NULL) {
            printf("Error while reallocating q->");
            return;
        }
        *size += 1;
    }
    q->data[q->tail++] = item;
}

int dequee(Quee*q, int *size) {
    if(q->tail == 0) {
        printf("Quee is empty ");
        return -1;
    }
    int item = q->data[0];
    for(int i = 0; i < q->tail; i++) {
        q->data[i] = q->data[i + 1];
    }
    q->tail--;
    *size -= 1;
    return item;
}

int main() {
    int n;
    scanf("%d", &n);
    Quee *qu = CreateQuee(n);
    enquee(10, qu, &n);
    enquee(11, qu, &n);
    enquee(12, qu, &n);
    enquee(13, qu, &n);
    enquee(14, qu, &n);
    enquee(15, qu, &n);
    printf("%d\n", dequee(qu, &n));
    printf("%d\n", dequee(qu, &n));
    printf("%d\n", dequee(qu, &n));
    printf("%d\n", dequee(qu, &n));
    printf("%d\n", dequee(qu, &n));
    printf("%d\n", dequee(qu, &n));
    printf("%d\n", dequee(qu, &n));
    free(qu);
    return 0;
}
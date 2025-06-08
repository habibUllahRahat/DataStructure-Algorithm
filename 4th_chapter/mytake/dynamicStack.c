#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * data;
    int count;
} Stack;

Stack * CreateStack(int size) {
    if(size < 1) {
        printf("Size Input atlest 1\n");
    }
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if(stack == NULL) {
        printf("Failed to allocate memory for Stack\n");
        return NULL;
    }
    stack->data = (int *)malloc(sizeof(int) * size);
    if(stack->data == NULL) {
        printf("Failed to allocate memory for Stack data\n");
        free(stack);
        return NULL;
    }
    stack->count = 0;
    return stack;
}

void push(Stack * s, int item, int* size) {
    if(s->count + 1 == *size) {
        int newSize = sizeof(int) * s->count + 1;
        s->data = realloc(s->data, (sizeof(int) * newSize));
        if(s->data == NULL) {
            printf("Something went wrong while reallocating\n");
            return;
        } else {
            *size += 1;
            printf("Reallocated new size : %d\n", *size);
        }
    }
    s->data[s->count] = item;
    s->count++;
}

void push1(Stack * s, int item, int* size) {
    int newSize = sizeof(int) * s->count + 1;
    s->data = realloc(s->data, (sizeof(int) * newSize));
    if(s->data == NULL) {
        printf("Something went wrong while reallocating\n");
        return;
    } else {
        *size += 1;
        printf("Reallocated new size : %d\n", *size);
    }

    s->data[s->count] = item;
    s->count++;
}

int pop(Stack * s, int *size) {
    if(s->count == 0) {
        printf("The Stack Is Empty size = %d\n", *size);
        return -1;
    }
    s->count--;
    *size -= 1;
    s->data = realloc(s->data, (*size * sizeof(int)));
    return  s->data[s->count];
}

int main() {
    int n;
    scanf("%d", &n);
    Stack * s = CreateStack(n);

    push(s, 10, &n);
    push(s, 11, &n);
    push(s, 12, &n);
    push(s, 13, &n);
    push(s, 14, &n);
    push(s, 15, &n);
    push(s, 16, &n);
    push(s, 17, &n);
    push(s, 18, &n);

    printf("%d\n", pop(s, &n));//18
    printf("%d\n", pop(s, &n));//17
    printf("%d\n", pop(s, &n));//16
    printf("%d\n", pop(s, &n));//15
    printf("%d\n", pop(s, &n));//14
    printf("%d\n", pop(s, &n));//13
    printf("%d\n", pop(s, &n));//12
    printf("%d\n", pop(s, &n));//11
    printf("%d\n", pop(s, &n));//10
    printf("%d\n", pop(s, &n));

    free(s);
    return 0;
}
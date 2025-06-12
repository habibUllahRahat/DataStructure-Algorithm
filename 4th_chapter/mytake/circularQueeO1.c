#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *data;
    int head, tail, storage;
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
    q->storage = size;
    q->data = (int*)malloc(q->storage * sizeof(int));
    if(q->data == NULL) {
        printf("Error while allocating memory for q->data");
        return NULL;
    }
    q->head = 0;
    q->tail = 0;
    q->storage += 1;
    return q;
}

void enquee(int item, Quee*q) {

    // if(q->tail + 1  == q->head) {
    // !Upper condition won't work cause
    /*
        when "tail" is equal to "storage-1"(storage = mainSize+1) then if we try to compare only "tail+1" it will wont allocate data accurately and quee will be full
        like:
        if given size=> 2
        so,
        storage = 2+1
        head=0;
        tail=0;
        enquee check will be:
        if(q->tail + 1  == q->head) >=>
        1st call:
            if(0+1==0)
            :
            tail= 0+1 % 3 = 1;
        2nd call:
            if(1+1==0)
            :
            tail= 1+1 % 3 = 2;
        3rd call:
            if(2+1==0) // ! Here it will be create the problem cause here it should be full and return
            :
            tail= 2+1 % 3 = 1;//! because of condition true "tail" will set at 0 so Quee will be rewritten
    ==============================================================================
    for Solve this we need to use:
        if((q->tail + 1) % q->storage  == q->head) >=>
        1st call:
            if(0+1 % 3==0)
            :
            tail= 0+1 % 3 = 1;
        2nd call:
            if(1+1 % 3==0)
            :
            tail= 1+1 % 3 = 2;
        3rd call:
            if(2+1 % 3==0) // * Here it solves the problem cause 2+1 % 3 = 0 so it won't allow to set tail at 0
            :
            tail= 2+1 % 3 = 0;// * so it won't be exuted and quee will be full

    */
    if((q->tail + 1) % q->storage  == q->head) {
        printf("Quee is Full while item =>%d\n", item);
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % q->storage ;
}

int dequee(Quee*q) {
    if(q->tail  == q->head) {
        printf("Quee is empty ");
        return -1;
    }
    int item = q->data[q->head];
    q->head = (q->head + 1) % q->storage ;
    return item;
}

int main() {
    int n;
    scanf("%d", &n);
    Quee *qu = CreateQuee(n);
    enquee(10, qu);
    enquee(11, qu);
    enquee(12, qu);
    enquee(13, qu);
    enquee(14, qu);
    enquee(15, qu);
    printf("%d\n", dequee(qu));
    printf("%d\n", dequee(qu));
    printf("%d\n", dequee(qu));
    printf("%d\n", dequee(qu));
    printf("%d\n", dequee(qu));
    printf("%d\n", dequee(qu));
    printf("%d\n", dequee(qu));
    free(qu);
    return 0;
}
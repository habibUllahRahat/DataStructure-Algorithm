//This a program about data structure Queue using c language;
/***
Characteristics of Queue:
1. It's maintain first in first out (FIFO) data input output methods.
2. The method for input data is known as enqueue.
3. The method for output known as dequeue.
4. There are two variable need to trace the data of A Queue:
        i. head / front
        ii. tail / end
5. Regular queue use
 condition like
    if( @tail+1 == @head ){
       printf("queue is full")

    }
6. Circular Queue this type of queue use numbering mod system it create like loop effect
        like :
        @tail = @tail+1 % 5 [ 1st time tail = 1 -> 2 -> -> 3 -> 4 -> 0 -> 1]

7. According to condition:
   if we wanna store 5 data we to use an array which have 0-4 index.
   so if we want to store data we have to update tail of structure by

        # @tail+1 % 5[cause when it will be 5 the mod result will be 0 it will create a circular numbering loop]

        # so if enter 3 new data the @head will 0 cause we didn't dequeue any data so far and @tail will be 3

        # and if we dequeue 3 data then @head will be 3 now @tail == @head. So, now the we know that the queue is empty.
        # now if we store more 1 new data the @tail will be 4 and and if we add 4 more new data updated @tail will be (0,1,2,3) [cause when we store new data @tail = @tail+1 % 5]\
            so it will create a problem it will be hard to identify is queue empty or full.

        #for resolve this we have to check every time that is @tail+1 % @QSize + 1 == @head [we don't need to take one more ] :

            if ( @tail+1 % @QSize + 1 == @head){
                 printf("queue is full")
            }





*/

#include <stdio.h>
#define QSize 5

typedef struct {
    int data[QSize+1];
    int head, tail;
}Queue;

void enqueue (Queue *q, int item){

    if((q->tail+1 )% (QSize+1)== q->head){
         printf("\n Queue is full !! and \n Tail is now: %d \n Head is now: %d \n ",q->tail,q->head);
    }else{
    printf("# Equeued item is : %d \n Tail is now: %d  \n Head is now: %d \n\n",item,(q->tail+1)%(QSize+1),q->head);
    q->data[q->tail] = item;
    q->tail=(q->tail+1)%(QSize+1);
    }
}

int dequeue (Queue * dq){
    int item;
    if (dq->tail==dq->head){
        printf("Queue is empty !! cause \n Tail is now: %d \n Head is now: %d \n",dq->tail,dq->head);
    }else{
    item = dq->data[dq->head];
    dq->head=(dq->head+1 )% (QSize+1);
    return item;
    }
}

void printQueue(Queue *q ,int item){
    printf("\n===========================\n");
    printf("The returned value is : %d \n Tail is now: %d \n Head is now: %d", item, q->tail, q->head);
    printf("\n===========================\n\n");
}

int main(){
    Queue myQ;
    int item;
    myQ.head=0,myQ.tail=0;
    enqueue(&myQ,11);
    enqueue(&myQ,12);
    enqueue(&myQ,13);
    enqueue(&myQ,14);
    enqueue(&myQ,15);
    enqueue(&myQ,16);
    enqueue(&myQ,17);
    printf("\n####################################################################\n\n");
    item=dequeue(&myQ);
    printQueue(&myQ,item);
    item=dequeue(&myQ);
    printQueue(&myQ,item);
    item=dequeue(&myQ);
    printQueue(&myQ,item);
    item=dequeue(&myQ);
    printQueue(&myQ,item);
    item=dequeue(&myQ);
    printQueue(&myQ,item);
    enqueue(&myQ,17);
    item=dequeue(&myQ);
    printQueue(&myQ,item);
    enqueue(&myQ,77);
    item=dequeue(&myQ);
    printQueue(&myQ,item);

    enqueue(&myQ,11);
    item=dequeue(&myQ);
    printQueue(&myQ,item);

    enqueue(&myQ,12);
    item=dequeue(&myQ);
    printQueue(&myQ,item);

    enqueue(&myQ,13);
    item=dequeue(&myQ);
    printQueue(&myQ,item);

    enqueue(&myQ,14);
    item=dequeue(&myQ);
    printQueue(&myQ,item);

    enqueue(&myQ,15);
    item=dequeue(&myQ);
    printQueue(&myQ,item);

    return 0;
}

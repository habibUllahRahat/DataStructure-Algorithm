#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *createNode (int item, Node *next){

    Node *newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL){
            printf("Error!! could not create a Node");
            exit(1);
        }
        newNode->data = item;
        newNode->next = NULL;
}
Node *prepend(Node *head,int item)
{
    Node *newNode = createNode(item,head);
    return newNode;
}



int main(){
    Node *n1,*n2,*head,*n3;

    n1 = createNode(10, NULL);
    head = n1;

    head = prepend(head,20);

    n2=head;
    printf("Data of n2 : %d\n", head->next->data);

    n2->next=n1;
    printf("Data of n 3 : %d\n", n2->next->data);

    return 0;


}

#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;

struct node {
    int data;
    Node * nextNodePtr;
};

Node * create_node(int data, Node* nextNodePtr) {
    Node * newNode = (Node *) malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Error While Allocating Space For New Node\n");
        return NULL;
    }
    newNode->data = data;
    newNode->nextNodePtr = nextNodePtr;
    return newNode;
}

Node * preAppend(Node* head, int data) {
    Node * newHeadNode = create_node(data, head);
    return newHeadNode;
}

Node * append(Node* head, int data) {
    Node * newNode = create_node(data, NULL);
    if(head->nextNodePtr == NULL) {
        head->nextNodePtr = newNode;
        return newNode;
    }
    Node * curr_node = head;
    while(curr_node->nextNodePtr != NULL) {
        curr_node = curr_node->nextNodePtr;
    }
    curr_node->nextNodePtr = newNode;
    return newNode;
}

void print_node(Node* head) {
    Node * curr_node = head;
    int i = 0;
    while(curr_node->nextNodePtr != NULL) {
        printf("%d - Data => %d,Next => %p\n", i++, curr_node->data, curr_node->nextNodePtr);
        curr_node = curr_node->nextNodePtr;
    }
    printf("%d - Data => %d,Next => %p\n", i++, curr_node->data, curr_node->nextNodePtr);
}

Node *insertNode(Node *head, Node *afterNode, int data) {
    Node *newNode = create_node(data, afterNode), *curr_node = head;
    while(curr_node->nextNodePtr != afterNode) {
        curr_node = curr_node->nextNodePtr;
    }
    curr_node->nextNodePtr = newNode;
    return newNode;
}


Node *removeNode(Node *head, Node *toRemove) {
    if(head == toRemove) {
        head = toRemove->nextNodePtr;
        free(toRemove);
        return head;
    }
    Node * curr_node = head;
    while(curr_node->nextNodePtr != toRemove) {
        curr_node = curr_node->nextNodePtr;
    }
    curr_node->nextNodePtr = toRemove->nextNodePtr;
    free(toRemove);
    return head;
}

int main() {
    Node *head, *n1, *n2, *n3;// Here we are declearing the head and other nodes
    // Create the first node and append others
    // to the linked list
    head = create_node(10, NULL);
    n1 = append(head, 20);
    n2 = append(head, 25);
    head = preAppend(head, 30);// Because we are preappending the head, it will be the first node and the previous head will be the second node that won't be stored in any variable we created inside main function.

    // print_node(head);
    // head=removeNode(head, n2);
    n3= insertNode(head, n1, 320);
    print_node(head);
    return 0;
}
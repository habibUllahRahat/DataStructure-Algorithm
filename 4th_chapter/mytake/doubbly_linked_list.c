#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;

struct node {
  Node *prevPtr;
  int data;
  Node *nextPtr;
};

Node *createNode(int data, Node *prevPtr, Node *nextPtr) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("An Error Occur While Creating New Node");
    return NULL;
  }
  newNode->data = data;
  newNode->nextPtr = nextPtr;
  newNode->prevPtr = prevPtr;
  return newNode;
}

Node *preAppend(int data, Node *head) {

  Node *newHeadNode = createNode(data, NULL, head);
  if (head == NULL) {
    return newHeadNode;
  }
  head->prevPtr = newHeadNode;
  return newHeadNode;
}

Node *append(int data, Node *head) {
  Node *currLastNode = head;
  while (currLastNode->nextPtr != NULL) {
    currLastNode = currLastNode->nextPtr;
  }
  Node *newEndNode = createNode(data, currLastNode, NULL);
  currLastNode->nextPtr = newEndNode;
  return newEndNode;
}

void printNodeLastToFirst(Node *lastNode) {
  Node *currNode = lastNode;
  int i = 0;
  printf("Last To First print\n==========================\n");
  while (currNode->prevPtr != NULL) {
    printf("%d. Data => %d, Next => %p, Prev => %p\n", i++, currNode->data,
           currNode->nextPtr, currNode->prevPtr);
    currNode = currNode->prevPtr;
  }
  printf("%d. Data => %d, Next => %p, Prev => %p\n", i++, currNode->data,
         currNode->nextPtr, currNode->prevPtr);
}

void pritNodeFirstToLast(Node *head) {
  Node *currNode = head;
  int i = 0;
  printf("First To Last print\n==========================\n");
  while (currNode->nextPtr != NULL) {
    printf("%d. Data => %d, Next => %p, Prev => %p\n", i++, currNode->data,
           currNode->nextPtr, currNode->prevPtr);
    currNode = currNode->nextPtr;
  }
  printf("%d. Prev => %p, Data => %d, Next => %p\n", i++, currNode->nextPtr,
         currNode->data, currNode->prevPtr);
}

Node *insertNode(Node *nodeAfter, int data) {
  Node *newNode = createNode(data, nodeAfter, nodeAfter->nextPtr);
  nodeAfter->nextPtr = newNode;
  return newNode;
}

Node *removeNode(Node *head, Node *nodedlt) {
  if (head == nodedlt) {
    head = nodedlt->nextPtr;
    head->prevPtr = NULL;
    free(nodedlt);
    return head;
  }

  Node *prevNode = nodedlt->prevPtr;
  Node *nextNode = nodedlt->nextPtr;

  prevNode->nextPtr = nextNode;
  nextNode->prevPtr = prevNode;

  free(nodedlt);

  return head;
}

int main() {
  Node *head = createNode(1, NULL, NULL);
  Node *second = append(2, head);
  Node *third = append(3, head);
  Node *fourth = append(4, head);
  Node *first = head;
  head = preAppend(0, head);
  // printNodeLastToFirst(fourth);
  Node *secondAft = insertNode(second, 100);
  pritNodeFirstToLast(head);

  printf("After delete!!\n");

  head = removeNode(head, second);
  pritNodeFirstToLast(head);
  printf("Now we are trying to print deleted second node\n%d. Data => %d, "
         "Next => %p, Prev => %p\n",
         1, second->data, second->nextPtr,
         second->prevPtr); // It will show  some garbage value;

  return 0;
}
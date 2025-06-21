#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;

struct node {
  int data;
  Node *l, *r;
};

Node *createNode(int data, Node *l, Node *r) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Somthing went wrong while creating A Node");
    return NULL;
  }
  return newNode;
}

int main() { return 0; }
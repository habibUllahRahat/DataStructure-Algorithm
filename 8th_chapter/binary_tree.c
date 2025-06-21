#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;

struct node {
  int data;
  Node *l, *r;
};

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Somthing went wrong while creating A Node");
    return NULL;
  }
  newNode->data = data;
  newNode->l = NULL;
  newNode->r = NULL;
  return newNode;
}

void pre_order_Traverse(Node *root) {
    if (root->l != NULL) {
        pre_order_Traverse(root->l);
    }
    if (root->r != NULL) {
        pre_order_Traverse(root->r);
    }
    printf(" %d", root->data);
}

Node *tree() {
  Node *one = createNode(1), *two = createNode(2), *three = createNode(3),
       *four = createNode(4), *five = createNode(5), *six = createNode(6),
       *seven = createNode(7), *eight = createNode(8), *nine = createNode(9),
       *ten = createNode(10), *eleven = createNode(11),
       *twelve = createNode(12);

  one->l = two;
  one->r = three;

  two->l = four;
  two->r = five;

  three->l = six;
  three->r = seven;

  four->l = eight;
  four->r = nine;

  five->l = ten;
  five->r = eleven;

  seven->r = twelve;
  return one;
}

int main() {
  Node *root = tree();
  pre_order_Traverse(root);
  return 0;
}
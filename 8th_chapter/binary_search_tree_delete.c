#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
  int data;
  Node *parent, *left, *right;
};

Node *create_a_node(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Error occured while trying to create node for => %d\n", data);
    return NULL;
  }
  newNode->data = data;
  newNode->left = newNode->parent = newNode->right = NULL;
  return newNode;
}

void add_left(Node *node, Node *child) {
  node->left = child;
  if (child !=
      NULL) { // cause we can use this function as delete left node and in that
              // case child will be NULL so we don't need to set parent.
    child->parent = node;
  }
}
void add_right(Node *node, Node *child) {
  node->right = child;
  if (child !=
      NULL) { // cause we can use this function as delete right node and in that
              // case child will be NULL so we don't need to set parent.
    child->parent = node;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d", n);
  return 0;
}
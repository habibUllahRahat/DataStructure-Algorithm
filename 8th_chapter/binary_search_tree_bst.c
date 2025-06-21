#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;

struct node {
  int data;
  Node *l, *r, *prnt;
};

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Something went wrong\n");
    return NULL;
  }
  newNode->data = data;
  newNode->l = newNode->prnt = newNode->r = NULL;
  return newNode;
}

void add_left_child(Node *prnt, Node *l_child) {
  prnt->l = l_child;
  if (l_child != NULL) { // If l_child is not NULL, set its parent pointer
    l_child->prnt = prnt;
  }
}

void add_right_child(Node *prnt, Node *r_child) {
  prnt->l = r_child;
  if (r_child != NULL) { // If r_child is not NULL, set its parent pointer
    r_child->prnt = prnt;
  }
}

Node *binary_search_tree_insrt(Node *root, Node *node) {
  Node *parent_node, *curr_node;
  if (root == NULL) {
    root = node;
    return root;
  }
  curr_node = root;
  // here we are finding out suitable parent for the node is given
  while (curr_node != NULL) {
    parent_node = curr_node;
    if (node->data < parent_node->data) {
      curr_node = curr_node->l;
    } else {
      curr_node = curr_node->r;
    }
  }
  if (node->data < parent_node->data) {
    parent_node->l = node;
    node->prnt = parent_node;
  } else {
    ;
    parent_node->r = node;
    node->prnt = parent_node;
  }
  return root;
}
void pre_order_Traverse(Node *root) {
  if (root->l != NULL) {
    pre_order_Traverse(root->l);
  }
  printf("%d ", root->data);
  if (root->r != NULL) {
    pre_order_Traverse(root->r);
  }
}

Node *bst_search(Node *root, int item) {
  Node *node = root;
  
  while ( node != NULL) {
    if (node->data == item) {
      return node;
    }
    if (node->data > item) {
      node = node->l;
    } else {
      node = node->r;
    }
  }
  return node;
}
int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  Node *root = createNode(arr[5]);
  printf("The root is %d\n", root->data);
  for (int i = 0; i < n; i++) {
    if (i == 5) {
      continue;
    }
    Node *node = createNode(arr[i]);
    binary_search_tree_insrt(root, node);
  }

  pre_order_Traverse(root);
  Node *search_node = bst_search(root, 10);
  if (search_node != NULL) {
    printf("\nFound and the value is \n _%d_\n/    \\\n%d   %d", search_node->data,
           search_node->l ? search_node->l->data : -1,
           search_node->r ? search_node->r->data : -1);
  } else {
    printf("\nNot Found");
  }
  return 0;
}
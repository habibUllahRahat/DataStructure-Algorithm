#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node {
  int data;
  Node *left, *right, *parent;
};

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Error while allocating space for : %d", data);
    return NULL;
  }
  newNode->data = data;
  newNode->left = newNode->right = newNode->parent = NULL;
  return newNode;
}

Node *bst_insert(Node *root, Node *nodeToBeAdded) {
  if (root == NULL) {
    root = nodeToBeAdded;
    return nodeToBeAdded;
  }
  Node *parent_node, *current_node = root;
  while (current_node != NULL) {
    parent_node = current_node;
    if (nodeToBeAdded->data < parent_node->data) {
      current_node = parent_node->left;
    } else {
      current_node = parent_node->right;
    }
  }
  if (nodeToBeAdded->data < parent_node->data) {
    nodeToBeAdded->parent = parent_node;
    parent_node->left = nodeToBeAdded;
  } else {
    nodeToBeAdded->parent = parent_node;
    parent_node->right = nodeToBeAdded;
  }
  return root;
}

Node *create_BST() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  Node *root = createNode(50), *node;

  for (int i = 0; i < n; i++) {

    node = createNode(arr[i]);
    root = bst_insert(root, node);
  }
  return root;
}

void bst_in_order_print(Node *root) {
  if (root->left != NULL) {
    bst_in_order_print(root->left);
  }
  if (root->right != NULL) {
    bst_in_order_print(root->right);
  }
  printf("%d ", root->data);
}

Node *bst_search_a_node(Node *root, int item) {
  Node *node = root;
  while (node != NULL) {
    if (node->data == item) {
      return node;
    }
    if (item < node->data) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return node;
}

int main() {
  Node *root = create_BST();
  bst_in_order_print(root);
  Node *searchNode = bst_search_a_node(root, 80);
  if (searchNode != NULL) {
    printf("\nNode found: \n _%d_\n/    \\\n%d   %d", searchNode->data,
           searchNode->left ? searchNode->left->data : -1,
           searchNode->right ? searchNode->right->data : -1);
  } else {
    printf("\nNode not found.\n");
  }
  free(root);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node{
  char data;
  struct node *left;
  struct node *right;
};

struct tree {
  struct node *root;
  void (*insert)(struct tree*, char);
  void (*delete)(struct tree*, char);
  void (*inorder)(struct tree *);
};

void insert(struct tree *t, char data){
  struct node *new_node = malloc(sizeof(struct node));

  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;

  if (t->root == NULL){
    t->root = new_node;
  } else {
    struct node *current = t->root;
    struct node *parent = NULL;

    while (current != NULL) {
      parent = current;
      if (data == '+' || data == '-') {
        current = current->right;
      } else if (data == '*' || data == '/') {
        if (current->data == '+' || current->data == '-') {
          current = current->left;
        } else {
          current = current->right;
        }       } else {
        if (current->data == '*' || current->data == '/') {
          current = current->left;
        } else {
          current = current->right;
        }
      }
    }

    if (data == '+' || data == '-' || data == '*' || data == '/'){
      parent->right = new_node;
    } else {
      parent->left = new_node;
    }  
  }
}

void inorder_helper(struct node *n){
  if (n->left != NULL){
    inorder_helper(n->left);
  }
  if (n->data == '+' || n->data == '-' || n->data == '*' || n->data == '/'){
    printf("%c ", n->data);
  } else {
    printf("%d ", n->data);
  }
  if (n->right != NULL){
    inorder_helper(n->right);
  }
}

void inorder(struct tree *t){
  if(t->root != NULL){
    inorder_helper(t->root);
  }
}

int main(){
  struct tree t;
  t.root = NULL;
  t.insert = insert;
  t.inorder = inorder;

  t.insert(&t, 2);
  t.insert(&t, '*');
  t.insert(&t, 3);
  t.insert(&t, '+');
  t.insert(&t, 4);
  t.insert(&t, '/');
  t.insert(&t, 5);

  t.inorder(&t);

  return 0;
}
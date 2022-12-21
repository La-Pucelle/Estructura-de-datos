#include <stdio.h>
#include <stdlib.h>

// Define la estructura tree_node para almacenar un número entero y dos punteros a otros nodos del árbol
typedef struct tree_node {
  int value;
  struct tree_node* left;
  struct tree_node* right;
} tree_node;

// Declara las funciones sum y sum_multiples_of_3
int sum(tree_node* root);
int sum_multiples_of_3(tree_node* root);

int main(void) {
  // Crea el árbol
  tree_node* root = NULL;
  printf("Ingresa números enteros para crear el árbol (ingresa 0 para terminar):\n");
  int n;
  scanf("%d", &n);
  while (n != 0) {
    // Crea un nuevo nodo para el árbol
    tree_node* new_node = (tree_node*) malloc(sizeof(tree_node));
    new_node->value = n;
    new_node->left = NULL;
    new_node->right = NULL;

    // Si el árbol está vacío, asigna el nuevo nodo como la raíz
    if (root == NULL) {
      root = new_node;
    } else {
      // Crea un puntero auxiliar para recorrer el árbol
      tree_node* aux = root;
      // Recorre el árbol hasta encontrar un lugar vacío para el nuevo nodo
      while (1) {
        if (n < aux->value) {
          if (aux->left ==NULL) {
            aux->left = new_node;
            break;
          } else {
            aux = aux->left;
          }
        } else {
          if (aux->right == NULL) {
            aux->right = new_node;
            break;
          } else {
            aux = aux->right;
          }
        }
      }
    }

    // Lee el siguiente número
    scanf("%d", &n);
  }

  // Calcula y muestra la suma de todos los elementos del árbol
  int total_sum = sum(root);
  printf("La suma de todos los elementos del árbol es: %d\n", total_sum);

  // Calcula y muestra la suma de los elementos múltiplos de 3 del árbol
  int multiple_of_3_sum = sum_multiples_of_3(root);
  printf("La suma de los elementos múltiplos de 3 del árbol es: %d\n", multiple_of_3_sum);

  return 0;
}

// Define la función sum para calcular la suma de todos los elementos del árbol
int sum(tree_node* root) {
  if (root == NULL) {
    return 0;
  } else {
    return root->value + sum(root->left) + sum(root->right);
  }
}

// Define la función sum_multiples_of_3 para calcular la suma de los elementos múltiplos de 3 del árbol
int sum_multiples_of_3(tree_node* root) {
  if (root == NULL) {
    return 0;
  } else {
    int sum = 0;
    if (root->value % 3 == 0) {
      sum += root->value;
    }
    sum += sum_multiples_of_3(root->left);
    sum += sum_multiples_of_3(root->right);
    return sum;
  }
}



#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int rut;
  struct stack* next;
} stack;

stack* copy_stack(stack* s);
void push(stack** s, int rut);

int main(void) {
  // Crea la pila
  stack* s = NULL;

  // Añade elementos a la pila
  push(&s, 12345678);
  push(&s, 87654321);
  push(&s, 23456789);

  // Muestra el contenido de la pila
  stack* aux = s;
  while (aux != NULL) {
    printf("%d\n", aux->rut);
    aux = aux->next;
  }

  // Libera la memoria utilizada por la pila
  aux = s;
  while (aux != NULL) {
    stack* temp = aux->next;
    free(aux);
    aux = temp;
  }

  return 0;
}


stack* copy_stack(stack* s) {
  stack* copy = NULL;
  stack* aux = s;

  // Recorre la pila original
  while (aux != NULL) {
    stack* new_node = (stack*) malloc(sizeof(stack));
    new_node->rut = aux->rut;
    new_node->next = copy;
    copy = new_node;
    aux = aux->next;
  }

  return copy;
}

void push(stack** s, int rut) {
  stack* new_node = (stack*) malloc(sizeof(stack));
  new_node->rut = rut;
  new_node->next = NULL;

  // Si la pila está vacía, asigna el nuevo nodo como el inicio de la pila
  if (*s == NULL) {
    *s = new_node;
  } else {
    stack* aux = *s;
    while (aux->next != NULL) {
      aux = aux->next;
    }
    // Añade el nuevo nodo al final de la pila
    aux->next = new_node;
  }
}


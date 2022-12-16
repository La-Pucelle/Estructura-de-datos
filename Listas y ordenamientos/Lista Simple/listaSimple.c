#include <stdio.h>
#include <stdlib.h>

// Estructura para cada nodo de la lista
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Estructura para la lista simplemente enlazada
typedef struct List {
  int size;
  Node* head;
} List;

// Función para crear una nueva lista
List* create_list() {
  List* list = (List*)malloc(sizeof(List));
  list->size = 0;
  list->head = NULL;
  return list;
}

// Función para crear un nuevo nodo
Node* create_node(int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Función para insertar un nodo al final de la lista
void push_back(List* list, int data) {
    Node* node = create_node(data);

    if (list->head == NULL) {
    // Si la lista está vacía, el nuevo nodo será el único
    list->head = node;
    } else {
    // Si hay al menos un nodo en la lista, recorremos la lista hasta encontrar el último nodo y agregamos el nuevo nodo al final
    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
  }

  list->size++;
}

// Función para imprimir la lista
void print_list(List* list) {
    if (list->head == NULL) {
        printf("La lista está vacía\n");
    } else {
        printf("La lista es: ");
        Node* current = list->head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Función para ordenar la lista usando bubble sort
void sort(List* list) {
    if (list->size <= 1) return;

    int swapped = 1;
    while (swapped) {
        swapped = 0;
        Node* current = list->head;
        while (current->next != NULL) {
        // Si el nodo actual es mayor que el siguiente, los intercambiamos
        if (current->data < current->next->data) {
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
            swapped = 1;
        
        }
        current = current->next;
        }
    }
}

int main() {
    // Creamos la lista
    List* list = create_list();

    // Agregamos los elementos a la lista
    push_back(list, 5);
    push_back(list, 6);
    push_back(list, 3);
    push_back(list, 2);
    push_back(list, 9);

    // Imprimimos la lista original
    print_list(list);

    // Ordenamos la lista usando bubble sort
    sort(list);

    // Imprimimos la lista ordenada
    print_list(list);

    getch();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para cada nodo de la lista
typedef struct Node {
  char* data;
  struct Node* next;
  struct Node* prev;
} Node;

// Estructura para la lista circular doblemente enlazada
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
Node* create_node(char* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

// Función para insertar un nodo al final de la lista
void push_back(List* list, char* data) {
  Node* node = create_node(data);

  if (list->head == NULL) {
    // Si la lista está vacía, el nuevo nodo será el único y tanto su next como su prev apuntarán a sí mismo
    list->head = node;
    node->next = node;
    node->prev = node;
  } else {
    // Si hay al menos un nodo en la lista, se inserta el nuevo nodo al final
    Node* last = list->head->prev;
    last->next = node;
    node->prev = last;
    node->next = list->head;
    list->head->prev = node;
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
        do {
        printf("%s ", current->data);
        current = current->next;
        } while (current != list->head);
        printf("\n");
    }
}

// Función de comparación para el quicksort
int compare(const void* a, const void* b) {
    char* s1 = *(char**)a;
    char* s2 = *(char**)b;
    return strlen(s2) - strlen(s1);
}

// Función para ordenar la lista usando quicksort
void sort(List*list) {
    if (list->size <= 1) return;

    // Creamos un arreglo para almacenar los datos de la lista
    char** data = (char**)malloc(sizeof(char*) * list->size);

    // Copiamos los datos de la lista al arreglo
    int i = 0;
    Node* current = list->head;
    do {
        data[i++] = current->data;
        current = current->next;
    } while (current != list->head);

    // Ordenamos el arreglo usando quicksort
    qsort(data, list->size, sizeof(char*), compare);

    // Copiamos los datos ordenados del arreglo de nuevo a la lista
    i = 0;
    current = list->head;
    do {
    current->data = data[i++];
    current = current->next;
    } while (current != list->head);

    // Liberamos el arreglo
    free(data);
}

int main() {
    // Creamos la lista
    List* list = create_list();
    int i;

    // Solicitamos al usuario que ingrese 10 cadenas
    char buffer[100];
    for ( i = 0; i < 10; i++) {
    printf("Ingrese una cadena: ");
    scanf("%s", buffer);
    push_back(list, strdup(buffer));
    }

    // Imprimimos la lista original
    print_list(list);

    // Ordenamos la lista usando quicksort
    sort(list);

    // Imprimimos la lista ordenada
    print_list(list);

    return 0;
}

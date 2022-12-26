#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Estructura para representar un nodo del grafo
typedef struct node {
  char name[MAX_NAME_LENGTH];
  char course[MAX_NAME_LENGTH];
  char rut[MAX_NAME_LENGTH];
  struct node* friends[MAX_NAME_LENGTH];
  int numFriends;
} Node;

// Función para escribir los amigos de un nodo dado su RUT
void printFriends(Node* nodes, int numNodes, char* rut) {
  for (int i = 0; i < numNodes; i++) {
    if (strcmp(nodes[i].rut, rut) == 0) {
      printf("Amigos de %s:\n", nodes[i].name);
      for (int j = 0; j < nodes[i].numFriends; j++) {
        printf(" - %s\n", nodes[i].friends[j]->name);
      }
      return;
    }
  }
  printf("No se ha encontrado ningún alumno con el RUT especificado.\n");
}

int main() {
  // Crea algunos nodos y los relaciona como amigos
  Node node1 = {"Juan", "Informática", "12345678-9", {NULL}, 0};
  Node node2 = {"Pablo", "Informática", "98765432-1", {NULL}, 0};
  Node node3 = {"Ana", "Informática", "12312312-3", {NULL}, 0};
  Node node4 = {"Laura", "Informática", "45645645-6", {NULL}, 0};

  node1.friends[node1.numFriends++] = &node2;
  node1.friends[node1.numFriends++] = &node3;
  node2.friends[node2.numFriends++] = &node1;
  node2.friends[node2.numFriends++] = &node3;
  node3.friends[node3.numFriends++] = &node1;
  node3.friends[node3.numFriends++] = &node2;
  node3.friends[node3.numFriends++] = &node4;
  node4.friends[node4.numFriends++] = &node3;

  // Crea un arreglo con todos los nodos
  Node nodes[] = {node1, node2, node3, node4};
  int numNodes = sizeof(nodes) / sizeof(Node);

  printFriends(nodes, numNodes, "12312312-3");

  return 0;
}

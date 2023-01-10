#include <stdio.h>
#define NUM_CLIENTES 3

struct cliente {
    char nombre[50];
    int tiempo;
};
// Prototipo
struct cliente clientes[NUM_CLIENTES];

float promedio(struct cliente clientes[]) {
    int suma = 0;
    // Promedio
    for (int i = 0; i < NUM_CLIENTES; i++) {
        suma += clientes[i].tiempo;
    }
    return (float)suma / NUM_CLIENTES;
}

int main() {
    // Recorrido for
    for (int i = 0; i < NUM_CLIENTES; i++) {
        printf("Ingrese el nombre del cliente %d: ", i+1);
        scanf("%s", clientes[i].nombre);
        printf("Ingrese el tiempo de atención del cliente %d: ", i+1);
        scanf("%d", &clientes[i].tiempo);
    }

    float prom = promedio(clientes);
    printf("El promedio del tiempo de atención es: %.2f minutos\n", prom);
    return 0;
}
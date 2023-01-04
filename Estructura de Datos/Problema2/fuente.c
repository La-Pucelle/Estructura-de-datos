#include <stdio.h>
#include <string.h>

struct ciudad{
    char nombre[50];
    int distancia;
    int combustible;
};

struct ciudad ciudades[100];
int num_ciudades = 0;

void mostrar_ciudades(struct ciudad ciudades[], int num_ciudades) {
    printf("Información de las ciudades:\n");
    for (int i = 0; i < num_ciudades; i++) {
        printf("- %s: distancia = %d km, combustible = %d litros\n", ciudades[i].nombre, ciudades[i].distancia, ciudades[i].combustible);
    }
}

int main() {
    char nombre_salida[50];
    char nombre_llegada[50];
    while (1) {

        printf("Ingrese el nombre de la ciudad de salida (Escriba fin para terminar): ");
        scanf("%s", nombre_salida);

        if (strcmp(nombre_salida, "fin") == 0) {
            break;
        }
        
        printf("Ingrese el nombre de la ciudad de llegada: ");
        scanf("%s", nombre_llegada);
        printf("Ingrese la distancia entre las ciudades: ");
        scanf("%d", &ciudades[num_ciudades].distancia);
        printf("Ingrese el gasto en combustible entre las ciudades: ");
        scanf("%d", &ciudades[num_ciudades].combustible);
        strcpy(ciudades[num_ciudades].nombre, nombre_salida);
        num_ciudades++;
        strcpy(ciudades[num_ciudades].nombre, nombre_llegada);
        num_ciudades++;
    }

    mostrar_ciudades(ciudades, num_ciudades);
    return 0;
}
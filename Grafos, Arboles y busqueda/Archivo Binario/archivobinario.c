#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_DESCRIPTION_LENGTH 50

// Define la estructura product para almacenar los datos de cada producto
typedef struct {
  int code;
  char description[MAX_DESCRIPTION_LENGTH];
  float price;
  int units;
} product;

int main(void) {
  // Abre el archivo en modo escritura binaria
  FILE* fp = fopen("products.dat", "wb");
  if (fp == NULL) {
    perror("Error al abrir el archivo");
    return 1;
  }

  // Crea un array de productos
  product products[MAX_PRODUCTS];

  // Asigna valores a los campos de cada producto
  for (int i = 0; i < MAX_PRODUCTS; i++) {
    products[i].code = i;
    sprintf(products[i].description, "Product %d", i);
    products[i].price = i * 10.0;
    products[i].units = i * 100;
  }

  // Calcula la dirección de cada registro usando la función hash
  int addresses[MAX_PRODUCTS];
  for (int i = 0; i < MAX_PRODUCTS; i++) {
    addresses[i] = (products[i].code % 97) + 1;
  }

  // Escribe cada registro en el archivo
  for (int i = 0; i < MAX_PRODUCTS; i++) {
    fseek(fp, (addresses[i] - 1) * sizeof(product), SEEK_SET);
    fwrite(&products[i], sizeof(product), 1, fp);
  }

  // Cierra el archivo
  fclose(fp);

  return 0;
}

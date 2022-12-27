/*#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
  int code;
  char description[MAX_DESCRIPTION_LENGTH];
  float price;
  int units;
} product;

int main(void) {
  FILE* fp = fopen("products.dat", "wb");
  if (fp == NULL) {
    perror("Error al abrir el archivo");
    return 1;
  }

  product products[MAX_PRODUCTS];

  for (int i = 0; i < MAX_PRODUCTS; i++) {
    products[i].code = i;
    sprintf(products[i].description, "Product %d", i);
    products[i].price = i * 10.0;
    products[i].units = i * 100;
  }

  int addresses[MAX_PRODUCTS];
  for (int i = 0; i < MAX_PRODUCTS; i++) {
    addresses[i] = (products[i].code % 97) + 1;
  }

  for (int i = 0; i < MAX_PRODUCTS; i++) {
    fseek(fp, (addresses[i] - 1) * sizeof(product), SEEK_SET);
    fwrite(&products[i], sizeof(product), 1, fp);
  }

  fclose(fp);

  return 0;
}
*/

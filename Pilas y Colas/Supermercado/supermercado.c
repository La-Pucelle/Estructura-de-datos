#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define NUM_CAJAS 3
#define NUM_CARRITOS 25

// Estructura para representar un producto
typedef struct {
  char nombre[100];
  float precio;
} Producto;

// Estructura para representar un carrito de la compra
typedef struct {
  int id;
  bool disponible;
  Producto productos[100];
  int num_productos;
} Carrito;

// Estructura para representar una caja de pago
typedef struct {
  int id;
  int clientes_atendidos;
  int clientes_en_cola;
} Caja;

// Estructura para representar un comprobante de compra
typedef struct {
  int id;
  char* productos[100];
  int num_productos;
} Comprobante;

// Cola de carritos de la compra
Carrito carritos[NUM_CARRITOS];

// Colas de cajas de pago
Caja cajas[NUM_CAJAS];

// Pila de comprobantes de compra
Comprobante comprobantes[100];
int comprobantes_almacenados = 0;

// Función para encontrar la caja con menos clientes en cola
int encontrar_caja_con_menos_clientes() {
  int id_caja = 0;
  int clientes_en_cola = cajas[0].clientes_en_cola;
  for (int i = 1; i < NUM_CAJAS; i++) {
    if (cajas[i].clientes_en_cola < clientes_en_cola) {
      id_caja = i;
      clientes_en_cola = cajas.clientes_en_cola;
}
}
return id_caja;
}

// Función para simular el proceso de compra de un cliente
void comprar() {
// Encontrar carrito disponible
int id_carrito;
while (true) {
id_carrito = rand() % NUM_CARRITOS;
if (carritos[id_carrito].disponible) {
carritos[id_carrito].disponible = false;
break;
}
}

// Simular proceso de compra
printf("Comprando con el carrito %d...\n", id_carrito);
sleep(1 + rand() % 3); // esperar entre 1 y 3 segundos

// Encontrar caja con menos clientes en cola
int id_caja = encontrar_caja_con_menos_clientes();
cajas[id_caja].clientes_en_cola++;

// Simular proceso de pago en caja
printf("Pagando en la caja %d...\n", id_caja);
sleep(1 + rand() % 3); // esperar entre 1 y 3 segundos
cajas[id_caja].clientes_atendidos++;
cajas[id_caja].clientes_en_cola--;
carritos[id_carrito].disponible = true;

// Emitir comprobante de compra
Comprobante comprobante;
comprobante.id = comprobantes_almacenados;
for (int i = 0; i < carritos[id_carrito].num_productos; i++) {
Producto producto = carritos[id_carrito].productos[i];
char* nombre = malloc(strlen(producto.nombre) + 1);
strcpy(nombre, producto.nombre);
comprobante.productos[i] = nombre;
}
comprobante.num_productos = carritos[id_carrito].num_productos;
comprobantes[comprobantes_almacenados] = comprobante;
comprobantes_almacenados++;
}

// Función para agregar un producto a un carrito
void agregar_producto() {
printf("Ingrese el ID del carrito: ");
int id_carrito;
scanf("%d", &id_carrito);

printf("Ingrese el nombre del producto: ");
Producto producto;
scanf("%s", &producto.nombre);
printf("Ingrese el precio del producto: ");
scanf("%f", &producto.precio);

carritos[id_carrito].productos[carritos[id_carrito].num_productos] = producto;
carritos[id_carrito].num_productos++;
}

// Función para mostrar la información de un comprobante
void mostrar_comprobante() {
printf("Ingrese el ID del comprobante: ");
int id_comprobante;
scanf("%d", &id_comprobante);

Comprobante comprobante = comprobantes[id_comprobante];
printf("Comprobante %d:\n", comprobante.id);
for (int i = 0; i < comprobante.num_productos; i++) {
printf("- %s\n", comprobante.productos[i]);
}
}

int main() {
// Inicializar carritos de la compra
for (int i = 0; i < NUM_CARRITOS; i++) {
carritos[i].id = i;
carritos[i].disponible = true;
carritos[i].num_productos = 0;
}

// Inicializar cajas de pago
for (int i = 0; i < NUM_CAJAS; i++) {
cajas[i].id = i;
cajas[i].clientes_atendidos = 0;
cajas[i].clientes_en_cola = 0;
}

srand(time(NULL));

while (true) {
printf("\nBienvenido al supermercado. ¿Qué desea hacer?\n");
printf("1. Comprar\n");
printf("2. Agregar producto a carrito\n");
printf("3. Mostrar comprobante\n");
printf("4. Salir\n");
printf("Opción: ");

int opcion;
scanf("%d", &opcion);

switch (opcion) {
  case 1:
    comprar();
    break;
  case 2:
    agregar_producto();
    break;
  case 3:
    mostrar_comprobante();
    break;
  case 4:
    return 0;
  default:
    printf("Opción inválida.\n");
    break;
}
}
return 0;
}
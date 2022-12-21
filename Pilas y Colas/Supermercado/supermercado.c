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
      clientes_en_cola = cajas[i].clientes_en_cola;
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
  int id_c

  // Simular proceso de pago en caja
  printf("Pagando en la %s caja %d...\n", id_caja);
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

// Función para agregar un producto a un carrito de la compra
void agregar_producto() {
  printf("--- Agregar producto ---\n");
    printf("Introduce el nombre del producto: ");
  scanf("%s", &producto.nombre);
  printf("Introduce el precio del producto: ");
  scanf("%f", &producto.precio);

  // Agregar producto al carrito
  carritos[id_carrito].productos[carritos[id_carrito].num_productos] = producto;
  carritos[id_carrito].num_productos++;
}

// Función para mostrar la información de los carritos de la compra
void mostrar_carritos() {
  printf("--- Carritos de la compra ---\n");
  for (int i = 0; i < NUM_CARRITOS; i++) {
    Carrito carrito = carritos[i];
    printf("Carrito %d - disponible: %d - productos: %d\n", carrito.id, carrito.disponible, carrito.num_productos);
  }
}

// Función para mostrar la información de los comprobantes de compra
void mostrar_comprobantes() {
  printf("--- Comprobantes de compra ---\n");
  for (int i = comprobantes_almacenados - 1; i >= 0; i--) {
    Comprobante comprobante = comprobantes[i];
    printf("Comprobante %d - productos: ", comprobante.id);
    for (int j = 0; j < comprobante.num_productos; j++) {
      printf("%s ", comprobante.productos[j]);
    }
    printf("\n");
  }
}

int main() {
  // Inicializar carritos
  for (int i = 0; i < NUM_CARRITOS; i++) {
    carritos[i].id = i;
    carritos[i].disponible = true;
  }

  // Inicializar cajas
  for (int i = 0; i < NUM_CAJAS; i++) {
    cajas[i].id = i;
    cajas[i].clientes_atendidos = 0;
    cajas[i].clientes_en_cola = 0;
  }

  // Inicializar generador de números aleatorios
  srand(time(NULL));

  // Bucle del menú principal
  while (true) {
    printf("\n--- Supermercado ---\n");
    printf("1. Comprar\n");
    printf("2. Agregar producto\n");
    printf("3. Mostrar carritos\n");
    printf("4. Mostrar comprobantes\n");
    printf("5. Salir\n");
    printf("Selecciona una opción: ");

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
        mostrar_carritos();
        break;
      case 4:
        mostrar_comprobantes();
        break;
      case 5:
        return 0;
      default:
        printf("Opción inválida\n");
        break;
    }
  }

  return 0;
}
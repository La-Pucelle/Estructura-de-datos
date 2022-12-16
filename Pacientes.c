#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_RUT_LENGTH 20
#define MAX_PROBLEM_LENGTH 100

// Estructura para almacenar los datos de un paciente
struct patient {
  char nombre[MAX_NAME_LENGTH];
  char direccion[MAX_ADDRESS_LENGTH];
  char rut[MAX_RUT_LENGTH];
  char nacimiento[MAX_RUT_LENGTH];
  char sexo[MAX_RUT_LENGTH];
  char diaVisita[MAX_RUT_LENGTH];
  char problemaMedico[MAX_PROBLEM_LENGTH];
  struct patient *prev;
  struct patient *next;
};

// Puntero a la cabeza de la lista doblemente enlazada
struct patient *head = NULL;

// Función para agregar un paciente a la lista
void add_patient(struct patient *new_patient) {
  // Si la lista está vacía, el nuevo paciente será la cabeza
  if (head == NULL) {
    head = new_patient;
    return;
  }

  //En caso contrario, recorremos la lista hasta llegar al último elemento
struct patient *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  // Agregamos el nuevo paciente al final de la lista
  current->next = new_patient;
  new_patient->prev = current;
}

// Función para mostrar los pacientes que visitan en un día determinado
void show_patients_by_diaVisita(char *diaVisita) {
  // Recorremos la lista de pacientes
  struct patient *current = head;
  while (current != NULL) {
    // Si el día de visita del paciente coincide con el día especificado por el usuario, mostramos sus datos
    if (strcmp(current->diaVisita, diaVisita) == 0) {
      printf("Nombre: %s\n", current->nombre);
      printf("Dirección: %s\n", current->direccion);
      printf("RUT: %s\n", current->rut);
      printf("Fecha de nacimiento: %s\n", current->nacimiento);
      printf("sexoo: %s\n", current->sexo);
      printf("Día de visita: %s\n", current->diaVisita);
      printf("Problema médico: %s\n", current->problemaMedico);
      printf("\n");
    }

    // Avanzamos al siguiente elemento de la lista
    current = current->next;
  }
} 

int main(int argc, char *argv[]) {
  // Creamos una estructura para almacenar la información de un paciente
  struct patient *p1 = malloc(sizeof(struct patient));
  strcpy(p1->nombre, "Juan Pérez");
  strcpy(p1->direccion, "Jose miguel carrera 123");
  strcpy(p1->rut, "12345678-9");
  strcpy(p1->nacimiento, "01/01/1970");
  strcpy(p1->sexo, "Hombre");
  strcpy(p1->diaVisita, "Lunes");
  strcpy(p1->problemaMedico, "Dolor de cabeza");
  p1->prev = NULL;
  p1->next = NULL;

  // Agregamos el paciente a la lista
  add_patient(p1);

  // Creamos otros pacientes y los agregamos a la lista
  struct patient *p2 = malloc(sizeof(struct patient));
  strcpy(p2->nombre, "María Rodríguez");
  strcpy(p2->direccion, "San jorge 456");
  strcpy(p2->rut, "98765432-1");
  strcpy(p2->nacimiento, "01/01/1980");
  strcpy(p2->sexo, "Mujer");
  strcpy(p2->diaVisita, "Martes");
  strcpy(p2->problemaMedico, "Dolor de estómago");
  p2->prev = NULL;
  p2->next = NULL;

  add_patient(p2);

  struct patient *p3 = malloc(sizeof(struct patient));
  strcpy(p3->nombre, "Eduardo Sanhueza");
  strcpy(p3->direccion, "San Carlos 961");
  strcpy(p3->rut, "20196453-k");
  strcpy(p3->nacimiento, "13/02/2003");
  strcpy(p3->sexo, "Hombre");
  strcpy(p3->diaVisita, "Miercoles");
  strcpy(p3->problemaMedico, "Dolor de pecho");

  add_patient(p3);

  struct patient *p4 = malloc(sizeof(struct patient));
  strcpy(p4->nombre, "Catalina Gabriela");
  strcpy(p4->direccion, "San Camilo 462");
  strcpy(p4->rut, "19.499.234-4");
  strcpy(p4->nacimiento, "10/11/1998");
  strcpy(p4->sexo, "Mujer");
  strcpy(p4->diaVisita, "Jueves");
  strcpy(p4->problemaMedico, "Fractura");

  add_patient(p4);

  //Parametro para imprimir los pacientes del dia x
  show_patients_by_diaVisita("Jueves");

  return 0;
}

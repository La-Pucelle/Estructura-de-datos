#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_RUT_LENGTH 20
#define MAX_PROBLEM_LENGTH 100

// Estructura para almacenar los datos de un paciente
struct patient {
  char name[MAX_NAME_LENGTH];
  char address[MAX_ADDRESS_LENGTH];
  char rut[MAX_RUT_LENGTH];
  char birth_date[MAX_RUT_LENGTH];
  char sex[MAX_RUT_LENGTH];
  char visit_day[MAX_RUT_LENGTH];
  char medical_problem[MAX_PROBLEM_LENGTH];
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
void show_patients_by_visit_day(char *visit_day) {
  // Recorremos la lista de pacientes
  struct patient *current = head;
  while (current != NULL) {
    // Si el día de visita del paciente coincide con el día especificado por el usuario, mostramos sus datos
    if (strcmp(current->visit_day, visit_day) == 0) {
      printf("Nombre: %s\n", current->name);
      printf("Dirección: %s\n", current->address);
      printf("RUT: %s\n", current->rut);
      printf("Fecha de nacimiento: %s\n", current->birth_date);
      printf("Sexo: %s\n", current->sex);
      printf("Día de visita: %s\n", current->visit_day);
      printf("Problema médico: %s\n", current->medical_problem);
      printf("\n");
    }

    // Avanzamos al siguiente elemento de la lista
    current = current->next;
  }
}

int main(int argc, char *argv[]) {
  // Creamos una estructura para almacenar la información de un paciente
  struct patient *p1 = malloc(sizeof(struct patient));
  strcpy(p1->name, "Juan Perez");
  strcpy(p1->address, "Calle Falsa 123");
  strcpy(p1->rut, "12345678-9");
  strcpy(p1->birth_date, "01/01/1970");
  strcpy(p1->sex, "Hombre");
  strcpy(p1->visit_day, "Lunes");
  strcpy(p1->medical_problem, "Dolor de cabeza");
  p1->prev = NULL;
  p1->next = NULL;

  // Agregamos el paciente a la lista
  add_patient(p1);

  // Creamos otro paciente y lo agregamos a la lista
  struct patient *p2 = malloc(sizeof(struct patient));
  strcpy(p2->name, "Maria Rodríguez");
  strcpy(p2->address, "Calle Falsa 456");
  strcpy(p2->rut, "98765432-1");
  strcpy(p2->birth_date, "01/01/1980");
  strcpy(p2->sex, "Mujer");
  strcpy(p2->visit_day, "Martes");
  strcpy(p2->medical_problem, "Dolor de estomago");
  p2->prev = NULL;
  p2->next = NULL;

  add_patient(p2);

  struct patient *p3 = malloc(sizeof(struct patient));
  strcpy(p3->name, "Eduardo Sanhueza");
  strcpy(p3->address, "Calle Falsa 567");
  strcpy(p3->rut, "12345678-1");
  strcpy(p3->birth_date, "01/01/1990");
  strcpy(p3->sex, "Hombre");
  strcpy(p3->visit_day, "Miercoles");
  strcpy(p3->medical_problem, "Dolor de pecho");
  p3->prev = NULL;
  p3->next = NULL;

  add_patient(p3);

  struct patient *p4 = malloc(sizeof(struct patient));
  strcpy(p4->name, "Fabricio Castro");
  strcpy(p4->address, "Calle Falsa 543");
  strcpy(p4->rut, "12563241-1");
  strcpy(p4->birth_date, "01/01/1950");
  strcpy(p4->sex, "Hombre");
  strcpy(p4->visit_day, "Jueves");
  strcpy(p4->medical_problem, "Fractura");
  p4->prev = NULL;
  p4->next = NULL;

  add_patient(p4);
  

  show_patients_by_visit_day("Jueves");

  getch();
  return 0;
}
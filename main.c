#include <stdio.h>
#include <string.h>
#include "util/lista.h"
#include "app/lista_paciente.h"
#include "io/arch.h"
#include "io/consola.h"

void demo_lista_de_ints(lista *, const char *);
void demo_lista_de_pacientes(lista*, const char *);
void demo_lista_pacientes(lista * , const char *);

int main(int argc, char **argv)
{
    demo_lista_de_ints(crear_lista(sizeof(int)), "recursos/lista_con_ints.dat");
    demo_lista_de_pacientes(crear_lista(sizeof(Paciente)), "recursos/lista_con_pacientes.dat");
    demo_lista_pacientes(crear_lista_paciente(), "recursos/lista_pacientes.dat");
    
    return 0;
}

void demo_lista_de_ints(lista *l, const char * archivo) {
    printf("################################\n");
    printf("#    Demo lista con enteros    #\n");
    printf("################################\n");

    agregar_a_lista(l, &(int){23});
    agregar_a_lista(l, &(int){10});
    agregar_a_lista(l, &(int){20});
    agregar_a_lista(l, &(int){7});

    printf("\nLista de enteros creada en memoria:\n");
    imprimir_lista(l, imprimir_int);

    eliminar_primero(l);

    printf("\nLista de enteros despues de eliminar el primero:\n");
    imprimir_lista(l, imprimir_int);

    printf("\nGrabando la lista de enteros en disco y cargandola de nuevo en memoria...\n");
    grabar_lista(l, archivo);
    const lista *l2 = cargar_lista(archivo);

    printf("\nLista de enteros cargada del disco\n(debería ser igual que la lista creada en memoria):\n");
    imprimir_lista(l2, imprimir_int);
}


void demo_lista_de_pacientes(lista *l, const char * archivo) {
    printf("################################\n");
    printf("#    Demo lista con pacientes  #\n");
    printf("################################\n");

    Paciente p = NuevoPaciente("Pedro", "Dr. Juan");
    agregar_a_lista(l, &p);
    p = NuevoPaciente("Samuel", "Dr. John");
    agregar_a_lista(l, &p);
    p = NuevoPaciente("Pepe", "Dr. Alberto");
    agregar_a_lista(l, &p);

    printf("\nLista de pacientes creada en memoria:\n");
    imprimir_lista(l, imprimir_paciente);

    printf("\nGrabando la lista de pacientes en disco y cargandola de nuevo en memoria...\n");
    grabar_lista(l, archivo);
    const lista *l2 = cargar_lista(archivo);

    printf("\nLista de pacientes cargada del disco\n(debería ser igual que la lista creada en memoria):\n");
    imprimir_lista(l2, imprimir_paciente);
}

void demo_lista_pacientes(lista *l, const char * archivo) {
    printf("################################\n");
    printf("#       Demo lista pacientes   #\n");
    printf("################################\n");
    
    Paciente p = NuevoPaciente("Pedro", "Dr. Juan");
    agregar_a_lista_paciente(l, &p);
    p = NuevoPaciente("Samuel", "Dr. John");
    agregar_a_lista_paciente(l, &p);
    p = NuevoPaciente("Pepe", "Dr. Alberto");
    agregar_a_lista_paciente(l, &p);

    printf("\nLista de pacientes creada en memoria:\n");
    imprimir_lista(l, imprimir_paciente);

    printf("\nGrabando la lista de pacientes en disco y cargandola de nuevo en memoria...\n");
    grabar_lista(l, archivo);
    const lista *l2 = cargar_lista(archivo);

    printf("\nLista de pacientes cargada del disco\n(debería ser igual que la lista creada en memoria):\n");
    imprimir_lista(l2, imprimir_paciente);
}






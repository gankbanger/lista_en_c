#include "consola.h"
#include <stdio.h>
#include "../app/lista.h"
#include "../modelo/paciente.h"

void imprimir_lista(lista* l, void (*funcion_de_imprimir)(void*)) {
    iter_lista *iter = iterar_lista(l);
    for (void* val = iter_siguiente(iter); val != NULL; val = iter_siguiente(iter)){
        (*funcion_de_imprimir)(val);
    }
}

void imprimir_int(void *v)
{
    printf("%d\n", *(int*)v);
}

void imprimir_paciente(void *v)
{
    printf("nombre: %s\n", ((Paciente*)v)->nombre);
    printf("\t - doctor: %s\n", ((Paciente*)v)->medicosolicitado);
}

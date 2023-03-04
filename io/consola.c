#include "consola.h"
#include <stdio.h>
#include "../util/lista.h"
#include "../app/paciente.h"

void imprimir_lista(const lista* l, void (*funcion_de_imprimir)(const void*)) {
    iter_lista *iter = iterar_lista(l);
    for (const void* val = iter_siguiente(iter); val != NULL; val = iter_siguiente(iter)){
        (*funcion_de_imprimir)(val);
    }
}

void imprimir_int(const void *v)
{
    printf("%d\n", *(const int*)v);
}

void imprimir_paciente(const void *v)
{
    printf("nombre: %s\n", ((const Paciente*)v)->nombre);
    printf("\t - doctor: %s\n", ((const Paciente*)v)->medicosolicitado);
}

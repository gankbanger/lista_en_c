#include <stdio.h>
#include <stdlib.h>
#include "arch.h"
#include "../app/lista.h"

void grabar_lista(lista *l, const char *nombre_archivo)
{
    FILE *f = fopen(nombre_archivo, "w");
    if (f == NULL)
    {
        exit(1);
    }

    // el primer registro el tamaño del tipo de datos
    size_t talla_valores = obtener_talla_valores(l);
    fwrite(&talla_valores, sizeof(int), 1, f);

    // ahora si grabamos un registro por cada elemento en la lista
    iter_lista *iter = iterar_lista(l);
    for (void* val = iter_siguiente(iter); val != NULL; val = iter_siguiente(iter)){
        fwrite(val, talla_valores, 1, f);
    }

    fclose(f);
}

lista * cargar_lista(const char *nombre_archivo)
{
    FILE *f = fopen(nombre_archivo, "r");
    if (f == NULL)
    {
        exit(1);
    }
    // prim leemos el tamaño de los elementos
    int talla_nodo;
    fread(&talla_nodo, sizeof(int), 1, f);
    lista *l = crear_lista(talla_nodo);

    // luego si leemos elemento por elemento
    void *valor = malloc(talla_nodo);
    while (fread(valor, talla_nodo, 1, f) > 0) {
        agregar_a_lista(l, valor);
    }
    free(valor);
    fclose(f);
    return l;
}
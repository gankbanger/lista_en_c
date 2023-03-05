#include <stdio.h>
#include "lista.h"

typedef struct nodo
{
    struct nodo *sig;
    void *v;
} nodo;

typedef struct lista
{
    nodo *prim;
    nodo *ult;
    size_t talla_valores;
} lista;

typedef struct iter_lista
{
    nodo *actual;
} iter_lista;

lista *crear_lista(size_t talla_valores)
{
    lista *l = malloc(sizeof(lista));

    l->prim = NULL;
    l->ult = NULL;
    l->talla_valores = talla_valores;

    return l;
}

size_t obtener_talla_valores(const lista *l){
    return l->talla_valores;
}

nodo *nuevo_nodo(const lista *l, void *val)
{
    nodo *n = malloc(sizeof(nodo));
    n->v = malloc(l->talla_valores);

    // grabamos byte por byte (char) hasta completar el tamaño del valor
    // porque no sabemos el tipo de void* en tiempo de compilación
    for (int i = 0; i < l->talla_valores; i++)
    {
        *(char *)(n->v + i) = *(char *)(val + i);
    }

    return n;
}

void agregar_a_lista(lista *l, void *val)
{
    nodo *n = nuevo_nodo(l, val);
    if (l->prim == NULL)
    {
        l->prim = n;
        l->ult = l->prim;
    }
    else
    {
        l->ult->sig = n;
        l->ult = n;
    }
}

void eliminar_primero(lista *l) {
    if (l->prim != NULL) {
        nodo * sig = l->prim->sig;
        free(l->prim);
        if (sig != NULL) {
            l->prim = sig;
        } else {
            l->ult = NULL;
        }
    }
}

iter_lista *iterar_lista(const lista *lista)
{
    iter_lista *iter = malloc(sizeof(iter_lista));
    iter->actual = lista->prim;
    return iter;
}

void *iter_siguiente(iter_lista *iter)
{
    if (iter->actual == NULL)
    {
        free(iter);
        return NULL;
    }
    void *valor = iter->actual->v;
    iter->actual = iter->actual->sig;
    return valor;
}

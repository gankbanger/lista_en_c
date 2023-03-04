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
    nodo *n;
} iter_lista;

lista *crear_lista(size_t talla_valores)
{
    lista *l = malloc(sizeof(lista));

    l->prim = NULL;
    l->ult = NULL;
    l->talla_valores = talla_valores;

    return l;
}

size_t obtener_talla_valores(lista *l){
    return l->talla_valores;
}

nodo *nuevo_nodo(lista *l, void *val)
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

iter_lista *iterar_lista(lista *lista)
{
    iter_lista *iter = malloc(sizeof(iter_lista));
    iter->n = lista->prim;
    return iter;
}

void *iter_siguiente(iter_lista *iter)
{
    if (iter->n == NULL)
    {
        free(iter);
        return NULL;
    }
    void *valor = iter->n->v;
    iter->n = iter->n->sig;
    return valor;
}
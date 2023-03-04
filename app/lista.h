#ifndef __LISTA_H
#define __LISTA_H

#include <stdlib.h>

/// @brief una lista genérica
typedef struct lista lista;

/// @brief un iterador de lista genérica
typedef struct iter_lista iter_lista;

/// @brief crea una lista que acepta elementos de cierta talla
/// @param talla_de_los_elementos talla de cada elemento de la lista
/// @return la nueva lista
lista *crear_lista(size_t talla_de_los_elementos);

/// @brief regresa la talla de elemetos aceptados por la lista
/// @param l la lista
/// @return la talla de los elementos aceptados por la lista
size_t obtener_talla_valores(lista* l);

/// @brief agrega un elemento a la lista
/// @param  l la lista
/// @param  v el elemento
void agregar_a_lista(lista* l , void* v);


/// @brief regresa un iterador de la lista
/// @param l la lista
/// @return el iterador de la lista
iter_lista* iterar_lista(lista* l);

/// @brief regresa el elemento en la posición actual del iterador y avanza la posición
/// @param iter el iterador
/// @return el valor en la posición actual del iterador
void *iter_siguiente(iter_lista* iter);

#endif
#ifndef __CONSOLA_H
#define __CONSOLA_H

/// @brief lista genérica
typedef struct lista lista;

/// @brief Imprime una lista
/// @param l la lista a imprimir
/// @param funcion_de_imprimir una función que recibe un puntero a un elemento de la lista y lo imprime
void imprimir_lista(const lista* l, void (*funcion_de_imprimir)(const void*));

/// @brief Imprime un número entero
/// @param v puntero a un número entero
void imprimir_int(const void *v);

/// @brief Imprime un Paciente
/// @param v puntero a un Paciente
void imprimir_paciente(const void *v);

#endif

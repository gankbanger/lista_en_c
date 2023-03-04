#ifndef __ARCH_H
#define __ARCH_H

/// @brief lista generica
typedef struct lista lista;

/// @brief graba una lista en disco
/// @param lista la lista
/// @param nombre_archivo el nombre del archivo destino
void grabar_lista(lista *lista, const char* nombre_archivo);

/// @brief carga en memoria una lista a partir de un archivo en disco
/// @param nombre_archivo el nombre del archivo fuente
/// @return la lista
lista * cargar_lista(const char *nombre_archivo);

#endif
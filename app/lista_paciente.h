#ifndef __LISTA_PACIENTE_H
#define __LISTA_PACIENTE_H

#include "lista.h"
#include "../modelo/paciente.h"

/// @brief Crea una lista de pacientes
/// @return la lista de pacientes
lista *crear_lista_paciente();

/// @brief agrega un Paciente a una lista de pacientes
/// @param l la lista de pacientes
/// @param  p el paciente
void agregar_a_lista_paciente(lista *l , Paciente *p);

/// @brief regresa el paciente en la posición actual del iterador y adelanta una posición
/// @param iter el iterador
/// @return el paciente
Paciente *iter_siguiente_paciente(iter_lista *iter);

#endif
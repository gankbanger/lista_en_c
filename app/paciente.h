#ifndef __PACIENTE_H
#define __PACIENTE_H

#include <time.h>

/// @brief Un paciente
typedef struct Paciente
{
    int protocolo;
    char nombre[30];
    char medicosolicitado[30];
    time_t fecha;
    char nombreOS[30];
    int tieneOS;
    int montoOS;
    int montoPT;
} Paciente;

/// @brief Crea un nuevo paciente
/// @param nombre nombre del paciente
/// @param medico nombre del medico
/// @return el paciente
Paciente NuevoPaciente(const char* nombre, const char* medico);

#endif
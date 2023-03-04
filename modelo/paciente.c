#include "paciente.h"
#include <string.h>

Paciente NuevoPaciente(const char* nombre, const char* medico){
    Paciente p;
    strcpy(p.nombre, nombre);
    strcpy(p.medicosolicitado,medico);
    p.fecha = time(NULL);
    return p;   
}
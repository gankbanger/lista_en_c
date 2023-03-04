
#include <stdio.h>
#include "lista_paciente.h"

lista *crear_lista_paciente()
{
    return crear_lista(sizeof(Paciente));
}

void agregar_a_lista_paciente(lista *l, Paciente *val)
{
    agregar_a_lista(l, val);
}

Paciente *iter_siguiente_paciente(iter_lista *iter)
{
    return (Paciente *)iter_siguiente(iter);
}

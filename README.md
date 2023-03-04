# Simple lista genérica en C

Implementación muy simple de una lista génerica en C.

La lista consiste es una colección de nodos enlazados.

La `lista` es simplemente el puntero al primer nodo.

Como ejemplo se incluye una lista _concreta_ de elements tipo `Paciente`, `lista_paciente`, que reutiliza la `lista` genérica.

El código está organizado así:
- `util/`: folder con la lista genérica
- `app/`: código aplicativo específico al ejemplo del uso del tipo `Paciente`.
- `io/`: folder con el código de entrada y salida, tanto en consola como en archivos.

##Uso

Se crea el ejecutable con el comando `make` a partir del terminal.

La ejecución del archivo `main` resultante muestra en pantalla las 3 demontraciones de utilización de la lista. 
- Demo de la lista genérica con `int` como elementos.
- Demo de la lista genérica con `Paciente` como elementos.
- Demo de la lista concreta `lista_paciente`.
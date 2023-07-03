#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "resultados.h"
#include "ingreso.h"
#define MAX_EQUIPOS 10

char nombresEquipos[MAX_EQUIPOS][50];

int puntos[MAX_EQUIPOS];


int main() {

  ingresarEquipos();
  mostrarCombinaciones();
  resultadosdelospartidos();
  mostrarTabla();

}

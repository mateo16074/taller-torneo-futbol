#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ingreso.h"
#include "resultados.h"

#define MAX_EQUIPOS 10 //Macro para el maximo de equipos 

char nombresEquipos[MAX_EQUIPOS][50];//matirz para el  nombre de los equipos
int nequip = 0;//variable para el numero de equipos
int puntos[MAX_EQUIPOS];//matriz para los puntos de los equipos

void ingresarEquipos() {//funcion para ingresar los nombres de los equipos
  printf("Ingrese los nombres de los equipos que van a participar\n");
  printf("Si desea finalizar, escriba 'terminar'\n");

  while (nequip < MAX_EQUIPOS) {//while para ingresar los equipos
    printf("Equipo %d: ", nequip + 1);
    scanf("%s", nombresEquipos[nequip]);

    if (strcmp(nombresEquipos[nequip], "terminar") == 0) {//compara la palabra terminar
      break;
    }
    
  }
}
void guardarEquiposEnArchivo() {//guardar los nombres de los equivos en un archivo.txt
  FILE *archivoEquipos = fopen("equipos.txt", "w");
  if (archivoEquipos == NULL) {
    printf("Error al abrir el archivo equipos.txt\n");
    return;
  }

  for (int i = 0; i < nequip; i++) {
    fprintf(archivoEquipos, "%s\n", nombresEquipos[i]);
  }

  fclose(archivoEquipos);
}
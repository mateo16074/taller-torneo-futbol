#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EQUIPOS 10 //Macro para el maximo de equipos 

char nombresEquipos[MAX_EQUIPOS][50];//matirz para el  nombre de los equipos
int nequip = 0;//variable para el numero de equipos
int puntos[MAX_EQUIPOS];//matriz para los puntos de los equipos

void ingresarEquipos() {//funcion para ingresar los nombres de los equipos
  printf("Ingrese los nombres de los equipos que van a participar\n");
  printf("Si desea finalizar, escriba 'terminar'\n");

  while (nequip < MAX_EQUIPOS) {
    printf("Equipo %d: ", nequip + 1);
    scanf("%s", nombresEquipos[nequip]);

    if (strcmp(nombresEquipos[nequip], "terminar") == 0) {
      break;
    }

    nequip++;
  }
}
void guardarEquiposEnArchivo() {//guardar los nombres de los equivos en un archivo.txt
  FILE *archivoEquipos = fopen("equipos.txt", "w+");
  if (archivoEquipos == NULL) {
    printf("Error al abrir el archivo equipos.txt\n");
    return;
  }

  for (int i = 0; i < nequip; i++) {
    fprintf(archivoEquipos, "%s\n", nombresEquipos[i]);
  }

  fclose(archivoEquipos);
}
void mostrarCombinaciones() {//funcion para mostrar los partidos posibles
  int i, j;

  printf("Combinaciones de partidos:\n");

  for (i = 0; i < nequip; i++) {
    for (j = i + 1; j < nequip; j++) {
      printf("%s vs %s\n", nombresEquipos[i], nombresEquipos[j]);
    }
  }
}


void resultadosdelospartidos() {//funcion para los goles de cada partido
  int i, j;
  int opcion;

  printf("Deseas ingresar manualmente los resultados de los partidos o generarlos aleatoriamente?\n");
  printf("1. Ingresar manualmente\n");
  printf("2. Generar aleatoriamente\n");
  printf("Ingrese su opcion: ");
  scanf("%d", &opcion);

  printf("Generando resultados de los partidos:\n");

  for (i = 0; i < nequip; i++) {
    for (j = i + 1; j < nequip; j++) {
      int resultado1, resultado2;

      if (opcion == 1) {
        printf("Ingrese los puntos del equipo %s: ", nombresEquipos[i]);
        scanf("%d", &resultado1);
        printf("Ingrese los puntos del equipo %s: ", nombresEquipos[j]);
        scanf("%d", &resultado2);
      } else if (opcion == 2) {
        resultado1 = rand() % 11;
        resultado2 = rand() % 11;
        printf("Resultado aleatorio: %s %d - %d %s\n", nombresEquipos[i],
               resultado1, resultado2, nombresEquipos[j]);
      } else {
        printf("Opción inválida.\n");
        return;
      }

      printf("Resultado: %s %d - %d %s\n", nombresEquipos[i], resultado1,
             resultado2, nombresEquipos[j]);

      // Comparar los puntos y asignarlos a los equipos
      if (resultado1 > resultado2) {
        puntos[i] += 3;
      } else if (resultado1 < resultado2) {
        puntos[j] += 3;
      } else {
        puntos[i] += 1;
        puntos[j] += 1;
      }
    }
  }
      guardarResultadosEnArchivo();
}

void mostrarTabla() {//funcion para la tabla de de posicones
  printf("\nTabla de posiciones:\n");
  printf("Equipo\t\tPuntos\n");

  for (int i = 0; i < nequip; i++) {
    printf("%s\t\t%d\n", nombresEquipos[i], puntos[i]);
  }
}

void guardarResultadosEnArchivo() {
  FILE *archivoResultados = fopen("resultados.txt", "w+");
  if (archivoResultados == NULL) {
    printf("Error al abrir el archivo resultados.txt\n");
    return;
  }

  for (int i = 0; i < nequip; i++) {
    fprintf(archivoResultados, "%s: %d puntos\n", nombresEquipos[i], puntos[i]);
  }

  fclose(archivoResultados);
}


int main() {

  ingresarEquipos();
  mostrarCombinaciones();
  resultadosdelospartidos();
  mostrarTabla();

}

/*
    *****************************************************************
    Gloria Oliva Olivares Ménez
    Curso: Análisis de algoritmos
    ESCOM-IPN
    Algoritmo de ordenación Bubble Sort
    Compilación: "gcc main.c tiempo.x  -o main (tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
    Ejecución: "./main n" (Linux y MAC OS)
    NOTA: Si se hace desde un script.sh, solo se tienen que cambiar los permisos para que pueda ejecutarse como programa dentro de la computadora y en la terminal poner "./myscript.sh"
    *****************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

//PROGRAMA PRINCIPAL
int main(int argc, char **argv){
	//Variables del programa
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //para medir el tiempo
    int *arr, n, aux, i, j; //arreglo a ordenar, tamaño del algoritmo, variables para algoritmo

	//Recepción y decodificación de argumentos

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=2){
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	}
	//Tomar el segundo argumento como tamaño del algoritmo
	else{
		n=atoi(argv[1]);
	}

	//Creacion del arreglo
	arr = malloc(sizeof(int)*n);

	//Guardar números en el arreglo
	for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    //Iniciar conteo para evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);

    //Algoritmo
    for(i=0; i<=n-2; i++){ //recorre el arreglo
        for(j=0; j<=n-2; j++){ 
            if(arr[j]>arr[j+1]){ //por cada posición se compara si hay uno menor a su derecha 
                aux=arr[j]; //si es así, se guarda la posición actual en una variable auxiliar 
                arr[j]=arr[j+1]; //se intercambian 
                arr[j+1]=aux; //el auxiliar se le asigna a la siguiente posición 
            }
        }
    }

    //Evaluar tiempos de ejecución
    uswtime(&utime1, &stime1, &wtime1);

	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

    //Terminar el programa
    exit(0);
}

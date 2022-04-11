/*
    *****************************************************************
    Curso: Análisis de algoritmos
    ESCOM-IPN
    Algoritmo de búsqueda Búsqueda Lineal o Secuencial
    Compilación: "gcc main.c tiempo.x  -o main (tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
    Ejecución: "./main n" (Linux y MAC OS)
    NOTA: Si se hace desde un script.sh, solo se tienen que cambiar los permisos para que pueda ejecutarse como programa dentro de la computadora y en la terminal poner "./myscript.sh"
    *****************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

int busquedaLineal(int *A, int x, int n);

//PROGRAMA PRINCIPAL
int main(int argc, char **argv){
	//Variables del programa
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //para medir el tiempo
    int index, x, n, *A; //del algoritmo

    //Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=3){
		printf("\nIndique el tamaño del arreglo y el número a buscar- Ejemplo: [user@equipo]$ %s 100 7\n",argv[0]);
		exit(1);
	}
	else{
		n=atoi(argv[1]); //tamanio del arreglo
        x=atoi(argv[2]);  //elemento a buscar 
	}

    //Creacion del arreglo
	A = malloc(sizeof(int)*n);

    //Guardar números en el arreglo
	for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }

    //Iniciar conteo para evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);

    //Algoritmo
    index=busquedaLineal(A,x,n);
    printf("%d\n", index);

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

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")

    exit(0); 
}

int busquedaLineal(int *A, int x, int n){
    int i; //se asigna variable para recorrer el arreglo
    for(i=0;i<n;i++){  //se recorre el arreglo
        if(x==A[i]){  //si el valor buscado corresponde con uno del arreglo
            return i;  //devuelve el índice de donde esta ubicado el numero
        }
    }
    return -1; //sino devuelve -1
}
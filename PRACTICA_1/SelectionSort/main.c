/*
    *****************************************************************
    Gloria Oliva Olivares Ménez
    Curso: Análisis de algoritmos
    ESCOM-IPN
    Algoritmo de ordenación Selection Sort
    Compilación: "gcc main.c tiempo.x  -o main (tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
    Ejecución: "./main n" (Linux y MAC OS)
    NOTA: Si se hace desde un script.sh, solo se tienen que cambiar los permisos para que pueda ejecutarse como programa dentro de la computadora y en la terminal poner "./myscript.sh"
    *****************************************************************
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "tiempo.h"

int main(int argc, char **argv){
    //Variables del programa
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //para medir el tiempo
    int *A, n, p, k, temp, i=0;  //variables del algoritmo 

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
    A = malloc(sizeof(int)*n);

    //Iniciar conteo para evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);

    //Asigna los valores recogidos a una posición del arreglo 
    do{
        scanf("%d", &A[i++]);
    }while(i<n);

    //Algoritmo
    for(k=0; k<=n-2;k++){ //recorre el arreglo
        p=k;  //se le asigna una variable p a la posición actual 
        for(i=k+1; i<=n-1; i++){ //recorre el arreblo desde un lugar posterior a la posición actual 
            if(A[i]<A[p]) //si la posición posterior a la actual es menor a la actual 
                p=i; //se le asigna a p el valor más pequeño 
        }
        temp=A[p]; //se le asigna a una variable temporal el valor de p
        A[p]=A[k]; //se intercambia el valor de la posición k a la posición p
        A[k]=temp; //a la posición k se le asigna el valor de la variable temporal 
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
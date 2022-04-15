/*
    *****************************************************************
    Curso: Análisis de algoritmos
    ESCOM-IPN
    Algoritmo de búsqueda Exponencial
    Compilación: "gcc main.c tiempo.x  -o main (tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
    Ejecución: "./main n" (Linux y MAC OS)
    *****************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tiempo.h"


int busquedaBinariaMini(int array[], int n, int x);
int busquedaBinaria(int array[], int l, int r, int x);
int busquedaExponencial(int arr[], int n, int x);
int BusquedaDeFibonacci(int array[], int n, int x);
int *array;
int min(int a, int b);


#define TRUE 1
#define FALSE 0
#define TAMANO_A 20


int num; //elementos en el arreglo, indicará el número de enteros a buscar
double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos


int main(int argc, char *argv[]){


      if (argc > 2) {
        int algoritmoBusqueda; //parámetro que representa que algoritmo de busqueda que se utilizará
        int valorABuscar, valorEncontrado;
        //se obtienen los primeros 3 parametros escritos en consola (los volvemos enteros) 
        //---------- se ingresa algoritmo -> tamaño -> valorabuscar---------------//
        algoritmoBusqueda = atoi(argv[1]);
        num = atoi(argv[2]);
        valorABuscar = atoi(argv[3]);


        array = malloc(sizeof(int) * num);
        int i;


        for (i = 0; i < num; ++i) { //recoge los valores del .txt gracias al redireccionamiento en la consola (<)
            scanf("%d", &array[i]);
        }


        
        printf("======================================================================\n");
        switch (algoritmoBusqueda) {
case 4: //busqueda exponencial
                printf("Busqueda exponencial\n");
                valorEncontrado = busquedaExponencial(array, num, valorABuscar);
                uswtime(&utime1, &stime1, &wtime1);//Evaluar los tiempos de ejecución
                break;
default:
                exit(0);
                break;
        }
//printf("\nContenido del arreglo:\n");
        //ImprimeArr(array);
        //printf("Num[%d]: %d.\n", num, array[num-1]);
        printf("\nTamaño del arreglo (n): %d\n", num);
        printf("\nElemento a buscar (x): %d\n", valorABuscar);
        printf("Coincidencias: %s\n", valorEncontrado != -1 ? "Si" : "No");


        //Mostrar los tiempos con 10 decimas
        printf("\n");
        printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
        printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
        printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
        printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
        printf("\n");


        //Mostrar los tiempos en formato exponecial
        printf("\n");
        printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
        printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
        printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
        printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
        printf("\n");
    }


    return 0;
}
int busquedaExponencial(int array[], int n, int x){
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);


    // Checa si el valor a buscar se encuentra en la primera posición
    if (array[0] == x)
        return 0;
 
    // Se calcula un rango para la busqueda binaria elevando 2^n su paso y verificando 
    //que el index sea menor o igual al valor a encontrar
    int i = 1;
    while (i < n && array[i] <= x)
        i = i*2;
 
    //Se hace una busqueda binaria con el rango calculado.
    return busquedaBinaria(array, i/2, min(i, n-1), x);
}

/*
    *****************************************************************
    Curso: Análisis de algoritmos
    ESCOM-IPN
    Algoritmo de búsqueda de Fibonacci
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
  case 5: //busqueda de Fibonacci
                printf("Busqueda de Fibonacci\n");
                valorEncontrado = BusquedaDeFibonacci(array, num, valorABuscar);
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

                                                                           int BusquedaDeFibonacci(int array[], int n, int x){
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);


    /* Inicializa los primeros números de Fibonacci */
    int fibMMm2 = 0; // (m-2)ésimo numero de Fibonacci.
    int fibMMm1 = 1; // (m-1)ésimo numero de Fibonacci.
    int fibM = fibMMm2 + fibMMm1; // (m)ésimo numero de Fibonacci
 
    /* la variable fibM se encargará de guardar el número de Fibonacci más 
    pequeño que sea menor o igual a n */
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
 
    // Marca el rango eliminado del frente
    int compensacion = -1;
 
    /* 
       El while se cumplira mientras haya elementos con los que se puede operar
       Dentro del while se compara que el valor de arr[fibMm2] con el valor a buscar
       Cuándo fibM toma el valor de 1, fibMm2 toma el valor de 0  */
    while (fibM > 1) {
        // Verifica que fibMm2 isea una valida locacion
        int i = min(compensacion + fibMMm2, n - 1);
 
        /* Si el número buscar es mayor que el valor en el index de fibMm2,
        se corta el rango del arreglo desde la compensasion hasta i*/
        if (array[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            compensacion = i;
        }
 
        /* Si el número buscar es menor que el valor en el index de fibMm2,
           se corta el rango después de i+1  */
        else if (array[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
 
        /* El valor a buscar es encontrado y se retorna su posicion */
        else
            return i;
    }
 
    /* Compara el ultimo elemento con el numero a encontrar */
    if (fibMMm1 && array[compensacion + 1] == x)
        return compensacion + 1;
 
    // Si no se encuentran coincidencias se retorna -1
    return -1;
}


int min(int a, int b){
    return (a < b ? a : b);// retorna el número más pequeño a través de un ternario
}

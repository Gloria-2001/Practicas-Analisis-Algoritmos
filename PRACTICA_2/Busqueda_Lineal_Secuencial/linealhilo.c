/*
    *****************************************************************
    Curso: Análisis de algoritmos
    ESCOM-IPN
    Algoritmo de búsqueda Búsqueda Lineal o Secuencial
    Compilación: "gcc main.c tiempo.x  -o main (tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
    Ejecución: "./main n" (Linux y MAC OS)
    *****************************************************************
*/

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>//libreria de hilos
#include "tiempo.h"
//*****************************************************************
//DECLARACIONES
//*****************************************************************
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************
struct parametros{// Nuestro nodo del árbol contendrá hijo izquierdo, derecho y un número entero
    int iz; 
    int de; 
    int x;
};
//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void* linealSearch(void *todo); 
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int *A, encontrado=0;//Apuntador a int para hacer arreglo
//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main(int argc, char *argv[])
{	//******************************************************************	
	//Variables del main
	//******************************************************************
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
    //Variables globales
    int n, i, x, result, medio;
    //Hilos
    pthread_t h[2];
	 //******************************************************************	
	//Recepción y decodificación de argumentos
    //Si no se recibe el argumento, se cierra el programa
    if(argc!=3) 
        exit(1);
        //Numero elementos en el arreglo
    n=atoi(argv[1]);// Identifica el número de datos sobre los que se va a trabajar
    x=atoi(argv[2]);// Asigna el número que se va a buscar
    printf("\nx = %i\nn = %i\n",x,n);
    //Se crea el arreglo
    A = malloc(n*sizeof(int));
    //Guardando los numeros
    for(i=0;i<n;i++)
        scanf("%i",&A[i]);
    //Para sacar la mitad
    medio=n/2;
    //Creacón deStructs para los hilos
    struct parametros *todo1 = (struct parametros *)malloc(sizeof(struct parametros));
    todo1 -> iz = 0;
    todo1-> de = medio;
    todo1-> x = x;
    struct parametros *todo2 = (struct parametros *)malloc(sizeof(struct parametros));
    todo2-> iz = medio-1;
    todo2-> de = n;
    todo2-> x = x;
    //******************************************************************    
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************    
    uswtime(&utime0, &stime0, &wtime0);
    //******************************************************************
    pthread_create(&h[0],NULL,linealSearch,(void *)todo1);
    pthread_create(&h[1],NULL,linealSearch,(void *)todo2);
    //Se espera a que terminen
    for(int i = 0;i < 2;i++)
        pthread_join(h[i],NULL);
    //Se imprime si se encontró o no
    (encontrado == 1)? printf("Y\n") : printf("N\n");
    //******************************************************************    
    //Evaluar los tiempos de ejecución 
    //******************************************************************
    uswtime(&utime1, &stime1, &wtime1);
    //Cálculo del tiempo de ejecución del programa
    printf("\nTiempo = %.10f s\n\n",  wtime1 - wtime0);
    //******************************************************************
    for(i = 0;i < 27;i++)
        printf("*");// Adjuntamos una division para el resultado de la búsqueda de cada número

    printf("\n");

    return 0;
}
/*
Descripción: Función encargada de buscar nuestro número
Recibe: Todos los argumentos que se comprimieron con anterioridad
*/
void* linealSearch(void *todo) 
{ 
    //Se descomprime lo que se mando
    struct parametros *recibido =  (struct parametros *)malloc(sizeof(struct parametros));
    recibido = (struct parametros *)todo;
    int iz = recibido -> iz;
    int de = recibido -> de;
    int x = recibido->x;
    for(int i = iz; i < de ; i++)//creamos un for que recora el arreglo
    {
        if(A[i] == x)//identifica si el número buscado se encuentra en el arreglo 
        {
            encontrado=1;//si el valor fue encontrado nuestra varible "encontrado" imprimira el valor de 1
            return;
        }
    }
    return;
} 
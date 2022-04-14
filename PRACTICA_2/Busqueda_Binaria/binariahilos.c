/*
    *****************************************************************
    Curso: Análisis de algoritmos
    ESCOM-IPN
    Algoritmo de búsqueda Búsqueda Lineal o Secuencial
    Compilación: "gcc binariahilo.c tiempo.x  -o binariahilo (tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
    Ejecución: "./binariahilo n" (Linux y MAC OS)
    *****************************************************************
*/


//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#include <pthread.h>
#include <math.h>

//*****************************************************************
//Declaracion de funciones
//*****************************************************************
int binaria(void *arguments);
//*****************************************************************
//Declaracion de estructuras
struct bin_args
{
    int *arr;
    int l;
    int r;
    int x;
};

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[])
{	
	//******************************************************************	
	//Variables del main
	//******************************************************************
	//Variables para medición de tiempos
	double utime0, stime0, wtime0,utime1, stime1, wtime1; 

	//Variables del algoritmo
	int n,x,i;

	//Apuntador para el arreglo
	int *arr;

	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=3) 
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
		x=atoi(argv[2]);
	}
	
	//Creacion del arreglo
	arr=malloc(n*sizeof(int));

	printf("\n El valor a buscar es %d en arreglo tamaño %d\n",x,n);

	//Guardado de numeros
	for(i=0;i<n;i++){
		scanf("%i",&arr[i]);
	}

	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo
	//******************************************************************	
	//Se llama a la funcion binaria
	pthread_t threads[4];
    int res[4], mod = n % 4, part = n / 4;

    for (i = 0; i < 4; i++)
    {
        struct bin_args arg;
        pthread_t thread;
        threads[i] = thread;
        arg.arr = arr;
        arg.x = x;
        arg.l = part * i;
        if (mod != 0 && i == 3)
            arg.r = part * (i + 1) - 1 + mod;
        else
            arg.r = part * (i + 1) - 1;


        res[i] = pthread_create(&threads[i], NULL, &binaria, (void *)&arg);
        pthread_join(threads[i], NULL);
    }
	//******************************************************************
	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
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
	//******************************************************************
	//Terminar programa normalmente	
	return 0;	
}

int binaria(void *arguments){
	pthread_detach(pthread_self());
    struct bin_args *args = arguments;
    int *arr = args->arr;
    int l = args->l;
    int r = args->r;
    int x = args->x;
    int times = log(r + 1) / log(2);
    int mid, valor= -1;
	for (int i = 0; i <= times; i++)
    {
        if (r >= l)
        {
            mid = l + (r - l) / 2;
            if (arr[mid] == x)
            {
                valor = mid;
                break;
            }
            else if (arr[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
	(valor == -1) ? printf("El valor %d no esta en esta parte del arreglo\n",x)
                  : printf("El valor esta en la posicion %d\n", valor);
}
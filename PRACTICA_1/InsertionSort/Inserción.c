//***********************
//
//Curso: An�lisis de algoritmos
//Marzo 2022
//ESCOM-IPN
//Medicion de los tiempos en los que tarda el algoritmo "Insercion" para ordenar n numeros
//Compilacion: "gcc Inserción.c tiempo.x -o Inserci�n.out
//(De cada uno de las librerias se pone el ".c" si se tiene la implementaci�n de la libreria � ".o" si solo se tiene el codigo objeto)
//Ejecucion: "./Inserción n" (oLinux y MAC OS)
//***********************

//*****************************************************************
//Librerias incluidas
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main(int argc, char* argv[]){
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n, i, j, temp; // Tama�o de arreglo, auxiliar para cambio y contadores para los ciclos
	int* A; // Apuntador para el arreglo de elementos
	
	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	
	if (argc!=2) 
	{
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
	}
	A = (int*)malloc(n*sizeof(int)); // Asignaci�n de memoria para el arreglo  de elementos
	for(i=0;i<n;i++){ // Ciclo de lectura de datos
		scanf("%i", &A[i]);
	}
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************	
	
	//******************************************************************	
	// Algoritmo de ordenamiento por incersi�n
	//******************************************************************	
	for(i=0; i<=n-1; i++){
		j=i;
		temp = A[i];
		while((j>0)&&(temp<A[j-1])){
			A[j]=A[j-1];
			j--;
		}
		A[j]=temp;
	}
	//******************************************************************	

		
	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);

	//******************************************************************	
	// Impresi�n del arreglo ordenado
	//******************************************************************
	for(i=0;i<n;i++){
        printf("%d\n",A[i]);
    }
	//******************************************************************

	free(A);
	//Cálculo del tiempo de ejecución del programa
	printf("\n\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acci��nes de E/S)  %.10f s\n",  stime1 - stime0);
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
	exit (0);	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************

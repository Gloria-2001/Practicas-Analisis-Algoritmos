/*
    *****************************************************************
    Curso: Análisis de algoritmos
    ESCOM-IPN
    Algoritmo de búsqueda Búsqueda Lineal o Secuencial
    Compilación: "gcc fibohilos.c tiempo.x  -o fibohilos (tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
    Ejecución: "./fibohilos n" (Linux y MAC OS)
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

//*****************************************************************
//Declaracion de funciones
//*****************************************************************
void sub(int A[], int i, int n, int B[]);
void* procesar(void* id);
int min(int x, int y){
    return (x <= y) ? x : y;
}
int fibo(int arr[], int x, int n);

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
	int n,x,i,nt;
	pthread_t *thread;
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
	i=0;

    for(int j=0; j<20; j++){

        for (i=1; i<nt; i++) {    
            if (pthread_create (&thread[i], NULL, procesar,(void*)i) != 0 ) {
                perror("El thread no pudo crearse");
                exit(-1);
            }
        }
        procesar(0);
        
        for (i=1; i<nt; i++){
                pthread_join(thread[i], NULL); 
            }   
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

void sub(int A[], int i, int n, int B[]){
	int aux, cont=0;
	for(aux = i; aux<i+n; aux++){
		B[cont] = A[aux];
		cont ++;
	}
}

void* procesar(void* id){
	int n_thread=(int)id;
	int inicio,fin,ne,n,nt, *datos,x;

	inicio=(n_thread*n)/nt;
	if(n_thread==nt-1){
		fin=n;
		ne=fin-inicio;
	}else{
		fin=((n_thread+1)*n)/nt-1;
		ne = (fin-inicio)+1;
	}
	printf("\nThread %d\tInicio %d\tTermino %d\n",n_thread,inicio, fin);
	int *B = (int*)malloc(ne*sizeof(int));
	sub(datos,inicio,ne,B);
	int result = fibo(B,x,ne);
	if(result!=-1){
		printf("\nNUmero %d encontrado %d\n",x,result);
	}
	if(n_thread!=0){
        pthread_exit(0); 
    }
}

int fibo(int arr[], int x, int n){
	//Se inicializan los numeros de fibonacci
    int fibMMm2 = 0; //el numero en la posicion (m-2)
    int fibMMm1 = 1; //el numero en la posicion (m-1)
    int fibM = fibMMm2 + fibMMm1; //m'th 

    //Guardara el numero que sea mayor a n
    while (fibM < n){
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1; //marca el rango eliminando desde el frente

    //Se compara arr[fibMMm2] con x y se inspeccionan los elementos
    while(fibM > 1){
        //comprueba si MMm2 es valido
        int i = min(offset + fibMMm2, n-1);
        // Si x es mas grande que el valor dentro de fibMm2, corta el arreglo de desplazamiento i
        if(arr[i]<x){
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }else if(arr[i]>x){ // Si x es mas grande que el valor dentro de fibMm2, corta el arreglo de desplazamiento i+1
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }else //el elemento se encontro
            return i;
    }
    //compara el ultimo elemento con x
    if (fibMMm1 && arr[offset + 1]==x)
        return offset +1;
    
    //si el elemento no se encuentra, retorna -1
    return -1;
}
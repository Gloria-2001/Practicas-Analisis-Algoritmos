/*
    *****************************************************************
    Curso: Análisis de algoritmos
    ESCOM-IPN
    Algoritmo de búsqueda Búsqueda Lineal o Secuencial
    Compilación: "gcc exponencialhilos.c tiempo.x  -o exponencialhilos (tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
    Ejecución: "./exponencialhilos n" (Linux y MAC OS)
    *****************************************************************
*/

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <pthread.h>
#include "tiempo.h"
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************
#define min //Definimos la constante para encontrar el minimo de dos numeros
#define MAX_THREAD 4 //Numero máximo de hilos que se utilizarán
//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************
/*
La estructura siguiente contiene 4 elementos, el arreglo de números ordenados, el numero
a buscar, el numero donde inicia el arreglo y donde termina
*/
struct bin_args{
    int *arr;
    int x;
    int inicio;
    int fin;
};

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void *exponentialSearch(int *arr, int n, int x); //Se declara como un apuntador debido a que se utilizará para los hilos
void *binarySearch(void *arguments); //Se declara como apuntador y recibirá una estructura de argumentos, la estructura 
									 //declarada anteriormente
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
bool found = false;
//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[]){	
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i; //Variables para loops
	int *a,x;
	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=3){
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else{
		n=atoi(argv[1]);
	}
	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo
	//******************************************************************	
	printf("\n\nBusqueda exponencial para buscar x=%d con %d numeros",x,n);
	i=0;
	a=malloc(n*sizeof(int));
	
	do{
		scanf("%d",&a[i++]);
	}while(i<n);
	
	x=atoi(argv[2]);

	exponentialSearch(a, n, x);
	
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
	exit (0);	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************

void *binarySearch(void *arguments){
	/*struct bin_args *args=arguments;
	int *a=args->arr;
	int key=args->x;
	int n=args->size;
	int part=0;
	// Each thread checks 1/4 of the array for the key
    int thread_part=part++;
    int mid;
  
    int low=thread_part*(n/4);
    int high=(thread_part+1)*(n/4);

    while (low<high&&!found) {
        mid=(high - low)/2+low;
  
        if (a[mid]==key)  {
            found = true;
            break;
        }
  
        else if (a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }*/
    pthread_detach(pthread_self());
    struct bin_args *args=arguments;
    int *arr=args->arr;
    int l=args->inicio;
    int r=args->fin;
    int x=args->x;
    int times=log(r+1)/log(2);
    int mid,value=-1;

    for (int i=0;i<=times;i++){
        if (r>=l){
            mid =l+(r-l)/2;
            if (arr[mid]==x){
                value=mid;
                break;
            }
            else if(arr[mid]>x)
                r=mid-1;
            else
                l=mid+1;
        }
    }
    if(value==-1)
        printf("El numero a buscar no se encuentra en el arreglo\n");
    else
        printf("El numero a buscar esta en la posicion %d del arreglo\n", value);
}

void *exponentialSearch(int *arr, int n, int x){
	/*pthread_t threads[MAX_THREAD];
  	struct bin_args arg;

    if (arr[0]==x){
        printf("El elemento a buscar esta en la posicion 0 del arreglo\n");
        return 0;
    }else{
    	arg.arr=arr;
    	arg.x=x;
    	arg.size=n;

    	for (int i = 0; i < MAX_THREAD; i++)
        pthread_create(&threads[i], NULL, &binarySearch, (void*)&arg);
  
	    for (int i = 0; i < MAX_THREAD; i++)
	        pthread_join(threads[i], NULL);

	    if(found)
	    	printf("El numero %d se encuentra en el arreglo",x);
	    else
	    	printf("El numero %d no se encuentra en el arreglo",x);
	  
	    // key found in array
	    /*if (found)
	        cout << key << " found in array" << endl;
	  
	    // key not found in array
	    else
	        cout << key << " not found in array" << endl;
	  
	    return 0;
    }*/

    pthread_t threads[4];
    int i = 1, res[4];

    if (arr[0]==x){
        printf("El elemento a buscar esta en la posicion 0 del arreglo\n");
        return 0;
    }

    while (i<n&&arr[i]<=x)
        i=i*2;

    int mod=n%4;

    for (int j=0,part=min(i,n-1)/4;j<4;j++){
        struct bin_args arg;
        pthread_t thread;
        threads[j]=thread;
        arg.arr=arr;
        arg.x=x;
        arg.inicio=part*j;
        if (mod!=0&&j==3)
            arg.fin=part*(j+1)-1+mod;
        else
            arg.fin=part*(j+1)-1;

        res[j]=pthread_create(&threads[j], NULL, &binarySearch, (void *)&arg);
        pthread_join(threads[j],NULL);
    }
}
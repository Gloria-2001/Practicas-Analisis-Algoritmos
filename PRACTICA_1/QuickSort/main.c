/*
    *****************************************************************
    Curso: Análisis de algoritmos
    ESCOM-IPN
    Algoritmo de ordenación Quick Sort
    Compilación: "gcc main.c tiempo.x  -o main (tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
    Ejecución: "./main n" (Linux y MAC OS)
    NOTA: Si se hace desde un script.sh, solo se tienen que cambiar los permisos para que pueda ejecutarse como programa dentro de la computadora y en la terminal poner "./myscript.sh"
    *****************************************************************
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h> 
#include "tiempo.h"

void intercambiar(int elem1, int elem2);
int particionar(int *A, int inicio, int final);
void quickSort(int *A, int inicio, int final);
void mostrar(int *A, int n);

int main(int argc, char **argv){
    //Variables del programa
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //para medir el tiempo
    int *mi_A, p=0, r=0, n, i=0; //para el algoritmo 

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

    //Iniciar conteo para evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);

    //Arreglo en la memoria 
    mi_A = malloc(sizeof(int)*n);
    //Asigna los valores recogidos a una posición del arreglo 
    do{
        scanf("%d", &mi_A[i++]);
    }while(i<n);

    //Algoritmo
    quickSort(mi_A,0,n-1);
    //mostrar(mi_A, n);

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

//hace todo el ordenamiento 
void quickSort(int *A, int inicio, int final){
    if(inicio<final){
        int pi; 
        pi= particionar(A, inicio, final); //se selecciona el pivote
        quickSort(A,inicio,pi-1); //antes del pivote
        quickSort(A,pi+1, final);  //después del pivote
    }
}

/*
    Toma el último elemento como el pivote y pone los menores a él a su izq y los más grandes a su derecha 
*/
int particionar(int *A, int inicio, int final){
    int pivote;
    pivote=A[final];

    int i = inicio -1; //índice del elemento más pequeño e indica la posición correcta del pivote encontrado

    for(int j=inicio ; j<= final-1; j++){ 
        //si el elemento actual es más chico que el pivote
        if(A[j]<pivote){ 
            i++; //se incrementa el index del elemento más peuqeño
            intercambiar(A[i], A[j]); //se intercambian 
        }
    }
    intercambiar(A[i+1], A[final]);
    return (i+1);
}

//cambia 2 elementos
void intercambiar(int elem1, int elem2){
    int temp;
    temp=elem1;
    elem2=elem1;
    elem1=temp;
}

/*
void mostrar(int *A, int n){
    for(int i=0; i<n; i++){
        printf("%d \n", &A[i]);
    }
}*/

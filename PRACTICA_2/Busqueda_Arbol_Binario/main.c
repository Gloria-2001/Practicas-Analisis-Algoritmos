/*
    *****************************************************************
    Curso: Análisis de algoritmos
    ESCOM-IPN
    Algoritmo de búsqueda Búsqueda en ABB
    Compilación: "gcc main.c tiempo.x  -o main (tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
    Ejecución: "./main n" (Linux y MAC OS)
    NOTA: Si se hace desde un script.sh, solo se tienen que cambiar los permisos para que pueda ejecutarse como programa dentro de la computadora y en la terminal poner "./myscript.sh"
    *****************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tiempo.h"

//se crea la estructura del árbol con un valor y 2 apuntadores a la izquierda y derecha 
typedef struct arbolABB{
    int valor;
    struct arbolABB *izquierda;
    struct arbolABB *derecha;
}arbolABB;

arbolABB *crearNodo(int valor);
void imprimirTabulacion(int numTabs);
void imprimirArbol_recursivo(arbolABB *raiz, int nivel);
void imprimirArbol(arbolABB *raiz);
bool insertar(arbolABB **raizptr, int valor, int n);
bool encontrarNumero(arbolABB *raiz, int valor, int n);

int main(int argc, char **argv){
    //Variables del programa
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //para medir el tiempo
    //del algoritmo
    arbolABB *miRaiz = NULL; 
    int *A, x, n;

    //Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=3){
		printf("\nIndique el tamaño del arreglo y el número a buscar- Ejemplo: [user@equipo]$ %s 100 7\n",argv[0]);
		exit(1);
	}
	else{
		n=atoi(argv[1]); //tamanio del arreglo
        x=atoi(argv[2]);  //elemento a buscar 
	}
   
    //creacion arreglo
    A = malloc(sizeof(int)*n);

    //Guardar números en el arreglo
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
        //printf("%d\n", A[i]);
        insertar(&miRaiz, A[i], n);
    }

    imprimirArbol(miRaiz);

    //Iniciar conteo para evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0); 

    //Algoritmo de busqueda
    printf("%d (%d)\n", x, encontrarNumero(miRaiz, x, n));

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

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    exit(0); 
}

//función para crear un nodo del arbo, recibe el valor que ira dentro
arbolABB *crearNodo(int valor){
    arbolABB* nodo = malloc(sizeof(arbolABB)); //se crea el espacio en la memoria
    if(nodo != NULL){  
        //se igualan los 2 aputnadores de izquiera y derecha a nulo, y el valor de la estructura al valor entrante
        nodo->izquierda=NULL;
        nodo->derecha=NULL;
        nodo->valor=valor;
    }
    return nodo;
}

//función para que al imprimir el arbol se hagan las tabulaciones necesarias
void imprimirTabulacion(int numTabs){
    for(int i=0; i<numTabs; i++){
        printf("\t");
    }
}

//función para imprimir el arbol
void imprimirArbol_recursivo(arbolABB *raiz, int nivel){
    //si la raiz esta vacia, se hace una tabulacion y se imprime vacio
    if(raiz==NULL){
        imprimirTabulacion(nivel);
        printf("VACIO \n");
        return;
    }  
    //sino esta vacio igual imprime una tabulacion y el valor, y de nuevo imprime otra tabulacion
    imprimirTabulacion(nivel);
    printf("Valor: %d\n", raiz->valor);
    imprimirTabulacion(nivel);
    printf("izq: \n");
    
    //vamos por el lado izquierdo y hacemos lo mismo, solo aumentamos el nivel
    imprimirArbol_recursivo(raiz->izquierda, nivel+1);

    imprimirTabulacion(nivel);
    printf("der: \n");

    //vamos hacia el lado derecho e imprimimos también
    imprimirArbol_recursivo(raiz->derecha, nivel+1);

    imprimirTabulacion(nivel);
    printf("listo\n");
}

void imprimirArbol(arbolABB *raiz){
    imprimirArbol_recursivo(raiz,0);
}

//funcion para insertar 
bool insertar(arbolABB **raizptr, int valor, int n){
    arbolABB *raiz = *raizptr; 
    if(raiz==NULL){
        //arbol vacío, se crea un nuevo nodo
        (*raizptr)=crearNodo(valor);
        return true;
    }
    //si el valor a insertar ya esta
    if(valor==raiz->valor){
        //hacer nada
        return false;
    }

    //vamos desde 0 hasta la altura del arbol
    //se hace lo mismo que vimos anteriormente, solo que del lado izquierdo y derecho 
    for(int i=0;i<n;i++){
        if(valor<raiz->valor){
            raizptr=&(raiz->izquierda);
            raiz=*raizptr;
            if(raiz==NULL){
                (*raizptr)=crearNodo(valor);
                return true;
            }
            if(valor==raiz->valor){
                //hacer nada
                return false;
            }
            //return insertar(&(raiz->izquierda), valor);
        }else{
            raizptr=&(raiz->derecha);
            raiz=*raizptr;
            if(raiz==NULL){
                (*raizptr)=crearNodo(valor);
                return true;
            }
            if(valor==raiz->valor){
                //hacer nada 
                return false;
            }
            //return insertar(&(raiz->derecha), valor);
        }
    }
}

bool encontrarNumero(arbolABB *raiz, int valor, int n){
    /*
        Estos 2 primeros if se refieren a la raiz del arbol, si la raiz esta vacía, no se encuentra el valor
        Si el apuntador de la raíz a valor en la estructura del arbol es igual al valor buscado, se encontró
    */
    if(raiz==NULL){
        printf("Valor NO encontrado\n");
        return false; 
    }
    if(raiz->valor==valor){
        printf("Valor encontrado\n");
        return true;
    }
    /*
        Aquí nos vamos al lado izquierdo, que es cuando el valor a buscar es menor que el valor en la raíz. 
        Recorremos toda la parte del lado izquierdo, y de igual forma si en el nodo no hay ningun valor (NULL)
        pues no se encuentra el valor, pero si el valor del nodo es igual al buscado, pues regresa un true
    */
    for(int i=0; i<n; i++){
        if(valor<raiz->valor){
            raiz=raiz->izquierda; 
            if(raiz==NULL) {
                printf("Valor NO encontrado\n");
                return false; 
            }
            if(raiz->valor==valor){
                printf("Valor encontrado\n");
                return true;
            }
            //return encontrarNumero(raiz->izquierda, valor);
        }
        /*
            Lo mismo que se hizo en el lado izquierdo se hace en el derecho. Se va a pasar al lado derecho
            cuando el valor sea mayor.
        */
        else{
            raiz=raiz->derecha; 
            if(raiz==NULL) {
                printf("Valor NO encontrado\n");
                return false;
            } 
            if(raiz->valor==valor){
                printf("Valor encontrado\n");
                return true;
            }
            //return encontrarNumero(raiz->derecha, valor);
        }
    }
}
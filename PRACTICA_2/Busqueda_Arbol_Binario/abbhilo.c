/*
    *****************************************************************
    Curso: Análisis de algoritmos
    ESCOM-IPN
    Algoritmo de búsqueda Búsqueda Lineal o Secuencial
    Compilación: "gcc abbhilo.c tiempo.x  -o abbhilo (tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
    Ejecución: "./abbhilo n" (Linux y MAC OS)
    *****************************************************************
*/

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include "tiempo.h"
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************
typedef struct node															// Nuestro nodo del �rbol contendr� hijo izquierdo, derecho y un n�mero entero
{
	struct node *left, *right;
	int number;
}node;
//DEFINICIONES DE SIN�NIMOS
typedef node* position;														// La posici�n ser� la direcci�n hacia un nodo espec�fico
typedef position arbol_bin;	
arbol_bin mainTree;
//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void * search(void *root);
void initialize(arbol_bin *BinaryTree);
void insert(arbol_bin * BinaryTree, int newNumber);
//void subTrees(position aux[], arbol_bin * BinaryTree, int n);
//void imprimeTiempos(bool found, int keyNumber, int nSize, double RealTime, double UserTime,double SysTime);
int Vacio(arbol_bin *a);
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
bool found = false; //variable que indicar� si se encontr� el n�mero en la b�squeda
int* Data; //apuntador de entero que ser� inicializado como arreglo para los datos donde se buscar�
int nSize = 0; //variable que tomar� el tama�o de la l�nea de comando
int nThreads = 0;  //variable que tomar� el n�mero de hilos
int keyNumber = 0; //variable que indicar� el n�mero a buscar
//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[])
{	
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i; //Variables para loops

	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	if (argc < 4) exit(0);	// Verificacion sencilla
	
	nSize = atoi(argv[1]);	// Identifica el numero de datos sobre los que se va a trabajar
	nThreads = atoi(argv[2]);	// Toma el numero de hilos a trabajar
	keyNumber = atoi(argv[3]);	// Asigna el numero que se va a buscar
	
	Data = (int*)calloc(nSize,sizeof(int));	// Inicializacion del arreglo para los numeros

	for (i = 0; i < nSize; ++i){
		scanf("%d", Data+i);			// Insertamos los numeros en el arreglo
	}

	initialize(&mainTree);	// Iniciamos nuestro ABB para usarlo

	for(i = 0; i < nSize; ++i){
		insert(&mainTree, Data[i]);	// Insertamos los datos en el ABB
	}
	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	position aux[nThreads];	// Arreglo de posiciones a partir de las cuales se realizar� la b�squeda
	for (i = 0; i < nThreads; ++i)
	{
		aux[i] = NULL;
	}

	//subTrees(aux, &mainTree, nThreads);

	/*switch(nThreads){	// Switch-Case con base al n�mero de hilos

		case 2:	// En caso de 2 hilos
		// Iniciaremos la b�squeda en los dos sub�rboles de la ra�z
			aux[0] = mainTree->left;
			aux[1] = mainTree->right;
			break;

		case 3:	// En caso de 3 hilos
		// Los dos primeros hilos iniciar�n en los dos sub�rboles del sub�rbol izquierdo
			aux[0] = (mainTree->left)->left;
			aux[1] = (mainTree->left)->right;
		// El �ltimo hilo iniciar� en el sub�rbol derecho
			aux[2] = mainTree->right;
			break;

		case 4:	// En caso de 4 hilos
		// Iniciaremos la b�squeda en los sub�rboles de los dos hijos de la ra�z
			aux[0] = (mainTree->left)->left;
			aux[1] = (mainTree->left)->right;
			aux[2] = (mainTree->right)->left;
			aux[3] = (mainTree->right)->right;
			break;

	}*/

	// En caso de que el n�mero se encuentre en la ra�z o en sus dos hijos, no iniciamos las b�squedas
	if(!found){	
		pthread_t *aThreads;	// Declaramos un arreglo de hilos
		aThreads = (pthread_t*) malloc(nThreads*sizeof(pthread_t));	// Inicializaci�n del arreglo de hilos

		for (i = 0; i < nThreads; ++i)
		{
			pthread_create(&aThreads[i], NULL, search, (void*)aux[i]);	// Crear los hilos con el comportamiento "segmentar"
		}

		for (i = 0; i < nThreads; ++i)
		{
			pthread_join(aThreads[i], NULL);	// Se verifica la finalizaci�n de todos los hilos
		}

		free(aThreads);	// Liberamos el arreglo de hilos
	}

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
	
	//imprimeTiempos(found, keyNumber, nSize, RealTime, UserTime, SysTime); // Funci�n que mostrar� los resultados
	free(Data);	// Liberamos el arreglo de n�meros
	//Terminar programa normalmente	
	exit (0);	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************
/*
Descripci�n: Funci�n encargada de buscar en los n�meros por medio de un �rbol Binario de B�squeda
Recibe: void * root (Ser� el apuntador a la ra�z sobre la que vamos a buscar)
*/
void * search(void *root){
position aux = (position)root;	// Posici�n auxiliar que nos permitir� movernos en el ABB

	while(aux != NULL && !found){ // Iteraci�n que durar� hasta que ya no haya elementos donde buscar o se haya encontrado el n�mero en otro hilo

		if(aux->number == keyNumber){	// En caso de encontrar el n�mero
			found = true;	// Indicamos que fue encontrado
		}

		if(aux->number > keyNumber){	// En caso de que el n�mero en el que estamos sea mayor que el buscado
			aux = aux->left;	// Nos moveremos al sub�rbol izquierdo
		}
		else{	// En caso contrario
			aux = aux->right;	// Nos movemos al sub�rbol derecho
		}
	}
	pthread_exit(NULL);	// Salimos del hilo
}
/*
Descripci�n: Funci�n encargada de inicializar la estructura del ABB
Recibe: arbol_bin *BinaryTree (apuntador al ABB declarado por el usuario)
*/
void initialize(arbol_bin *BinaryTree){
	*BinaryTree = NULL;	                 // El apuntador enviado por el usuario se coloca en un valor NULL
	return;
}

/*
Descripci�n: Funci�n encargada de insertar un nuevo elemento en el ABB
Recibe: arbol_bin * BinaryTree (apuntador al ABB utilizado por el usuario), 
	int newNumber (nuevo elemento que se va a incluir en el ABB) 
*/
void insert(arbol_bin * BinaryTree, int newNumber){
	arbol_bin * aux = BinaryTree; 			// Declaramos un apuntador para recorrer el �rbol
	while(*aux != NULL){				    // Recorremos el �rbol hasta encontrar el espacio libre donde ir� el nuevo elemento
		if (newNumber > ((*aux)->number))   // En caso de que el valor sea mayor, iremos a la parte derecha del �rbol
		{
			aux = &((*aux)->right);
		}
		else{							// Caso contrario, viajaremos a la parte izquierda del �rbol
			aux = &((*aux)->left);
		}
	}
	*aux = (node *)malloc(sizeof(node));  // Una vez ubicados en su lugar, le haremos espacio en memoria al nuevo nodo
	(*aux)->number = newNumber;			  // En el nodo colocaremos el n�mero que desea introducir el usuario al �rbol
	(*aux)->left = NULL;				// Nos aseguramos de que ambos hijos est�n apuntando a un valor NULL para evitar errores
	(*aux)->right = NULL;
	return;
}

/*
Descripci�n: Funci�n encargada de imprimir los tiempos de ejecuci�n de los programas
Recibe: 
	bool found (indica si se encontr� el n�mero en la b�squeda)
	int keyNumber (n�mero que se busc�)
	int nSize (n�mero de datos sobre los que se realiz� la b�squeda)
	double SysTime (tiempo del sistema)
	double UserTime (tiempo del usuario)
	double RealTime (tiempo real)
*/
/*void imprimeTiempos(bool found, int keyNumber, int nSize, double RealTime, double UserTime,double SysTime){
	if (found)
	{
		printf("\nKey Number = %i Encontrado\n", keyNumber);
	}else{
		printf("\nKey Number = %i No Encontrado\n", keyNumber);
	}
	printf(" n = %i\n", nSize);
	printf("Real Time: \t%.10f\n", RealTime);
	printf("User Time: \t%.10f \n", UserTime);
	printf("System Time: \t%.10f\n", SysTime);
}*/
/*
Descripci�n: Funci�n que devolver� los sub�rboles necesarios para iniciar los hilos
Recibe: position aux[] (arreglo de posiciones donde a�adiremos los apuntadores a los sub�rboles),
	arbol_bin *BinaryTree (apuntador al ABB utilizado por el usuario),
	int n (n�mero de hilos inicial que se ir� reduciendo)
*/
void subTrees(position aux[], arbol_bin * BinaryTree, int n){
	
	while(Vacio(BinaryTree) != 1)
	{
		// Si el nodo en el que estamos contiene el valor
		// significa que fue encontrado
		if((*BinaryTree)->number == keyNumber){
		found = true;
		break;
		}
		else if((*BinaryTree)->number < keyNumber)
		{
			// Si el valor que buscamos es mayor
			// al del nodo en el que nos encontramos
			// nos movemos a la derecha
			BinaryTree = &((*BinaryTree)->right);
		}		
		else if((*BinaryTree)->number > keyNumber)
		{
			// Si el valor que buscamos es menor
			// al del nodo en el que nos encontramos
			// nos movemos a la izquierda
			BinaryTree = &((*BinaryTree)->left);
		}
	}
}

/*
  Descripcion: Funci�n que determina si un arbol est� vac�o
  Regresa 1 en caso de que est� vac�o y 0 en otro caso
 */
int Vacio(arbol_bin *a){
	if(*a == NULL)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

// Arbol Binario de Busqueda y recorrido InOrden
// Arbol Binario de Busqueda y recorrido InOrden


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "tiempo.h"

int posicion = 0; 

struct arbol *crearArbol(struct arbol *a)
{
    a = NULL;
    return a;
}




struct arbol *insertarNumeros(struct arbol *a, int num)
{
    if (a == NULL)
    {
        struct arbol *aux = NULL;
        aux = (struct arbol *)malloc(sizeof(struct arbol));
        aux->nodo_izq = NULL;
        aux->nodo_der = NULL;
        aux->numero = num;

        return aux;
    }

    if (num < (a->numero))
        a->nodo_izq = insertarNumeros(a->nodo_izq, num);
    else
        a->nodo_der = insertarNumeros(a->nodo_der, num);

    return a;
}


void guardarRecorridoInOrden(struct arbol *a, int *arreglo)
{
    if (a != NULL)
    {
        guardarRecorridoInOrden(a->nodo_izq, arreglo);
        *(arreglo + posicion) = a->numero;
        posicion++;
        guardarRecorridoInOrden(a->nodo_der, arreglo);
    }
}



int main(int narg, char **varg)
{
    int n, *numeros;
    double utime0,stime0,wtime0,utime1,stime1,wtime1;  
    


    struct arbol *a;
    a = crearArbol(a);



    if (narg != 2)
    {
        exit(1);
    }

    n = atoi(varg[1]);

    numeros = malloc(sizeof(int) * (n));
    if (numeros == NULL)
    {
        exit(1);
    }


    for (int i = 0; i < n; i++)
        scanf("%d", &numeros[i]);


    uswtime(&utime0,&stime0,&wtime0);


    for (int j = 0; j < n; j++)
        a = insertarNumeros(a, numeros[j]);

    guardarRecorridoInOrden(a, numeros);
    uswtime(&utime1, &stime1, &wtime1);

    printf("%d>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>", n);

    printf("\n");
    printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
    printf("sys (Tiempo en acciÃ³nes de E/S)  %.10f s\n",  stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");
    

    printf("\n");
    printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
    printf("sys (Tiempo en acciÃ³nes de E/S)  %.10e s\n",  stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n\n");

	exit (0);
}

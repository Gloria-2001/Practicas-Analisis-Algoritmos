#include <stdio.h> 
#include <stdlib.h>

void mergeSort(int *arreglo, int elementos){
    int i;
    int mitad, restante;
    int indiceIzquierda, indiceDerecha;
    int *copiaIzquierda, *copiaDerecha;

    /*Si ya sólo es 1 elemento, ya está ordenado el arreglo*/
    if(elementos == 1){
        return;
    }

    /*
    Si hay más de 1 elemento, hay que ordenarlo : 
    Hay que partir el arreglo en 2 partes.
    Uno que contenga la primer mitad de elementos.
    Y otra que contenga la segunda mitad de elementos.
    Por eso calculamos <<mitad>> para saber cuántos habrá en la mitad izquierda
    y <<restante>> es lo que habrá en la derecha. Esto porque si n es impar 
    pueden ser diferentes estos números.
    */
    mitad = elementos / 2;
    restante = elementos - mitad;    
    copiaIzquierda = malloc(mitad * sizeof(int));
    copiaDerecha = malloc(restante * sizeof(int));

    /* Copiamos los elementos del original a sus respectivas mitades */
    for(i = 0; i < mitad; i ++){
        copiaIzquierda[i] = arreglo[i];
    }

    for(i = 0; i < restante; i ++){
        copiaDerecha[i] = arreglo[mitad + i];
    }

    /*
    Ordenamos recursivamente. Es decir, después de llamar merge(), cada mitad 
    estará ordenada
    */
    mergeSort(copiaIzquierda, mitad);
    mergeSort(copiaDerecha, restante);
    
    /*
    Ahora hay que unir las 2 mitades ya ordenadas para que el completo esté
    ordenado también
    */

    indiceIzquierda = 0;
    indiceDerecha = 0;

    i = 0;
    /*
    En cada momento hay que preguntar, ¿Cuál va primero, el de la izquierda o el de la derecha? 
    Y hay que tomar el más pequeño. Así sabemos que al final, <<arreglo>> esta ordenado. 
    ¿ Por qué? Imaginemos que la mitad izquierda se ve así : 
    a < b < c < d < ... porque está ordenado
    Y luego la derecha: 
    A < B < C < D < ... 
    Así, supongamos si estamos comparando un elemento s de la izquierda y un S de la derecha, sabemos que
    si el arreglo tiene elementos 
    w1 < w2 < w3 < w4 < ... < wk, entonces w1, w2, w3, w4, ..., wk < s y que w1, w2, w3, w4, ..., wk < S 
    porque hemos puesto valores menores a s y S ya que las mitades estaban ordenadas anteriormente
    entonces si ponemos a s y S en orden entonces el arreglo estará ordenado.
    */
    while(indiceIzquierda < mitad && indiceDerecha < restante){
        if(copiaIzquierda[indiceIzquierda] < copiaDerecha[indiceDerecha]){            
            arreglo[i] = copiaIzquierda[indiceIzquierda];            
            indiceIzquierda ++;
        } else {
            arreglo[i] = copiaDerecha[indiceDerecha];
            indiceDerecha ++;
        }
        i ++;
    }
    
    /* Ahora, si ya se acabó la mitad derecha, hay que terminar de pasar la mitad izquierda */
    while(indiceIzquierda < mitad){
        arreglo[i] = copiaIzquierda[indiceIzquierda];            
        indiceIzquierda ++;
        i ++;
    }

    /* Y si se acabó la mitad izquierda, hay que vaciar la mitad derecha */
    while(indiceDerecha < restante){
        arreglo[i] = copiaDerecha[indiceDerecha];
        indiceDerecha ++;
        i ++;
    }
}

int main(void){
    int n ; 
    int i;
    int *arreglo;
    
    /* leer n */
    scanf("%d", &n);
    
    /* crear un arreglo de tamaño n */
    arreglo = malloc(n * sizeof(int));
    
    /* leer los n elementos */
    for(i = 0; i < n; i++){
        scanf("%d", &arreglo[i]);
    }

    /* ordenarlos */
    mergeSort(arreglo, n);

    /* imprimirlos */
    for(i = 0; i < n; i ++){
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Nodo{
    int numero; 
    struct Nodo *izquierda;
    struct Nodo *derecha; 
};

struct Nodo *nuevoNodo(int numero){
    size_t tamNodo = sizeof(struct Nodo);
    struct Nodo *nodo = (struct Nodo *)malloc(tamNodo);
    nodo->dato=dato;
    nodo->izquierda=nodo->derecha=NULL;
    return nodo;
}

void insertar(struct Nodo *nodo, int numero){
    if(numero>nodo->dato){
        if(nodo->derecha==NULL){
            nodo->derecha=nuevoNodo(numero);
        }else{
            insertar(nodo->derecha, numero);
        }
    }else{
        if(nodo->izquierda==NULL){
            nodo->izquierda=nuevoNodo(numero);
        }else{
            insertar(nodo->izquierda, numero);
        }
    }
}

void inorden(struct Nodo *nodo){
    if(nodo!=NULL){
        inorden(nodo->izquierda);
        inorden(nodo->derecha);
    }
}

int main(int argc, char **argv){
    int *A, n;
    A = malloc(sizeof(int)*n);
    struct Nodo *abba = nuevoNodo(A[0])
    for(int i=0; i<=n-1; i++){
        insertar(abba, A[i]);
    }
    inorden(abba);
    return 0; 
}
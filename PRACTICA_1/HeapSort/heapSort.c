#include <stdio.h>
#include <stdlib.h>

struct Heap{
    int *heap;
    int capacidad;
    int iUltimo; 
};

void Construir(Heap *h, int tam){
    h->capacidad = tam;
    h->iUltimo = 0;
    h->heap = (int*)malloc(sizeof(int) * tam);
}

void MonticuloDesdeArray(Heap *h, int *vec, int tam) {
    int i;

    h->capacidad = tam;
    h->iUltimo = tam;
    h->heap = (int*)malloc(sizeof(int) * h->capacidad);
    for(i = 0; i < h->iUltimo; i++) h->heap[i] = vec[i];
    Convertir(*h);
}

void Destruir(Heap *h) {
    free(h->heap);
}

void Convertir(Heap h) {
    int i;

    for(i = h.iUltimo/2; i >= 0 ; i--) {
        Bajar(h, i);
    }
}

void Insertar(Heap *h, int v) {
    if(h->iUltimo >= h->capacidad) Reubicar(h, h->capacidad*2);

    h->heap[h->iUltimo++] = v;
    Subir(*h, h->iUltimo-1);
}

void Borrar(Heap *h, int i) {
    if(i < h->iUltimo) {
        h->heap[i] = h->heap[--h->iUltimo];
        Bajar(*h, i);
    }
}

int ExtraerMaximo(Heap *h) {
    int retval = h->heap[0];

    Borrar(h, 0);

    return retval;
}

void Reubicar(Heap *h, int ncap) {
    int *heap2;
    int i;

    heap2 = (int*)malloc(sizeof(int) * ncap);
    for(i = 0; i < h->iUltimo; i++) heap2[i] = h->heap[i];
    if(h->heap) free(h->heap);
    h->heap = heap2;
    h->capacidad = ncap;
}

void Intercambia(Heap h, int i1, int i2) {
    int aux;

    aux = h.heap[i1];
    h.heap[i1] = h.heap[i2];
    h.heap[i2] = aux;
}

// Algoritmo no recursivo para subir
void Subir(Heap h, int i) {
    int iPadre;

    while(i > 0 && h.heap[i] > h.heap[iPadre=Padre(h, i)]) {
        Intercambia(h, i, iPadre);
        i = iPadre;
    }
}

void Bajar(Heap h, int i){
    int iIzq, iDer, maximo;

    maximo = i;
    do{
        i = maximo;
        iIzq=Izquierdo(h, i);
        iDer=Derecho(h, i);
        if(iDer < h.iUltimo && h.heap[iDer] > h.heap[maximo]) maximo = iDer;
        if(iIzq < h.iUltimo && h.heap[iIzq] > h.heap[maximo]) maximo = iIzq;
        if(i != maximo) Intercambia(h, i, maximo);
    } while (i != maximo && maximo < h.iUltimo/2);
}

int Padre(Heap h, int i) {
    return (i-1)/2;
}

int Izquierdo(Heap h, int i) {
    return 2*i+1;
}

int Derecho(Heap h, int i) {
    return 2*i+2;
}

int Vacio(Heap h) {
    return h.iUltimo == 0;
}

int main()
{
    int *A, n; 
    A = malloc(sizeof(int)*n);
    Heap h1;
    
    for(int i=0; i<=n-1;i++){
        Insertar(h1, A[i]);
    }

    for(int j=0; j<=n-1; j++){
        A[j]=ExtraerMaximo(h1);
    }
    return 0;
}
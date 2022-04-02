#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int A[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && A[l] > A[largest])
        largest = l;
 
    if (r < n && A[r] > A[largest])
        largest = r;
 
    if (largest != i) {
        swap(&A[i], &A[largest]);
        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        swap(&A[0], &A[i]);
        heapify(A, i, 0);
    }
}

int main (int argc, char* argv[]){
    //-------------- Entrada -------------------
    // Cantidad de Numeros pasasda como argumentos
    int N = atoi(argv[1]);
    int A[N];

    // Entrada de numeros
    for (int i = 0; i < N; i++)
        scanf("%i", &A[i]);

    //-------------- ALgortimo ----------------
    heapSort(A,N);

    //------------- Imprimir numeros -----------
    for (int i = 0; i < N; i++)
        printf("%i\n", A[i]); 

    return 0;
}
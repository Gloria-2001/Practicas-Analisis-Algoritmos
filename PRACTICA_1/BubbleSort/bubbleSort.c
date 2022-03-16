#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv){
    int *A, n, aux; 
    A = malloc(sizeof(int)*n);
    for(int i=0; i<=n-2; i++){
        for(int j=0; j<=n-2; j++){
            if(A[j]>A[j+1]){
                aux=A[j];
                A[j]=A[j+1];
                A[j+1]=aux;
            }
        }
    }
}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int main(int argc, char **argv){
    int *A, n, aux, i=0; 
    bool cambios=true; 
    A = malloc(sizeof(int)*n);
    while(i<=n-2 && cambios){
        cambios=false; 
        for(int j=0; j<=(n-2)-i; j++){
            if(A[j]<A[j+1]){
                aux=A[j];
                A[j]=A[j+1];
                A[j+1]=aux;
                cambios=true;
            }
        }
    }
}
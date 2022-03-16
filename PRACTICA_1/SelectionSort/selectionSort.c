#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv){
    int *A, n, p, k, temp; 
    A = malloc(sizeof(int)*n);
    for(k=0; k<=n-2;k++){
        p=k;
        for(int i=k+1; i<=n-1; i++){
            if(A[i]<A[p])
                p=i;
        }
        temp=A[p];
        A[p]=A[k];
        A[k]=temp; 
    }
}
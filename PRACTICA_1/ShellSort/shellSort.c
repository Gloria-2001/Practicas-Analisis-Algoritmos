#include<stdio.h>
#include<stdlib.h>
#include<math.h>  
#include<time.h>

int main(int argc, char **argv){
    int *A, n, b, k, temp; 
    A = malloc(sizeof(int)*n);
    k=trunc(n/2);
    while(k>=1){
        b=1;
        while(b!=0){
            b=0;
            for(int i=k; i<=n-1; i++){
                if(A[i-k]>A[i]){
                    temp=A[i];
                    A[i]=A[i-k];
                    A[i-k]=temp;
                    b=b+1; 
                }
            }
        }
        k=trunc(k/2);
    }
}
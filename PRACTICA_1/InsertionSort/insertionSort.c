#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv){
    int *A, n, temp, j, i;
    A = malloc(sizeof(int)*n); 
    for(i=0; i<=n-1;i++){
        j=i;
        temp=A[i];
        while(j>0) && (temp<A[j-1]){
            A[j]=A[j-1];
            j--;
        }
        A[j]=temp;
    }
}
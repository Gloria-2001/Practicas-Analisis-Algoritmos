#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h> 

void intercambiar(int *A, int i, int j){
    int temp;
    A = malloc(sizeof(int)); 
    temp=A[j];
    A[j]=A[i];
    A[i]=temp; 
}

int pivot(int *A, int p, int r){
    A = malloc(sizeof(int)); 
    int piv=A[p], i=p+1, j=r; 
    while(i<j){
        while(A[i]<=piv && i<r){
            i++;
        }
        while(A[j]>piv){
            j--
        }
        intercambiar(A, p, j); 
    }
    return j; 
}

void quickSort(int *A, int p, int r){
    A = malloc(sizeof(int)); 
    if(p<r){
        int j= pivot(A, p, r); 
        quickSort(A,p,j-1);
        quickSort(A,j+1, r); 
    }
}

int main(int argc, char **argv){
    int *mi_A, p, r;
    mi_A = malloc(sizeof(int));
    quickSort(mi_A,p,r);
    return 0; 
}
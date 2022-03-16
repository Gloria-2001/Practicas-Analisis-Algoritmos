#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h> 

void Merge(int *A, int p, int q, int r){
    int l=r-p+1, i=p, j=q+1, *C; 
    A=(int*)malloc(sizeof(int));
    C=(int*)malloc(sizeof(int));

    for(int k=0; k<=l; k++){
        if(i<=q && j<=r){
            if(A[i]<A[j]){
                C[k]=A[i];
                i++;
            }else{
                C[k]=A[j];
                j++
            }
        }else if(i<=q){
            C[k]=A[i];
            i++;
        }else{
            C[k]=A[j];
            j++;
        }
        A[p-r]=C[l];
    }
}

void MergeSort(int *A, int p, int r){
    A = malloc(sizeof(int));
    if(p<r){
        q=trunc((p+r)/2);
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        Merge(A,p,q,r);
    }
}

int main(int argc, char **argv){
    int *mi_A, p, r;
    mi_A = malloc(sizeof(int));
    MergeSort(mi_A, p, r);
    return 0; 
}
//Burbuja Optimizada 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

int main (int argc, char* argv[]){
	int *A = (int*) malloc(sizeof(int)*10000000); 
	int n, i, j, aux=0;
	double utime0, stime0, wtime0,utime1, stime1, wtime1; 
	
	n = atoi(argv[1]); 
	

	for(i = 0; i < n; i++){	
		scanf("%d",&A[i]);
	}	

	if (argc!=2){
		exit(1);
	} 

	else{
		n=atoi(argv[1]);
	}
		
	uswtime(&utime0, &stime0, &wtime0);
	for (i=0;i<=n-2;i++){
		for (j=0;j<=(n-2)-i;j++){
			if (A[j] > A[j+1]){
				aux = A[j];	 
				A[j] = A[j+1];  
				A[j+1] = aux;
			}
		}
	}
	uswtime(&utime1, &stime1, &wtime1);

	
	printf("%d//////////////////////////////////////////////////////////////////////////////////////", n);
	
	//Cálculo del tiempo de ejecucion del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciones de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciones de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	exit (0);
}

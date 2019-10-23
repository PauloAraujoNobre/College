#include <stdio.h>
#include <stdlib.h>
int main(){

	int seed = time(0);
	srand(seed);

    printf("Vetor A:\n");
	int A[5][4]; int B[4][3]; int C[5][3];
	int i = 0; int j = 0; int k = 0; int soma = 0;
	for(i = 0; i < 5; i++){
		for(j = 0; j < 4; j++){
			A[i][j] = (rand() % 10);;
			printf("%d ", A[i][j]);
		}	
		printf("\n");
	}
	printf("\nVetor B:\n");
	for(i = 0; i < 4; i++){
		for(j = 0; j < 3; j++){
			B[i][j] = (rand() % 10);;
			printf("%d ", B[i][j]);
		}	
		printf("\n");
	}
	printf("\n");
	for(i = 0; i < 5; i++){
		for(j = 0; j < 3; j++){
			for(k = 0; k < 4; k++){
				soma += A[i][k] * B[k][j];
			}
			C[i][j] = soma;
			soma = 0;
		}
	}

    printf("Vetor C:\n");
	for(i = 0; i < 5; i++){
		for(j = 0; j < 3; j++){
			printf("%d ", C[i][j]);
		}	
		printf("\n");
	}
	return 0;
}

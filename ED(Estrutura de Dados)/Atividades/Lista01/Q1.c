#include <stdio.h>
int main(){
	int seed = time(0);
	srand(seed);

	int A[25] = {0}; int B[25] = {0}; int C[50] = {0};
	int i = 0; int j = 0;  
	
	for(i = 0; i < 25; i++){
		A[i] = (rand() % 100);
	}

	for(i = 0; i < 25; i++){
		B[i] = (rand() % 100);
	}

	for(i = 0, j = 0; i < 50; i = i + 2, j++){
		C[i] = A[j];
		C[i + 1] = B[j];
	}

	int numero = 0; char letra; int flag = 0;
	printf("Qual numero deseja encontrar?\n");
	scanf("%d", &numero);
	i = 0;
	while(1){
		if(C[i] == numero){
			printf("Numero %d encontrado no indice %d do vetor\n", numero, i);
			break;
		}
		if(i == 49){
			printf("Numero nao encontrado no vetor\n");
			break;
		}
		i++;
	}
	printf("Vetor:\n");
	for(i = 0; i < 50; i++){
		printf("%d ", C[i]);
	}
	return 0;
}	







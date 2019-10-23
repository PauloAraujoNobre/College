#include <stdio.h>
int main(){
	int seed = time(0);
	srand(seed);

	int vetor[30] = {0};
	int i = 0; int j = 0; int aux = 0; 
	
	for(i = 0; i < 30; i++){
		vetor[i] = (rand() % 100);
		if(i%2 == 0){
			vetor[i] *= 2;
		}

		if(i%2 == 1){
			vetor[i] *= 5;
		}
	}

	for(i = 0; i < 30; i++){
		for(j = i + 1; j < 30; j++){
			if(vetor[i] > vetor[j]){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}

	int numero = 0;
	printf("Qual numero deseja encontrar?\n");
	scanf("%d", &numero);
	int menor = 0; int maior = 29; int meio;
	while(1){
		meio = (maior + menor)/2;
		if(vetor[meio] == numero){
			printf("Numero %d encontado no indice %d\n", numero, meio);
			break;
		}else if(numero < vetor[meio]){
			maior = meio - 1;
		}else if(numero > vetor[meio]){
			menor = meio + 1;
		}
		if(maior < menor){
		    printf("Numero nao encontrado\n");
		    break;
		}
	}
	printf("Vetor:\n");
	for(i = 0; i < 30; i++){
		printf("%d ", vetor[i]);
	}
	return 0;
}	

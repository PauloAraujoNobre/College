#include <stdio.h>

long long int vetor[70] = {0, 1};
int countVetor = 2;

void Fib(int indice){
	int i = 0;
	for(i = countVetor; i <= indice; i++){
		vetor[i] = vetor[i - 1] + vetor[i - 2];
		countVetor++;
	}
}

int main(){
	int nCasos = 0; int indice = 0;
	scanf("%d", &nCasos);
	int i = 0;
	for(i = 0; i < nCasos; i++){
		scanf("%d", &indice);
		if(indice >= countVetor){
			Fib(indice);
		}
		printf("Fib(%d) = %lld\n", indice, vetor[indice]);
	}
	return 0;
}

#include <stdio.h>
int main(){
	int nCasos = 0; int numero = 0; int menor = NULL; int i = 0;
	int vetor[1050] = {0};
	scanf("%d", &nCasos);
	for(i = 0; i < nCasos; i++){
		scanf("%d", &numero);
		vetor[i] = numero;
		if(numero < menor){
			menor = numero;
		}
	}
	i = 0;
	while(vetor[i] != menor){
		i++;
	}
	printf("Menor valor: %d\n", menor);
	printf("Posicao: %d\n", i);
	return 0;
}	

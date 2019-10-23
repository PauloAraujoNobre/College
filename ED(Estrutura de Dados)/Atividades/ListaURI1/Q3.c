#include <stdio.h>
int main(){
	int vetor[105][105] = {0};
	int indice = 0;
	scanf("%d", &indice);
	while(1){
		int i = 0; int j = 0;
		for(j = 0; j < indice; j++){
			for(i = 0; i < indice - j; i++){
				vetor[i+j][i] = 1 + j;
				vetor[i][i+j] = 1 + j;
			}
		}
		for(i = 0; i < indice; i++){
			for(j = 0; j < indice; j++){
				printf("%3d", vetor[i][j]);
				if(j < indice - 1){
					printf(" ");
				}
			}
			printf("\n");
		}
		scanf("%d", &indice);
		if (indice == 0){
			break;
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}

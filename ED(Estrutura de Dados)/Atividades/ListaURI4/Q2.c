#include <stdio.h> //1211 - Lista Telefônica Econômica
#include <string.h>

char numeros[100005][200] = {0};

int main(){
	int X;
	int i, j, k, l;
	char aux[200] = {0};

	while(scanf("%d", &X) != EOF){
		int count = 0;
		for(i = 0; i < X; i++){
			scanf("%s", numeros[i]);
		}

		for(k = 0; k < X - 1; k++){
			for(l = k+1; l < X; l++){
				if(strcmp(numeros[k], numeros[l]) < 0){
					strcpy(aux, numeros[k]);
					strcpy(numeros[k], numeros[l]);
					strcpy(numeros[l], aux);
				}	
			}
		}

		for(i = 0; i < X-1; i++){
			for(j = 0; j < strlen(numeros[i]); j++){
				if(numeros[i][j] == numeros[i+1][j]){
					count++;
				}else{
					break;
				}
			}
		}
		printf("%d\n", count);
	}

	
	return 0;
}



#include <stdio.h> //1062 - Trilhos
int main(){
	int zero = 1;

	int N;
	while(scanf("%d", &N) && N){
		while(N != 0){
			int i, j, k, Naux, flag = 0, flag2 = 0;
			int entrada[1005] = {0};
			int pilha[1005] = {0};
			int saida[1005] = {0};
			
			for(i = N-1; i >= 0; i--){
				scanf("%d", &entrada[i]);
				if(entrada[i] == 0){
					flag2 = 1;
					N = 0;
					printf("\n");
					break;
				}
			}
			if(flag2 == 1){
				flag2 = 0;
				break;
			}else{
				Naux = N;
				for(i = 0, j = 0, k = 0; j < N && i < N+1;){
					if(entrada[i] == Naux){
						saida[j] = entrada[i];
						j++;
						i++;
						Naux--;
					}else if(pilha[k-1] == Naux && i > 0){
						saida[j] = pilha[k-1];
						pilha[k] = 0;
						j++;
						k--;
						Naux--;
					}else{
						pilha[k] = entrada[i];
						k++;
						i++;
					}
				}
				Naux = N;
				for(i = Naux, j = 0; i > 0; i--, j++){
					if(saida[j] != i){
						flag = 1;
					}
				}
				if(flag == 0){
					printf("Yes\n");
				}else{
					printf("No\n");
				}
			}
		}
	}


	return 0;
}

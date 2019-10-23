#include <stdio.h> //1069 - Diamantes e Areia
#include <string.h>
int main(){
	int N;
	scanf("%d", &N);
	
	char c[1005];
	while(N--){
		char pilha[1005] = {0};
		int countA = 0, countB = 0, i = 0, k = 0;
		scanf("%s", c);

		for(i = 0, k = 0; i < strlen(c); i++){
			if(c[i] == '<' || c[i] == '>'){
				pilha[k] = c[i];
				k++; 
			}
		}

		for(i = 0; i < strlen(c); i++){
			if(pilha[i] == '<'){
				countA++;
			}else if(pilha[i] == '>' && countA > countB){
				countB++;
			}
		}


		printf("%d\n", countB);

		
	
	}

	return 0;
}

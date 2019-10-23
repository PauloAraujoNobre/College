#include <stdio.h> //1068 - Balanço de Parênteses I
#include <string.h>
int main(){
	char c[10005] = {0};
	while(scanf("%s", c) != EOF){
		char pilha[10005] = {0};

		int countA = 0, countB = 0, i = 0, k = 0, erro = 0;

		for(i = 0, k = 0; i < strlen(c); i++){
			if(c[i] == '(' || c[i] == ')'){
				pilha[k] = c[i];
				k++;
			}
		}

		for(i = 0; i < strlen(pilha); i++){
			if(pilha[i] == '('){
				countA++;
			}else if(pilha[i] == ')' && countA > countB){
				countB++;
			}else{
				erro = 1;
			}
		}

		if(countA == countB && erro == 0 && k != 0){
			printf("correct\n");
		}else{
			printf("incorrect\n");
		}
	
	}

	return 0;
}

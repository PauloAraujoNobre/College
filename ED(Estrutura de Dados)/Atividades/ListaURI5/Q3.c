#include <stdio.h>

int flag = 0;

int  pula (int M, int N, int pos_atual, int pulo_i){
	int pos_aux;
	if(pos_atual == M){
		flag = 1;
	    return 0;	
	}
    
    pos_aux = pos_atual + ((pulo_i * 2) - 1);
    if(pos_aux <= N){
        pos_atual = pos_aux;
		pulo_i++;
		pula(M, N, pos_atual, pulo_i);
		if(flag == 1){
    	    return 0;	
    	}
	}    
    
    pos_aux = pos_atual - ((pulo_i * 2) - 1);
	if(pos_aux > 0){
		pos_atual = pos_aux;
		pulo_i++;
		pula(M, N, pos_atual, pulo_i);
	    if(flag == 1){
    	    return 0;	
    	}
	}
    return 0;
}

int main(){
	int N, M;
	while(1){
		scanf("%d %d", &N, &M);
		if(N == 0 && M == 0){
			return 0;
		}
		int pos_atual = 1;
		int pulo_i = 2;
		pula(M, N, pos_atual, pulo_i);

		if(flag == 0){
			printf("Don't make fun of me!\n");
		}else{
			printf("Let me try!\n");
		}
		flag = 0;
	}
}

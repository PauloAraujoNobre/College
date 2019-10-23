#include <stdio.h>
int main(){
	int N = 0; int i = 0; int j = 0;
	while(scanf("%d", &N) != EOF){
		for(i = 0; i < N; i++){
			for (j = 0; j < N; j++){
				if(i + j == N - 1){
					printf("2");
				}else if(i - j == 0){
					printf("1");
				}else{
					printf("3");
				}
			}
			printf("\n");
		}
	}
	return 0;
}

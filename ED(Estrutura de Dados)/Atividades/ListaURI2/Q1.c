#include<stdio.h>
int main(){
    int i, j, N, aux;
    while(1){
        scanf("%d", &N);
        if(N == 0){
            break;
        }
        for(i = 1; i <= N; i++){
            for(j = 1; j <= N; j++){
                aux = i;
                if(j < i){
                    aux = j;
                }
                
                if(N - i + 1 < aux){
                    aux = N - i + 1;
                }
                
                if(N - j + 1 < aux){
                    aux = N - j + 1;
                }
                
                printf("%3d", aux);
                if(j < N){
                    printf(" ");
                }else{
                  printf("\n");  
                }             
                
            }
        }
        printf("\n");
    }
    return 0;
}

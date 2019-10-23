#include <stdio.h> //1548 - Fila do Recreio
int main(){ 
    int N, M, P[1005] = {0}, Q[1005] = {0};
    scanf("%d", &N);
    while(N--){
        scanf("%d", &M);

        int i;
        for(i = 0; i < M; i++){
           scanf("%d", &P[i]);
           Q[i] = P[i];
        }
        
        int j, aux;
        for(i = 0; i < M-1; i++){
            for(j = i+1; j < M; j++){
                if(Q[j] > Q[i]){
                    aux = Q[j];
                    Q[j] = Q[i];
                    Q[i] = aux;
                }
            }   
        }
        
        int count = 0;
        for(i = 0; i < M; i++){
            if(P[i] == Q[i]){
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}

#include <stdio.h> //1025 - Onde está o Mármore?
int main(){
    int N, Q, count = 1;
    while(1){
        int A[100005] = {0}, B[100005] = {0};
        scanf("%d %d", &N, &Q);
        if(N == 0 && Q == 0){
            break;
        }
        int i, j = 0, tamB = 0;
        for(i = 0; i < N; i++){
            scanf("%d", &A[i]);
        }
        for(i = 0; i < Q; i++){
            scanf("%d", &B[i]);
            tamB++;
        }
        printf("CASE# %d:\n", count);
        count++;
        
        while(tamB > 0){
            int flag = 0;
            for(i = 0; i < N; i++){
                if(B[j] == A[i]){
                    printf("%d found at %d", B[j], i+1);
                    j++;
                    tamB--;
                    flag = 1;
                    break;
                }
            }
            if(flag = 0){
                printf("%d not found", B[j]);
                j++;
                tamB--;
            }
        }
        
    }
    return 0;
}

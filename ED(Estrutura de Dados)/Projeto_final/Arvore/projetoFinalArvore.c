#include <stdio.h>
#include <stdlib.h>
#include "lib.h" 

//variaveis globais

node vetor_possi[10000000];
int tam_pos = 0;
int ultimo_visitado = 0;
int count_bfs = 0;

int main(int argc, char const *argv[]){

    //int nodo_inicial[9] = {1, 2, 0, 3, 4, 5, 6, 7, 8}; //Estado p exemplo
    //int nodo_inicial[9] = {1, 2, 3, 4, 0, 5, 6, 7, 8};
    //int nodo_inicial[9] = {1, 2, 3, 4, 5, 6, 0, 7, 8};
    int nodo_inicial[9] = {8, 7, 6, 5, 4, 3, 2, 1, 0};
    node nodoP = iniciaEstados(nodo_inicial);

    while(1){
    
        if (count_bfs != 0){
            nodoP = vetor_possi[ultimo_visitado++];
            nodoP = generateTree(nodoP);
        }
        
        if (checkTarget(nodoP.estado)){
            printf("--------\n");
            for (int i = 0; i < 9; i++) {
                printf("%2d ", nodoP.estado[i]);
                if(i % 3 == 2){
                    printf("\n");
                }
            }
            printf("\nQuantidade de instâncias: %d\n", count_bfs);
            exit(0);
        }
        
        count_bfs++;

        int aux_pos =  nodoP.qnt_possi;

        for (int j = 0; j < aux_pos; j++){
            vetor_possi[tam_pos++] = nodoP.filhos[j];
        }
    }   

    return 0;
}

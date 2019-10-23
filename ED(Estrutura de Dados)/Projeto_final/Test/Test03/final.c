#include <stdio.h>
#include <stdlib.h>
#include "final.h" 

//-------------GLOBAIS-----------//
int COUNT_DFS = 0;
int aux1 = 1;
node vetor_possi[10000000];
int tam_pos = 0;
int ultimo_visitado = 0;
//-------------------------------//




int main(int argc, char const *argv[]) {
    node nodoP = cria_node_zerado();

    while(1){
        if (COUNT_DFS != 0){
            nodoP = vetor_possi[ultimo_visitado++];   
            nodoP = cria_possibilidades(nodoP);
        } 
     //   printf("tam_pos = %d\n",tam_pos );
        if (checar_acerto(nodoP.estado)){
          //  printf("\n");
            for (int i = 0; i < 9; i++) {
                printf("%d ", nodoP.estado[i]);
            }

          //  printf("\nCAMINHO ENCONTRADO\n");
            exit(0);

        }
        
        COUNT_DFS++;

        int aux_pos =  nodoP.qnt_possi;
       // printf("aux_pos = %d\n",aux_pos );
        for (int j = 0; j < aux_pos; j++){
           //if(heuristica(nodoP) < 9){
                vetor_possi[tam_pos]= nodoP.possibilidades[j];
                tam_pos++;
            //}
        }
    }   


    return 0;
}

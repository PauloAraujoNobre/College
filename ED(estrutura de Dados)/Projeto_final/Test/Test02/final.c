#include <stdio.h>
#include <stdlib.h>
#include "final.h" 

//-------------GLOBAIS-----------//
int COUNT_DFS = 0;
int aux1 = 1;
int qnt_acertados = 1;
//-------------------------------//


int dfs(node nodoP) {

    printf("\n\nDFS N° %d\n",COUNT_DFS+1);
   
    if (checar_acerto(nodoP.estado)){
		printf("\n");
    	for (int i = 0; i < 9; i++) {
            printf("%d ", nodoP.estado[i]);
        }

        printf("\nCAMINHO ENCONTRADO\n");
        exit(0);

    }
    if (COUNT_DFS != 0){
        nodoP = cria_possibilidades(nodoP);
    }
    COUNT_DFS++;
    while (nodoP.visitado < nodoP.qnt_possi) {
        COUNT_DFS++;

        if (nodoP.qnt_possi == 0) {
            printf("Saiu %d\n", aux1++);
            return 0;
        }
        dfs(nodoP.possibilidades[++nodoP.visitado]);

    }

    printf("Saiu %d\n", aux1++);
    return 0;
}



int main(int argc, char const *argv[]) {
    node raiz = cria_node_zerado();
    dfs(raiz);


    return 0;
}

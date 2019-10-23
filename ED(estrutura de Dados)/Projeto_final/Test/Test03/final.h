int VISITADOS[10000000][9] = {0};
int aux_visitados = 0;

typedef struct node {
    struct node *pai;
    struct node *possibilidades;
    int estado[9];
    int qnt_possi;
} node;

node cria_possibilidades(node nodoa);


node cria_node_zerado() {
    node a;
    
    int aux[9] = {8,7,6,5,4,3,2,1,0};
    for (int i = 0; i < 9; i++){
        a.estado[i] = aux[i];     
    }
    //[8, 7, 6,
    // 5, 4, 3,   
    // 2, 1, 0]
    //a.estado[0] = 0
    a = cria_possibilidades(a);
    return a;
}


int heuristica_dist (node nodo){
    int passos[9] = {0};
    int count = 0;
    for(int i = 0; i < 9; i++){
        passos[i] = abs((nodo.estado[i]%3 - i%3)) + abs((nodo.estado[i]/3 - i/3));
        count += passos[i];
    }
    //printf("%d\n",count );
    return count;
}

int heuristica_erro(node nodo){
    int count = 0;
    for (int i = 0; i < 9; i++){
        if(nodo.estado[i] != i)
            count++;
    }
    printf("%d\n", count);
    return count;
}

int checar_visitado(int estado[9]) {
    int flag = 0;
    for (int i = 0; i < aux_visitados; i++) {
        int flag_interna = 1;
        for (int j = 0; j < 9; j++) {
            if (VISITADOS[i][j] != estado[j]) {
                flag_interna = 0;
                break;
            }
        }
        if (flag_interna) {
            flag = 1;
            break;
        }
    }

    return flag;
}

int checar_acerto(int *estado) {
    int qnt_rainhas = 0;
    for (int i = 0; i < 9; i++) {
        if(estado[i] != i){
            return 0;
        }
    }
    return 1;
}

node cria_possibilidades(node nodoa) {
    printf("--------\n");
        for (int i = 0; i < 9; i++) {
            printf("%2d ", nodoa.estado[i]);
            if(i%3 == 2 && i != 8){
                printf("\n");
            }
        }

    printf("\n");
    printf("--------\n");
    heuristica_erro(nodoa);
   
  
    int k;
    for ( k = 0; k < 9; k++){
        if (nodoa.estado[k] == 0){
            break;
        }
    }
    int vetor_pos[4][9] = {0};
    int vetor_aux[4][9] = {0};
    int estado_aux[9] = {0};
    int estado_aux2[9] = {0};





    for (int i = 0; i < 9; i++){
        estado_aux[i] = nodoa.estado[i];   
        estado_aux2[i] = estado_aux[i];
    }


    int i = 0,aux = 0, aux2 = 0;
    if (k > 2){
        i = k;
        for (int l = 0; l < 9; l++){
            estado_aux[l] = estado_aux2[l];
        }
        //TOP
        aux = estado_aux[i];
        estado_aux[i] = estado_aux[i-3];
        estado_aux[i-3] = aux;
        for (i = 0; i < 9; i++){
            vetor_aux[aux2][i] = estado_aux[i];
        }
        aux2++;
    }

    if (k < 6){
        i = k;
        for (int l = 0; l < 9; l++){
            estado_aux[l] = estado_aux2[l];
        }
        //BOT
        aux = estado_aux[i];
        estado_aux[i] = estado_aux[i+3];
        estado_aux[i+3] = aux;
        for (i = 0; i < 9; i++){
            vetor_aux[aux2][i] = estado_aux[i];
        }
        aux2++;       
    }
    if (k != 0 && (k != 3 || k != 6)){
        i =k;
        for (int l = 0; l < 9; l++){
            estado_aux[l] = estado_aux2[l];
        }

        //LEF
        
        aux = estado_aux[i];
        estado_aux[i] = estado_aux[i-1];
        estado_aux[i-1] = aux;
        for (i = 0; i < 9; i++){
            vetor_aux[aux2][i] = estado_aux[i];
        }
        aux2++;  
    }
    if (k != 2 && k != 5 && k != 8){
        i= k;

        //RGT
        for (int l = 0; l < 9; l++){
            estado_aux[l] = estado_aux2[l];
        }
        estado_aux[i] = estado_aux[i+1];
        estado_aux[i+1] = aux;
        for (i = 0; i < 9; i++){
            vetor_aux[aux2][i] = estado_aux[i];
        }
        aux2++;  
    }



    int j = 0;

    
    int tam_aux = 0;
    

    for (int i = 0; i < aux2; i++){
        if (!checar_visitado(vetor_aux[i])){
            for (int l = 0; l < 9; l++){
             //   printf("%d", vetor_aux[i][l]);
                vetor_pos[tam_aux][l] = vetor_aux[i][l];
                VISITADOS[aux_visitados][l] = vetor_aux[i][l];
            }
       //     printf("\n");
            aux_visitados++;
            tam_aux++;
        }
    }

   
    nodoa.qnt_possi = tam_aux;
   //   printf("Quantidade de possibilidades = %d\n", tam_aux);
    node *vetor_alocado = (node *) malloc((tam_aux+2) * sizeof(node));

    for (int i = 0; i < tam_aux; i++) {

        node b;
        for (int j = 0; j < 9; j++) {
            b.estado[j] = vetor_pos[i][j];
        }
        b.pai = &nodoa;
        b.qnt_possi = 0;

        vetor_alocado[i] = b;
    }

    nodoa.possibilidades = vetor_alocado;
    free(vetor_alocado);
    return nodoa;

}

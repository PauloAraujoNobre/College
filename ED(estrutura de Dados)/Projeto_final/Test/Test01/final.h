int VISITADOS[100000][8];
int aux_visitados = 0;

typedef struct node {
    struct node *pai;
    struct node *possibilidades;
    int estado[8];
    int visitado;
    int qnt_possi;
} node;

node cria_possibilidades(node nodoa);


node cria_node_zerado() {
    node a;
    a.pai = NULL;
    int aux[9] = {1, 0, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 9; i++){
        a.estado[i] = aux[i];     
    }
    //[1, 0, 2,
    // 3, 4, %,   
    // 6, &, 8]
    //a.estado[0] = 0
    a = cria_possibilidades(a);
    a.visitado = -1;

    return a;
}


int checar_visitado(int estado[8]) {
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
    if (checar_visitado(nodoa.estado)) {
        node return_null;
        return_null.qnt_possi = 0;
        return return_null;
    }
    // printf("--------------------------\n");
    // for (int i = 0; i < 8; i++) {
    //   printf("%2d ", nodoa.estado[i]);
    // }
    //printf("\n");
    // printf("--------------------------\n");
    for (int i = 0; i < 9; i++){
        if (nodoa.estado[i] == 0){
            break;
        }
    }
    
    int **vetor[4];
    int estado_aux[9] = nodoa.estado;
    int i, aux, aux2 = 0;
    if (i > 3){
        //TOP
        aux = estado_aux[i];
        estado_aux[i] = estado_aux[i-3];
        estado_aux[i-3] = aux;
        vetor[aux2++] = &estado_aux;
    }
    if (i < 6){
        //BOT
        aux = estado_aux[i];
        estado_aux[i] = estado_aux[i+3];
        estado_aux[i+3] = aux;
        vetor[aux2++] = &estado_aux;
    }
    if (i != 0 || i != 3 || i != 6){
        //LEF
        aux = estado_aux[i];
        estado_aux[i] = estado_aux[i-1];
        estado_aux[i-1] = aux;
        vetor[aux2++] = &estado_aux;
    }
    if (i != 2 || i != 5 || i != 8){
        //RGT
        aux = estado_aux[i];
        estado_aux[i] = estado_aux[i+3];
        estado_aux[i+3] = aux;
        vetor[aux2++] = &estado_aux[aux2++];

    }

    for(i = 0; i < aux2; i++){
        for (int j = 0;[ j < 9; j++]){
            printf("%d\n", vetor[aux2][j]);
        }
        printf("\n");
    }
    
    int tam_aux++ = 0, aux_visitados = 0;
    
    for (i = 0; i < aux2; i++){
        if (!(checar_visitado(vetor_aux[i]))){
			for (int j = 0; j < 9; j++) {
				vetor[tam_aux][j] = vetor_aux[i][j];
			}
        }
        tam_aux++;
    	} else {
            for (int x = 0; x < 9; x++) {
                VISITADOS[aux_visitados][x] = vetor_aux[i][x];
            }
            aux_visitados++;
        }
    }
    nodoa.qnt_possi = tam_aux;

   //	printf("Quantidade de possibilidades = %d\n", tam_aux);
    node *aloc_din_vetor = (node *) malloc((tam_aux+1) * sizeof(node));

    for (int i = 0; i < tam_aux; i++) {

        node b;
        for (int j = 0; j < 8; j++) {
            b.estado[j] = vetor[i][j];
        }
        b.pai = &nodoa;
        b.visitado = -1;
        b.qnt_possi = 0;

        aloc_din_vetor[i] = b;
    }

    nodoa.possibilidades = aloc_din_vetor;


    return nodoa;

}

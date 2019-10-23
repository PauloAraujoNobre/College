int VISITADOS[100000][9] = {{1, 0, 2, 3, 4, 5, 6, 7, 8}};
int aux_visitados = 0;

typedef struct node {
    struct node *pai;
    struct node *possibilidades;
    int estado[9];
    int visitado;
    int qnt_possi;
} node;

node cria_possibilidades(node nodoa);


node cria_node_zerado() {
    node a;
    
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
    if (checar_visitado(nodoa.estado)) {
        printf("VISITADO\n" );
        node return_null;
        return_null.qnt_possi = 0;
        return return_null;
    }
    printf("--------------------------\n");
     for (int i = 0; i < 9; i++) {
       printf("%2d ", nodoa.estado[i]);
    }
    printf("\n");
     printf("--------------------------\n");
    for (int i = 0; i < 9; i++){
        if (nodoa.estado[i] == 0){
            break;
        }
    }
    int vetor_pos[4][9] = {0};
    int vetor_aux[4][9] = {0};
    int estado_aux[9];





    for (int i = 0; i < 9; i++){
        estado_aux[i] = nodoa.estado[i];   
        printf("%d", estado_aux[i]);
    }

    printf("AAAA\n");

    int i, aux = 0, aux2 = 0;
    if (i > 3){
        //TOP
        printf("EEEE\n");
        aux = estado_aux[i];
        estado_aux[i] = estado_aux[i-3];
        estado_aux[i-3] = aux;
        for (i = 0; i < 9; i++){
            vetor_aux[aux2][i] = estado_aux[i];
        }
        aux2++;
    }
    if (i < 6){
        //BOT
        aux = estado_aux[i];
        estado_aux[i] = estado_aux[i+3];
        estado_aux[i+3] = aux;
        for (i = 0; i < 9; i++){
            vetor_aux[aux2][i] = estado_aux[i];
        }
        aux2++;       
    }
    if (i != 0 || i != 3 || i != 6){
        //LEF
        aux = estado_aux[i];
        estado_aux[i] = estado_aux[i-1];
        estado_aux[i-1] = aux;
        for (i = 0; i < 9; i++){
            vetor_aux[aux2][i] = estado_aux[i];
        }
        aux2++;  
    }
    if (i != 2 || i != 5 || i != 8){
        //RGT
        aux = estado_aux[i];
        estado_aux[i] = estado_aux[i+3];
        estado_aux[i+3] = aux;
        for (i = 0; i < 9; i++){
            vetor_aux[aux2][i] = estado_aux[i];
        }
        aux2++;  
    }



    printf("BBBBB\n");
    int j = 0;
    for(i = 0; i < aux2; i++){
        for (j = 0; j < 9; j++){
            printf("%d\n", vetor_aux[aux2][j]);
        }
        printf("\n");
    }
    
    int tam_aux = 0, aux_visitados = 0;
    
    printf("CCCCCCCCCCCC\n");
    for (i = 0; i < aux2; i++){
        if (!(checar_visitado(vetor_aux[i]))){
			for (int j = 0; j < 9; j++) {
				vetor_pos[tam_aux][j] = vetor_aux[i][j];
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
    printf("DDDDDDDDddd\n");

   //	printf("Quantidade de possibilidades = %d\n", tam_aux);
    node *aloc_din_vetor = (node *) malloc((tam_aux+1) * sizeof(node));

    for (int i = 0; i < tam_aux; i++) {

        node b;
        for (int j = 0; j < 9; j++) {
            b.estado[j] = vetor_pos[i][j];
        }
        b.pai = &nodoa;
        b.visitado = -1;
        b.qnt_possi = 0;

        aloc_din_vetor[i] = b;
    }

    nodoa.possibilidades = aloc_din_vetor;
    printf("%d\n", aux2);

    for (int i = 0; i < aux2; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            //printf("%d",nodoa.possibilidades[i].estado[j]);
        }
        printf("\n");
    }
    return nodoa;

}

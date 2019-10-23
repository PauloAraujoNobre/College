int arrVisitados[10000000][9] = {0};
int visited = 0;

typedef struct node {
    struct node *pai;
    struct node *filhos;
    int estado[9];
    int qnt_possi;
} node;

node generateTree(node nodoa);


node iniciaEstados(int nodo_inicial[9]){

    node a;
    int aux[9];	
    for(int i = 0; i < 9; i++){
        aux[i] = nodo_inicial[i];
    }
    
    for (int i = 0; i < 9; i++){
        a.estado[i] = aux[i];  
        arrVisitados[visited][i] = aux[i];  
    }
 	visited++;
	
    a = generateTree(a);
    return a;
}

/*
int heuristica_dist (node nodo){
    int passos[9] = {0};
    int count = 0;
    for(int i = 0; i < 9; i++){
        passos[i] = abs((nodo.estado[i] % 3 - i % 3)) + abs((nodo.estado[i]/3 - i/3));
        count += passos[i];
    }
    //printf("%d\n",count );
    return count;
}
*/

/*
int heuristica_erro(node nodo){
    int count = 0;
    
    for (int i = 0; i < 9; i++){
        if(nodo.estado[i] != i)
            count++;
    }
    //printf("%d\n", count);
    return count;
}
*/

//Checa as posicoes ja visitadas para evitar que visite esses estados novamente
int checkVisited(int estado[9]) {

    int flag = 0;
    
    for (int i = 0; i < visited; i++) {
        int flag2 = 1;
        
        for (int j = 0; j < 9; j++) {
            if (arrVisitados[i][j] != estado[j]) {
                flag2 = 0;
                break;
            }
        }
        
        if(flag2){
            flag = 1;
            break;
        }
    }
    return flag;
}

//Se o estado atual for igual ao target, pula para prox posicao
int checkTarget(int *estado) {

    for (int i = 0; i < 9; i++) {
        if(estado[i] != i)
        	return 0;
    }
    return 1;
}

node generateTree(node nodoa) {

    printf("--------\n");
        for (int i = 0; i < 9; i++) {
            printf("%2d ", nodoa.estado[i]);
            if(i % 3 == 2 && i != 8){
                printf("\n");
            }
        }

    printf("\n");
    printf("--------\n");
	
  
    int k;
    
    for (k = 0; k < 9; k++){
        if (nodoa.estado[k] == 0)
            break;
    }
    
    int vetor_pos[4][9] = {0};
    int vetor_aux[4][9] = {0};
    int estado_aux[9] = {0};
    int estado_aux2[9] = {0};

    //faz o backup dos nodos atuais, para em caso de erro ele ainda possui os estados anteriores
    for(int i = 0; i < 9; i++){
        estado_aux[i] = nodoa.estado[i];   
        estado_aux2[i] = nodoa.estado[i];
    }

    int i = 0, aux = 0, aux2 = 0;
    
    //condicao de troca de uma posicao de cima (so pode acontecer se for maior que 2)
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
    
    //condicao de troca de uma posicao de baixo (so pode acontecer se for maior que 6)
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

        //LEFT
        
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

        //RIGHT
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
        if (!checkVisited(vetor_aux[i])){
            for (int l = 0; l < 9; l++){
             //   printf("%d", vetor_aux[i][l]);
                vetor_pos[tam_aux][l] = vetor_aux[i][l];
                arrVisitados[visited][l] = vetor_aux[i][l];
            }
       //     printf("\n");
            visited++;
            tam_aux++;
        }
    }

    nodoa.qnt_possi = tam_aux;
   //   printf("Quantidade de filhos = %d\n", tam_aux);
    node *arrAlocado = (node *) malloc((tam_aux+2) * sizeof(node));

    for (int i = 0; i < tam_aux; i++) {

        node b;
        for (int j = 0; j < 9; j++) {
            b.estado[j] = vetor_pos[i][j];
        }
        b.pai = &nodoa;
        b.qnt_possi = 0;

        arrAlocado[i] = b;
    }

    nodoa.filhos = arrAlocado;
    free(arrAlocado);
    
    return nodoa;
}

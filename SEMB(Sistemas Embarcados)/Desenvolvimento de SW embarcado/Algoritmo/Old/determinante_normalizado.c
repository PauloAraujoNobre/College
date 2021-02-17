#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define max 10

/*
* 09/12/20
* @(#) DeterminanteNormalizado.c
* 
* Copyright 2020 by Yves Augusto e Paulo Henrique, todos os direitos reservados
* Instituto Federal de Ciência, Tecnologia e Educação do Ceará
*
* Este código foi desenvolvido para um trabalho da disciplina de
* Sistemas Embarcados. É de livre cópia e utilização.
*
* A equipe não é responsável por danos causados em virtude da utilização deste código
*
*/

/********************************************
*
*
* Este código implementa o cálculo do determinante normalizado, que consiste
* na divisão do determinante de uma matriz pela raiz quadrada do produto das
* normas das linhas dessa matriz. O cálculo é feito para saber se um determi
* nado sistema é bem condicionado ou mal condicionado. De acordo com o resul
* tado entregue por esta implementação, será possível medir quão bem ou mal
* condicional é o sistema.
*
* Entrada
* 	- Dimensões da matriz, com um limite de 25 x 25
*	- Matriz, a ser coletada por meio de digitação do usuário, elemento a elemento, por meio do scanf,
*     ou então através de geração aleatória(utilizado para testes).
* Saida
*	- Um valor entre 0 e 1.
*
* Conforme o valor tender a 1, considera-se que o sistema é bem condicionado.
* Caso contrário, e o resultado computado tenda a zero, o sistem será mal condi
* cionado.
*
*
*********************************************/

int check_if_condinioned(int n, double matriz[][n]) {

    // // -----------------------------------------------------------------------------
    //
    // Função check_if_condinioned
    // Argumentos:
    // 	- matrix[n][n]: matriz de floats, sobre a qual vai ser calculado o determinante normalizado.
    //	- n: a ordem da matriz.
    // Retorna:
    // 	- É retornado o valor de um inteiro que representa uma condição de indeterminação na matriz.
    //
    // // -----------------------------------------------------------------------------

	int i, j;
    int nullLine = 0, flag = 0;
    // É criado um somador para a linha e uma flag de ativação.
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
    		if(matriz[i][j] == 0) {
    			nullLine++;
                // É somado +1 sempre que algum indice da linha for 0.
			}
        }
        if(nullLine == n) {
        // Caso nullLine seja igual a n, isso justifica que todos os elementos dessa linha são compostos por 0.
        	flag = 1;
            // A flag é ativada para indicar que existe uma condição de indeterminação.
		}
		nullLine = 0;
        // O somador é zerado para verificar a proxima linha.
    }
    return flag;
}

void biuld_matriz(int n, double matriz[n][n]) {

    // // -----------------------------------------------------------------------------
    //
    // Função biuld_matriz
    // Argumentos:
    // 	- matrix[n][n]: matriz de floats, sobre a qual vai ser calculado o determinante normalizado.
    //	- n: a ordem da matriz.
    // Retorna:
    // 	- void.
    //
    // // -----------------------------------------------------------------------------

	srand( (unsigned)time(NULL) );
    // É setado o srand para gerar valores aleatorios. 

	int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
        // Os valores da matriz são atribuidos.
        	//matriz[i][j] = rand() % 10;									//Inteiro randomico
        	//matriz[i][j] = (((float)rand()/(float)(RAND_MAX)) * max);		//Float randomico
        	scanf("%lf", &matriz[i][j]);									//Entrada do teclado
        }
    }
}

void biuld_random_matriz(int n, double matriz[][n]) {

    // // -----------------------------------------------------------------------------
    //
    // Função biuld_matriz
    // Argumentos:
    // 	- matrix[n][n]: matriz de floats, sobre a qual vai ser calculado o determinante normalizado.
    //	- n: a ordem da matriz.
    // Retorna:
    // 	- void.
    //
    // // -----------------------------------------------------------------------------

	srand( (unsigned)time(NULL) );
    // É setado o srand para gerar valores aleatorios. 

	int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
        // Os valores da matriz são atribuidos.
        	//matriz[i][j] = rand() % 10;									//Inteiro randomico
        	matriz[i][j] = (((float)rand()/(float)(RAND_MAX)) * max);		//Float randomico
        	//scanf("%lf", &matriz[i][j]);									//Entrada do teclado
        }
    }
}

void troca_linha(int n, double matriz[][n], int i, int j) {

    // // -----------------------------------------------------------------------------
    //
    // Função troca_linha
    // Argumentos:
    // 	- matrix[n][n]: matriz de floats, sobre a qual vai ser calculado o determinante normalizado.
    // 	- i: indice da linha do pivotante representada na matriz[n][n].
    //	- j: indice da linha na matriz[n][n] a ser trocada com a linha do pivotante.
    // Retorna:
    // 	- void.
    //
    // // -----------------------------------------------------------------------------

	double aux;
	int k;
	for(k = 0; k < n; k++) {
        // inicia em zero
		aux = matriz[i][k];             // Inicia-se o looping para a troca
		matriz[i][k] = matriz[j][k];    // de linhas dos respectivos incides
		matriz[j][k] = aux;             // i e j da matriz[n][n]
	}
}

void triang_matriz(int n, double matriz[][n]) {

    // // -----------------------------------------------------------------------------
    //
    // Função triang_matriz
    // Argumentos:
    // 	- matrix[n][n]: matriz de floats, sobre a qual vai ser calculado o determinante normalizado.
    //	- n: a ordem da matriz.
    // Retorna:
    // 	- void.
    // OBS:
    //  - É feita a triangularização apenas da parte inferior da diagonal principal.
    // // -----------------------------------------------------------------------------

	int i, j, k;
    // Inicializa indices para percorrer na matriz.
	double ratio;
    // Ratio é o multiplicador da linha
	for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j>i){
            // Condição para pivotação ser apenas na parte inferior da diagonal principal.
                if(matriz[i][i] == 0){
                // Caso o pivotante seja 0, é necessário trocar-lo com outra linha.
                	troca_linha(n, matriz, i, j);
                    // A função acima, faz a troca da linha do pivotante com a linha do multiplicador.
				}
				ratio = matriz[j][i]/matriz[i][i];
                // É atribuido o valor do multiplicador da linha na variavl ratio.
                for(k = 0; k < n; k++){
                    matriz[j][k] -= ratio * matriz[i][k];
                    // É feita a compensação de valores da matriz.
                }
            }
		}
	}
}

double calc_det(int n, double matriz[][n]) {

    // // -----------------------------------------------------------------------------
    //
    // Função calc_det
    // Argumentos:
    // 	- matrix[n][n]: matriz de floats, sobre a qual vai ser calculado o determinante normalizado.
    //	- n: a ordem da matriz.
    // Retorna:
    // 	- determinante da matriz.
    //
    // // -----------------------------------------------------------------------------

	double det = 1;
    // Inicializa det em 1.
	int i;
	for(i = 0; i < n; i++) {
        det = det * matriz[i][i];
        // Det é equivalente a multiplicação da diagonal principal da matriz triangularizada.
    }
    if(det<0) {
	   	det = (-1)*(det);
	}
    return det;
}

double calc_den(int n, double matriz[][n], double denominador[n]) {

    // // -----------------------------------------------------------------------------
    //
    // Função calc_den
    // Argumentos:
    // 	- matrix[n][n]: matriz de floats, sobre a qual vai ser calculado o determinante normalizado.
    // 	- denominador[n]: vetor vazio, de tamanho no máxmo 25, que vai receber a norma de cada uma das linhas da matriz.
    //	- n: a ordem da matriz.
    // Retorna:
    // 	- (V1*V2*V3*...*Vn)^1/2, onde Vi é a norma da linha i.
    //
    // // -----------------------------------------------------------------------------

    double sumLine;
    // Inicia-se um somador para recolher o valor total da linha somada.
    int i, j, k;
    for(i = 0; i < n; i++) {
        sumLine = 0;
        for(j = 0; j < n; j++) {
            sumLine += (pow(matriz[i][j], 2));
            // Cada indice da linha é elevado ao quadrado e somado no somador.
        }
        denominador[i] = sqrt(sumLine);
        // Cada incide do vetor denominador é equivalente a raiz quadrada da soma de cada indice da linha ao quadrado.
    }
        
    double den = 1;
    // Inicia-se o resultado do den em 1.
    for(k = 0; k < n; k++) {
        den = den * denominador[k];
        // O den é equivalente a multiplicação de cada indice do vetor denominador.
    }
    return den;
} 

void print_matriz(int n, double matriz[][n]) {

    // // -----------------------------------------------------------------------------
    //
    // Função print_matriz
    // Argumentos:
    // 	- matrix[n][n]: matriz de floats, sobre a qual vai ser calculado o determinante normalizado.
    //	- n: a ordem da matriz.
    // Retorna:
    // 	- void.
    //
    // // -----------------------------------------------------------------------------

    int i, j;
    // Inicializa os indices para caminhar pela matriz.
    	printf("[");
	for(i = 0; i < n; i++) {
	    printf("[");
        for(j = 0; j < n; j++) {
            if(j == n - 1){
            	if(i == n-1){
            		printf("%.6lf]", matriz[i][j]);
            	}
            	else
            		printf("%.6lf],", matriz[i][j]);
            }
            else
	    	printf("%.6lf, ", matriz[i][j]);
	    	// Cada elemento da matriz é printado com 2 casas decimais.
        }
        if(i == n-1)
        	printf("]");
        else
        	printf("\n");
    }
    printf("\n\n");
}

void save_matrix(int n, double matriz[][n]){

    // // -----------------------------------------------------------------------------
    //
    // Função save_matrix
    // Argumentos:
    // 	- matrix[n][n]: matriz de floats, sobre a qual vai ser calculado o determinante normalizado.
    //	- n: a ordem da matriz.
    // Retorna:
    // 	- void.
    //
    // Função:
    // - salva a matrix num arquivo txt, a fim de testá-la num código python.
    //
    // // -----------------------------------------------------------------------------

	int i,j;
	FILE *f = fopen("matrix.txt", "w");
	if(f==NULL){
		printf("File not found!");
		return;
	}
    fprintf(f, "[");
	for(i=0; i < n; i++){
		fprintf(f, "[");
		for(j=0; j<n; j++){
		
			if(j == n - 1){
			    	if(i == n-1){
			    		fprintf(f,"%.6lf", matriz[i][j]);
				    }
                    else
                        fprintf(f,"%.6lf,", matriz[i][j]);
            }
            else
                fprintf(f,"%.6lf, ", matriz[i][j]);
			
		}
		if(i == n-1)
            fprintf(f,"]");
        else
            fprintf(f,"\n");
	
	}
}

int main(){
	
	int n;
    // n é a ordem da matriz.

	printf("Informe a ordem da matriz: ");
    scanf("%d", &n);
    if(n>25){
        printf("O valor ultrapassa o limite de 25\n");
        return 0;
    }
    // Recolhe a ordem da matriz pro uma entrada do teclado.

    // Declara uma matriz de ordem n x n, o vetor denominador de tamanho n
    double matriz[n][n], denominador[n];
    
    biuld_random_matriz(n, matriz);
    // A função acima constroi a matriz.
    save_matrix(n,matriz);
    // A função acima salva a matriz num txt
    print_matriz(n,matriz);
    // A função acima mostra no terminal um pront da matriz.

    int flag = check_if_condinioned(n, matriz);
    // A função acima retornar 0 caso a matriz tenha alguma condição de indeterminação.
    
    
    if (flag) {
    	printf("A matriz possui linha nula!");
	}
    // O programa não procede caso o indice de condição de indeterminação(flag) seja true.
	
	else {
	    double den = calc_den(n, matriz, denominador);
        // A função acima calcula o denominador da formula.
		triang_matriz(n,matriz);
        // A função acima triangulariza a diagonal menor da matriz.
		double det = calc_det(n, matriz);
        // A função acima calcula o determinante da matriz.
	    double detN = det/den;
        // A linha acima recebe o valor do determinante normalizado da matriz.
	        
	    printf("Determinante: %.4lf\n", det);
	    printf("Denominador : %.4lf\n", den);
	    printf("Determinante Normalizado: %.4lf\n", detN);
	}
	
    return 0;
}
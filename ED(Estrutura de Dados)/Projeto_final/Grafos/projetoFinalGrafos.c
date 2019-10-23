#include <stdio.h>
//==========GLOBAL==========
int matrix[3][3] = {0};
int VectorCheck[10000000][3][3] = {0};
int POS[10000000][3][3] = {0};
int indicePOS = 0;
int indiceAtual = 0;
int indiceVectorCheck = 0;
int vectorIndice[2] = {0};
int instancias = 0;
//==========GLOBAL==========

//=========PROTOTIPO========
int checkRepeat(int k);
int findNumber(int number);
void creatPos();
void setStart();
int checkHit();
int BFS();
//=========PROTOTIPO========

int checkRepeat(int k){
	int flag = 1;
	int countEquals = 0;
	if(k < indiceVectorCheck){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if(VectorCheck[k][i][j] != matrix[i][j]){
					k++;
					flag = checkRepeat(k);
					return flag;
				}else{
					countEquals++;
				}
			}
		}
		if(countEquals == 9){
			return 0;
		}
	}else{
		return 1;
	}
}

int findNumber(int number){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(matrix[i][j] == number){
				vectorIndice[0] = i;
				vectorIndice[1] = j;
				return 0;
			}
		}			
	}
}

int BFS(){
	instancias++;
	//printf("Instancia: %d\n", instancias);
	
	//int a;
	//scanf("%d", &a);

	if(checkRepeat(0)){ // Return 1: Nao esta no VectorCheck -- Return 0: Esta no VectorCheck
		for (int i = 0 ;i < 3; i++){
			for (int j = 0 ;j < 3; j++){
				VectorCheck[indiceVectorCheck][i][j] = matrix[i][j];
			}
		}
		indiceVectorCheck++;

		for(int i = 1; i < 5; i++){
			findNumber(i);
			creatPos();
		}

		if(checkHit()){
			return 0;
		}

	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			//printf("%d ", matrix[i][j]);
			matrix[i][j] = POS[indiceAtual][i][j];
		}
		//printf("\n");
	}
	//printf("\n");

	indiceAtual++;

	BFS();
}

void setStart(){
	matrix[0][0] = 1;
	matrix[0][2] = 2;
	matrix[2][0] = 3;
	matrix[2][2] = 4;
	
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			printf("%d ", matrix[i][j]);	
		}
		printf("\n");
	}	
	printf("\n");

	// Start
	// 1 0 2
	// 0 0 0
	// 3 0 4
}

int checkHit(){
	if(matrix[0][0] == 4 &&	matrix[0][2] == 3 && matrix[2][0] == 2 && matrix[2][2] == 1){	
		return 1;
	}else{
		return 0;
	}

	// Final
	// 4 0 3
	// 0 0 0
	// 2 0 1
}

void creatPos(){
	int matrixAux[3][3];
	int aux = 0;

	for(int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			matrixAux[i][j] = matrix[i][j];
		}
	}

	if(vectorIndice[0] == 0 && vectorIndice[1] == 0){ //Posição 0 - 0
		
		if(matrixAux[2][1] == 0){

			aux = matrixAux[0][0];
			matrixAux[0][0] = matrixAux[2][1];
			matrixAux[2][1] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
				
			}
			indicePOS++;
		}

		if(matrixAux[1][2] == 0){

			aux = matrixAux[0][0];
			matrixAux[0][0] = matrixAux[1][2];
			matrixAux[1][2] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
				
			}
			indicePOS++;
		}

	}else if(vectorIndice[0] == 0 && vectorIndice[1] == 1){ // Posição 0 - 1
		
		if(matrixAux[2][0] == 0){

			aux = matrixAux[0][1];
			matrixAux[0][1] = matrixAux[2][0];
			matrixAux[2][0] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}
		
		if(matrixAux[2][2] == 0){

			aux = matrixAux[0][1];
			matrixAux[0][1] = matrixAux[2][2];
			matrixAux[2][2] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}

	}else if(vectorIndice[0] == 0 && vectorIndice[1] == 2){ // Posição 0 - 2
		
		if(matrixAux[2][1] == 0){

			aux = matrixAux[0][2];
			matrixAux[0][2] = matrixAux[2][1];
			matrixAux[2][1] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}

		if(matrixAux[1][0] == 0){

			aux = matrixAux[0][2];
			matrixAux[0][2] = matrixAux[1][0];
			matrixAux[1][0] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}
		
	}else if(vectorIndice[0] == 1 && vectorIndice[1] == 0){ // Posição 1 - 0
		
		if(matrixAux[0][2] == 0){

			aux = matrixAux[1][0];
			matrixAux[1][0] = matrixAux[0][2];
			matrixAux[0][2] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}

		if(matrixAux[2][2] == 0){

			aux = matrixAux[1][0];
			matrixAux[1][0] = matrixAux[2][2];
			matrixAux[2][2] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}
		
	}else if(vectorIndice[0] == 1 && vectorIndice[1] == 2){ // Posição 1 - 2
		
		if(matrixAux[0][0] == 0){

			aux = matrixAux[1][2];
			matrixAux[1][2] = matrixAux[0][0];
			matrixAux[0][0] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}
		
		if(matrixAux[0][2] == 0){

			aux = matrixAux[1][2];
			matrixAux[1][2] = matrixAux[0][2];
			matrixAux[0][2] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}
		
	}else if(vectorIndice[0] == 2 && vectorIndice[1] == 0){ // Posição 2 - 0
		
		if(matrixAux[0][1] == 0){

			aux = matrixAux[2][0];
			matrixAux[2][0] = matrixAux[0][1];
			matrixAux[0][1] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}
		
		if(matrixAux[1][2] == 0){

			aux = matrixAux[2][0];
			matrixAux[2][0] = matrixAux[1][2];
			matrixAux[1][2] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}
		
	}else if(vectorIndice[0] == 2 && vectorIndice[1] == 1){	// Posição 2 - 1
		
		if(matrixAux[0][0] == 0){

			aux = matrixAux[2][1];
			matrixAux[2][1] = matrixAux[0][0];
			matrixAux[0][0] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}
		
		if(matrixAux[0][2] == 0){

			aux = matrixAux[2][1];
			matrixAux[2][1] = matrixAux[0][2];
			matrixAux[0][2] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}
		
	}else if(vectorIndice[0] == 2 && vectorIndice[1] == 2){ // Posição 2 - 2
		
		if(matrixAux[0][1] == 0){

			aux = matrixAux[2][2];
			matrixAux[2][2] = matrixAux[0][1];
			matrixAux[0][1] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}
			
		if(matrixAux[1][0] == 0){

			aux = matrixAux[2][2];
			matrixAux[2][2] = matrixAux[1][0];
			matrixAux[1][0] = aux;

			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					POS[indicePOS][i][j] = matrixAux[i][j]; //Grava a possibildiade no vetor de possibilidade
					matrixAux[i][j] = matrix[i][j]; //Reseta o vetor pra próxima interação
				}
			}
			indicePOS++;
		}
	}
}	

int main(){
	setStart();

	BFS();

	printf("Caso contrado:\n");
	
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			printf("%d ", matrix[i][j]);	
			matrix[i][j] = POS[indiceAtual++][i][j];
		}
		printf("\n");
	}
	printf("Foram usados %d instancias\n", instancias);
	return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 3
#define max 10

int check_if_condinioned(double matriz[SIZE][SIZE], int n) {
	int i, j;
    int nullLine = 0, flag = 0;
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
    		if(matriz[i][j] == 0) {
    			nullLine++;
			}
        }
        if(nullLine == n) {
        	flag = 1;
		}
		nullLine = 0;
    }
    return flag;
}

void biuld_matriz(double matriz[SIZE][SIZE], int n) {
	srand( (unsigned)time(NULL) );
	int i, j;    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
        	//matriz[i][j] = rand() % 10;									//Inteiro randomico
        	//matriz[i][j] = (((float)rand()/(float)(RAND_MAX)) * max);		//Float randomico
        	scanf("%lf", &matriz[i][j]);									//Entrada do teclado
        }
    }
}

void troca_linha(double matriz[SIZE][SIZE], int i, int j) {
	double aux;
	int k;
	for(k = 0; k < SIZE; k++) {
		aux = matriz[i][k];
		matriz[i][k] = matriz[j][k];
		matriz[j][k] = aux;
	}
}

void triang_matriz(double matriz[SIZE][SIZE], int n) {
	int i, j, k;
	double ratio;
	for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j>i){
                if(matriz[i][i] == 0){
                	troca_linha(matriz, i, j);
				}
				ratio = matriz[j][i]/matriz[i][i];
                for(k = 0; k < n; k++){
                    matriz[j][k] -= ratio * matriz[i][k];
                }
            }
		}
	}
}

double calc_det(double matriz[SIZE][SIZE], int n) {
	double det = 1;
	int i;
	for(i = 0; i < n; i++) {
        det = det * matriz[i][i];
    }
    if(det<0) {
	   	det = (-1)*(det);
	}
    return det;
}

double calc_den(double matriz[SIZE][SIZE], double denominador[SIZE], int n) {
    double sumLine;
    int i, j, k;
    for(i = 0; i < n; i++) {
        sumLine = 0;
        for(j = 0; j < n; j++) {
            sumLine += (pow(matriz[i][j], 2));
        }
        denominador[i] = sqrt(sumLine);
    }
        
    double den = 1;
    for(k = 0; k < n; k++) {
        den = den * denominador[k];
    }
    return den;
} 

void print_matriz(double matriz[SIZE][SIZE], int n) {
    int i, j;
	for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%.2lf, ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}

int main(){
	double matriz[SIZE][SIZE], denominador[SIZE];
	int n;
	printf("Informe a ordem da matriz: ");
    scanf("%d", &n);
    
    biuld_matriz(matriz, n);
    triang_matriz(matriz, n);
    int flag = check_if_condinioned(matriz, n);
    print_matriz(matriz, n);
    
    if (flag) {
    	printf("Matriz de linha nula!");
	} 
	
	else {
	    double den = calc_den(matriz, denominador, n);
		double det = calc_det(matriz, n);
	    double detN = det/den;
	        
	    printf("Determinante: %.4lf\n", det);
	    printf("Denominador : %.4lf\n", den);
	    printf("Determinante Normalizado: %.4lf", detN);
	}
	
    return 0;
}

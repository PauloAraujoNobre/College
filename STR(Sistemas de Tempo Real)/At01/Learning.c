#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void slow() {
	int i, j, k;
	int valor = 1000;
	
	for (i = 0; i < valor; i++) {
		for (j = 0; j < valor; j++) {
			for (k = 0; k < valor; k++) {
				valor = valor;
			}
		}
	}
}

void *func(void * arg) {
	int *pvalor;
	pvalor = arg;
	
	printf("Thread %i executando... \n", *pvalor);
	
	slow();
	
	printf("Thread %i finalizada.. \n", *pvalor);
}

int main(){
	pthread_t threads [NUM_THREADS];
	int i, arg[NUM_THREADS];
	
	for (i = 0; i < NUM_THREADS; i++) {
		arg[i] = i + 1;
		pthread_create(&threads[i], NULL, func, (void *)&arg[i]);
	}
	
	for (i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL)	;
	}
	
	printf("\n");
}

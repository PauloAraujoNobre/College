#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <strings.h>

#define SIZE 30

char v[SIZE];
int flag[3] = {1, 0, 0};
int indice = 0;

void *function (void *arg) {
	int *valor = (int *)arg;
	
	while (indice < SIZE) {
		if (flag[0] == 1 && *valor == 1) {
			strcat (v, "A");
			flag[0] = 0;
			flag[1] = 1;
			
			indice++;
		} else if (flag[1] == 1 && *valor == 2) {
			strcat (v, "B");
			flag[1] = 0;
			flag[2] = 1;
			
			indice++;
		} else if (flag[2] == 1 && *valor == 3) {
			strcat (v, "C");
			flag[2] = 0;
			flag[0] = 1;
			
			indice++;
		}
	}
}

int main (){
	pthread_t t0, t1, t2;
	int i;
	int a0 = 1;
	int a1 = 2;
	int a2 = 3;

	pthread_create(&t0, NULL, function, &a0);	
	pthread_create(&t1, NULL, function, &a1);
	pthread_create(&t2, NULL, function, &a2);

	pthread_join(t0, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("%s\n", v);


	exit(0);
}

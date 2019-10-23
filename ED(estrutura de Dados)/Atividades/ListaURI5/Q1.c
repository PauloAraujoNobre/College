#include <stdio.h>
int main(){
	int i, j, n, n1, aux, countX, countS, count = 1, x[51], y[51];
	countS = count;
	
	scanf("%d", &n);
	while(n != 0){
	    
	    for(i = 0; i < 51; i++){
	       	x[i] = 0;
		    y[i] = 0;
	    }
	    
		for(i = n, j = 0; i > 0; i--, j++){
			x[j] = i;
		}
		
		countX = 0;
		
		while(countS < n){
			count = 1;
		    y[countX] = x[n - count];
			aux = x[n - count - 1]; 

			while(n > count){
				count++;
				x[n - count] = x[n - count - 1];
			}
			
			x[0] = aux;
            countX++;
			n--;
		}
		
    	printf("Discarded cards: %d", y[0]);
    	
        for(i = 1; y[i] != 0; i++){
            printf(", %d", y[i]);
        }
        
        printf("\nRemaining card: %d\n", x[0]);
    	
    	scanf("%d", &n);
	}
	
	return 0;
}

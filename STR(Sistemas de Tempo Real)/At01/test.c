#include <stdio.h>
#include <stdlib.h>

int main (){
	char teste[4];
	strcat (teste, "A");
	//teste[0] = "a";
	//teste[1] = "b";
	
	printf("%s\n", teste);
	printf("%s\n", teste[0]);
}

#include<stdio.h>
int main(){
int i, j, count = 0;
char c;
double matrix[12][12], soma = 0;
scanf("%c", &c);
getchar();
for(i = 0; i < 12; i++){
    for(j = 0; j < 12; j++){
        scanf("%lf", &matrix[i][j]);
        if((i + j) < 11){
            soma = soma + matrix[i][j];
            count++;
        }   
    }
}
if(c == 'S'){
    printf("%.1lf\n", soma);
}else if(c == 'M'){
    printf("%.1lf\n", soma/count);
}

return 0;
}

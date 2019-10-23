#include<stdio.h>
int main(){
   int i, j, col;
   char c;
   double matrix[12][12], soma = 0;
   scanf("%d", &col);
   getchar();
   scanf("%c", &c);

   for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%lf", &matrix[i][j]);
            if(j == col){
                soma += matrix[i][j];
            
            }
        }

   }
   if(c == 'S'){
        printf("\n%.1lf\n", soma);
   }else if(c == 'M'){
         printf("%.1lf\n", soma/12);
   }
   
   return 0;
}

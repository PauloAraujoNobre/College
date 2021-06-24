const int n = 19;
int i, j, k;

double det[2] = {1, 1};
double den[2] = {1, 1}; 

double sumLine = 0, ratio, aux;
double matriz[n][n], denominador[n];

void setup()
{
    Serial.println("Antigo");
    
    Serial.begin(9600);
    randomSeed(analogRead(0));
    
    biuld_matriz();
    print_matriz();
    calc_den();
    triang_matriz();
    print_matriz();
    calc_det();
    
    Serial.print("Det1:  ");
    Serial.println(det[0], 4);
    Serial.print("Det2:  ");
    Serial.println(det[1], 4);
    Serial.println("Det = Det1 * Det2");
    Serial.println("");  
    
    Serial.print("Den1: ");
    Serial.println(den[0], 4);
    Serial.print("Den2: ");
    Serial.println(den[1], 4); 
    Serial.println("Den = Den1 * Den2");
    Serial.println("");
    
    Serial.println("DetN = Det/Den");
    Serial.println("");
  
    Serial.println(millis());
}

void troca_linha(int i_aux, int j_aux) {
    for(k = 0; k < n; k++) {
        aux = matriz[i_aux][k];
        matriz[i_aux][k] = matriz[j_aux][k];
        matriz[j_aux][k] = aux;
    }
}

void triang_matriz() {
    Serial.println("Matriz Triangularizada:");  
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j>i){
                if(matriz[i][i] == 0){
                  troca_linha(i, j);
                }
                ratio = matriz[j][i]/matriz[i][i];
                for(k = 0; k < n; k++){
                    matriz[j][k] -= (ratio * matriz[i][k]);
                }
            }
        }  
    }
}

void calc_den() {
    for(i = 0; i < n; i++) {
        sumLine = 0;
        for(j = 0; j < n; j++) {
            sumLine += (pow(matriz[i][j], 2));
        }
        denominador[i] = sqrt(sumLine);
    }

    for (k = 0; k < n; k++) {
      if (k < n/2) {
        den[0] *= denominador[k];
      }
      if (k >= n/2 && k < n) {
        den[1] *= denominador[k];
      }
    }
}

void calc_det() {
    for (k = 0; k < n; k++) {
      if (k < n/2) {
        det[0] *= matriz[k][k];
      }
      if (k >= n/2 && k < n) {
        det[1] *= matriz[k][k];
      }
    }
    
    if(det[0]<0) {
        det[0] = (-1)*(det[0]);
    }
    if(det[1]<0) {
        det[1] = (-1)*(det[1]);
    }
}

void biuld_matriz() {
    Serial.println("Matriz:");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
              matriz[i][j] = random(1, 3000) / 1000.0;
        }
    }
}

void print_matriz() {
  Serial.print("[");
  for(i = 0; i < n; i++) {
      Serial.print("[");
        for(j = 0; j < n; j++) {
            if(j == n - 1){
              if(i == n-1){
                Serial.print(matriz[i][j], 4);
                Serial.print("]");
              }
              else {
                Serial.print(matriz[i][j], 4);
                Serial.print("],");
              }
            }
            else {
              Serial.print(matriz[i][j], 4);
              Serial.print(", ");
            }
        }
        if(i == n-1){
          Serial.print("]");
        }
        else {
          Serial.println("");
        }
    }
    Serial.println("");
    Serial.println("");
}

void loop() {}

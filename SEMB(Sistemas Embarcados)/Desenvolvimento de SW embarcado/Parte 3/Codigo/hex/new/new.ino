const int n = 19;
short i, j, k;

double det[2] = {1, 1};
double den[2] = {1, 1}; 

double sumLine, ratio;
double matriz[n][n];

void setup()
{
    Serial.println(F("Novo"));
    
    Serial.begin(9600);
    randomSeed(analogRead(0));
    
    biuld_matriz();
    print_matriz();
    calc_den();
    triang_matriz();
    print_matriz();
    calc_det();

    Serial.print(F("Det1:  "));
    Serial.println(det[0], 4);
    Serial.print(F("Det2:  "));
    Serial.println(det[1], 4);
    Serial.println(F("Det = Det1 * Det2"));
    Serial.println(F(""));  
    
    Serial.print(F("Den1: "));
    Serial.println(den[0], 4);
    Serial.print(F("Den2: "));
    Serial.println(den[1], 4); 
    Serial.println(F("Den = Den1 * Den2"));
    Serial.println(F(""));
    
    Serial.println(F("DetN = Det/Den"));
    Serial.println(F(""));

    Serial.println(millis());
}

void triang_matriz() {
    Serial.println(F("Matriz Triangularizada:"));
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            ratio = matriz[j][i]/matriz[i][i];
            for(k = 0; k < n; k++){
                matriz[j][k] -= (ratio * matriz[i][k]);
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

        den[0] *= (i < n/2 ? sqrt(sumLine) : 1);
        den[1] *= (i >= n/2 ? sqrt(sumLine) : 1);
    }
}

void calc_det() {
    for (k = 0; k < n; k++) {
        det[0] *= (k < n/2 ? matriz[k][k] : 1);
        det[1] *= (k >= n/2 ? matriz[k][k] : 1);
    }

    det[0] *= (det[0]<0 ? -1 : 1);
    det[1] *= (det[1]<0 ? -1 : 1);
}

void biuld_matriz() {
    Serial.println(F("Matriz:"));
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
              matriz[i][j] = random(1, 3000) / 1000.0;
        }
    }
}

void print_matriz() {
  Serial.print(F("["));
  for(i = 0; i < n; i++) {
      Serial.print(F("["));
      for(j = 0; j < n; j++) {
          if(j == n - 1){
              if(i == n-1){
                  Serial.print(matriz[i][j], 4);
                  Serial.print(F("]"));
              }
              else {
                  Serial.print(matriz[i][j], 4);
                  Serial.print(F("],"));
              }
          }
          else {
              Serial.print(matriz[i][j], 4);
              Serial.print(F(", "));
          }
      }
      if(i == n-1){
          Serial.print(F("]"));
      }
      else {
          Serial.println(F(""));
      }
    }
    Serial.println(F(""));
    Serial.println(F(""));
}

void loop() {}

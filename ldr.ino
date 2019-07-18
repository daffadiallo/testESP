define LDRpin A0 

int LDRValue = 0;     // resultat de la lecture analogique de la broche

void setup() {
  Serial.begin(9600); // Initialisation du port serie 
}

void loop() {
  LDRValue = analogRead(LDRpin); // Lis la valeur du LDR
  Serial.println(LDRValue);      // Ecrit la valeur lu sur le port serie
  delay(100);                    // Attendre un peu
}

//const int capteur_D = 4; // pin connecté à la sortie digital du capteur
const int capteur_A = A0; // pin connecté à la sortie analogique du capteur

int val_analogique;

void setup()
{
  pinMode(capteur_D, INPUT);
  //pinMode(capteur_A, INPUT);
  Serial.begin(9600);
}

void loop()
{
//Partie Digital

if(digitalRead(capteur_D) == LOW) // Le capteur est actif à l'état bas
  {
    Serial.println("Valeur digital : mouille"); 
    delay(10); // Tempo
  }
else
  {
    Serial.println("Valeur digital : Pas mouille");
    delay(10); // Tempo
  }

// Partie analogique
 
 val_analogique=analogRead(capteur_A); // on lit la broche capteur "analogique"
 Serial.print("Valeur analogique : ");
 Serial.println(val_analogique); // afficher la valeur de detection sur la liison série
 Serial.println("");
  delay(1000);
}

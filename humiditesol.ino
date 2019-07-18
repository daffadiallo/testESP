int PinSensor = A0;

int ValeurSensor = 0;
int pourcentage = 0;

void setup(){
 Serial.begin(9600);
}

void loop(){
 ValeurSensor = analogRead(PinSensor);
 pourcentage = ConvertEnPercent(ValeurSensor);
 AfficheValeurEtPourcentage();
 delay(1000);
}

int ConvertEnPercent(int value){
 int ValeurPorcentage = 0;
 ValeurPorcentage = map(value, 1023, 465, 0, 100);
 return ValeurPorcentage;
}

void AfficheValeurEtPourcentage(){
 Serial.print("Valeur: ");
 Serial.println(ValeurSensor);
 Serial.print("Pourcentage: ");
 Serial.print(pourcentage);
 Serial.println("%");
 Serial.println("-----------");
}

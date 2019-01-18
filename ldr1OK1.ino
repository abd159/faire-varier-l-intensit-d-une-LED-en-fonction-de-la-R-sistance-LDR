int pinPR = A0; //pin de connexion pour la photorésistance
int valMin = 1024; // on initialise la valeur minimale au plus haut
int valMax = 0; // et la valeur maximale au plus bas

int pinLED = 9;  
int ledValue =0;  

void setup()
{
  Serial.begin(9600);
  pinMode (pinLED, OUTPUT); // on indique que la LED est une sortie
}
void loop()
{
  int valeur = analogRead(pinPR); // on lit la valeur transmise par la photorésistance
  if (valeur > valMax) //on compare avec valMax
    valMax = valeur; // on modifie valMax
  if (valeur < valMin) // on compare avec valMin
    valMin = valeur; // on modifie valMin
  int pourcentage = map(valeur, valMin, valMax, 0, 100); //pourcentage entre les bornes
  //Séquence d'affichage
  Serial.print("Valeur : ");
  Serial.print(valMin);
  Serial.print(" < ");
  Serial.print(valeur);
  Serial.print(" < ");
  Serial.print(valMax);
  Serial.print("  soit : ");
  Serial.print(pourcentage);
  Serial.print(" %");

 int ledValue=map(pourcentage, 0, 100,0,255); //fonction de mappage

  Serial.print("ledValue= ");
  Serial.println(ledValue);
  analogWrite(pinLED,ledValue); //on allume la LED
   delay(10);
}

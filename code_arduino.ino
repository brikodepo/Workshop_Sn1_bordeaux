#include <NewPing.h> // récupération des deux blibliothèques pour faire fonctionner le programme. NewPing pour le detecteur, Liquid pour l'écrans LCD //
#include <LiquidCrystal_I2C.h>

const int echoPin = 7;
const int trigPin = 8;
NewPing sonar (trigPin, echoPin, 140); //Definition des broches, dans l'ordre, trig puis echo. Puis en troisème valeur la longueur de scan. //


unsigned long previousTime = 0;    // initialisation d'une valeur spéciale qui va nous servir de chronomètre. //
float a = 0;
float b = 0;                    // definition des valeurs qui vont nous servir pour le reste du programme. Int, float, et unsingned long sont les types, et les caractères qui suivent les noms de celle ci //
int temps = 0;
float c = 0;

LiquidCrystal_I2C lcd(0x27,16,2); // initialisation de notre écran qui est un écran 16 par 2 cases. 


void setup()
{
Serial.begin(9600);
delay(50);                            // variable d'initialisation générales, alumage et nettoyage de l'écran. //
lcd.init();                      
lcd.init();
lcd.backlight();
}





void loop() 
{
b = b + 1; 
Serial.print("La distance est :");
Serial.println(sonar.ping_cm()); // Permet d'afficher la longeur captée par le capteur après la phrase inscrite //
delay(100); // Un délai de 100MS a été mis en place entre chaque nouveau scan //

  previousTime = millis(); // Permet de donner a la variable previousTime la valeur de "millis" qui signifie milliseconde.


 // affichage des valeurs sur écran LCD //


  lcd.setCursor(0,1); // L'affichage marche de la facon suivante, (ligne, colonne) et cela sert a dire ou mettre le curseur pour écrire. //
  lcd.print(c*100); // affichage du pourcentage de présence //
  lcd.setCursor(0,0);
  lcd.print(a/4); // affiche le temps ou quelque chose a été detecté par le capteur //
  lcd.setCursor(7,0);
  lcd.print(previousTime/1000); // affiche un chronomètre en seconde // 


if (sonar.ping_cm() > 0) digitalWrite(13, HIGH); // Sert a allumer ou eteindre la lumière si le capteur capte un distance différente de 0 //
if (sonar.ping_cm() == 0) digitalWrite(13, LOW);


 // affichage valeur sur le moniteur de controle // 


if (sonar.ping_cm() > 0) a = a + 1; 
Serial.print("Le detecteur est en fonctionnement depuis :");
Serial.println(b/4); 
Serial.print("Une presence a ete detectee pendant : ");
Serial.println(a/4); // Affiche le temps de présence total //
c = a/b;
Serial.print("Sur la duree de fonctionnement, une presence a ete detecte ");
Serial.println(c); // affiche le % de présence // 
Serial.println("% du temps");
}

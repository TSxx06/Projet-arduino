
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

//step moteur fils (male/femelle) ---> vert/Bleu, bleu/vert, rouge/rouge, jaune/orange
//lcd fils haut -> bas = bleu/vert/marron/bleu
Servo servotrappe; //trappe
Servo servobras; //bras
LiquidCrystal_I2C lcd(0x27, 20, 4);
//LiquidCrystal_I2C lcd(0x3F,20,4);
const int bouton = 3;
int val=0;
const int led_rouge=2;
const int inter1 = 4;
const int inter2 = 5;
const int inter3 = 6;
const int inter4 = 7;
const int inter5 = 8;
const int inter6 = 9;
const int inter7 = 10;
const int Pas = 13;
const int Dir = 12;



void setup() {
  Serial.begin(115200);
  servotrappe.attach(A0);
  pinMode(bouton,INPUT);
  pinMode(led_rouge,OUTPUT);
  digitalWrite(led_rouge,LOW);
  pinMode(Pas,OUTPUT);
  pinMode(Dir,OUTPUT);
  digitalWrite(Dir,HIGH);
  pinMode(inter1,INPUT_PULLUP);
  pinMode(inter2,INPUT_PULLUP);
  pinMode(inter3,INPUT_PULLUP);
  pinMode(inter4,INPUT_PULLUP);
  pinMode(inter5,INPUT_PULLUP);
  pinMode(inter6,INPUT_PULLUP);
  pinMode(inter7,INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Bonjour");
  lcd.setCursor(0,1);
  lcd.print("Jeune polypote");
  servotrappe.write(0);
  delay(1000);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(inter1);
  Serial.println(val);
  digitalWrite(Dir,HIGH);
  digitalWrite(Pas,HIGH);
  digitalWrite(led_rouge,LOW);
  if (digitalRead(inter1) == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("L'interrupteur 1");
    lcd.setCursor(0,1);
    lcd.print("Trop facile !!");
    appuyer();
    lcdFastoche();
    delay(1000);
    setledBase();
    delay(3000);
    
  }
  if (digitalRead(inter2) == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("L'interrupteur 2");
    lcd.setCursor(0,1);
    lcd.print("...");
    digitalWrite(Dir,HIGH);
    for (int x=0;x<150;x++){
      digitalWrite(Pas,HIGH);
      delayMicroseconds(500);
      digitalWrite(Pas,LOW);
      delay(4);
    }
    digitalWrite(Dir,LOW);
    appuyer();
    lcdFastoche();
    for (int x=0;x<150;x++){
      digitalWrite(Pas,HIGH);
      delayMicroseconds(500);
      digitalWrite(Pas,LOW);
      delay(4);
    }
    delay(1000);
    setledBase();
    delay(3000);
  }
  if (digitalRead(inter3) == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("L'interrupteur 3");
    lcd.setCursor(0,1);
    lcd.print("Ca fait loin la");
    digitalWrite(Dir,HIGH);
    for (int x=0;x<325;x++){
      digitalWrite(Pas,HIGH);
      delayMicroseconds(500);
      digitalWrite(Pas,LOW);
      delay(4);
    }
    digitalWrite(Dir,LOW);
    appuyer();
    lcdFastoche();
    for (int x=0;x<325;x++){
      digitalWrite(Pas,HIGH);
      delayMicroseconds(500);
      digitalWrite(Pas,LOW);
      delay(4);
    }
    delay(1000);
    setledBase();
    delay(3000);
  }
  if (digitalRead(inter4) == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("L'interrupteur 4");
    lcd.setCursor(0,1);
    lcd.print("T'es obstine toi");
    digitalWrite(Dir,HIGH);
    for (int x=0;x<510;x++){
      digitalWrite(Pas,HIGH);
      delayMicroseconds(500);
      digitalWrite(Pas,LOW);
      delay(4);
    }
    digitalWrite(Dir,LOW);
    appuyer();
    lcdFastoche();
    for (int x=0;x<510;x++){
      digitalWrite(Pas,HIGH);
      delayMicroseconds(500);
      digitalWrite(Pas,LOW);
      delay(4);
    }
    delay(1000);
    setledBase();
    delay(3000);
  }
  if (digitalRead(inter5) == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("L'interrupteur 5");
    lcd.setCursor(0,1);
    lcd.print("...");
    digitalWrite(Dir,HIGH);
    for (int x=0;x<700;x++){
      digitalWrite(Pas,HIGH);
      delayMicroseconds(500);
      digitalWrite(Pas,LOW);
      delay(4);
    }
    digitalWrite(Dir,LOW);
    appuyer();
    lcdFastoche();
    for (int x=0;x<700;x++){
      digitalWrite(Pas,HIGH);
      delayMicroseconds(500);
      digitalWrite(Pas,LOW);
      delay(4);
    }
    delay(1000);
    setledBase();
    delay(3000);
  }
  if (digitalRead(inter6) == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("L'interrupteur 6");
    lcd.setCursor(0,1);
    lcd.print("...");
    digitalWrite(Dir,HIGH);
    for (int x=0;x<900;x++){
      digitalWrite(Pas,HIGH);
      delayMicroseconds(500);
      digitalWrite(Pas,LOW);
      delay(4);
    }
    digitalWrite(Dir,LOW);
    appuyer();
    lcdFastoche();
    for (int x=0;x<900;x++){
      digitalWrite(Pas,HIGH);
      delayMicroseconds(500);
      digitalWrite(Pas,LOW);
      delay(4);
    }
    delay(1000);
    setledBase();
    delay(3000);
  }
  if (digitalRead(inter7) == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("L'interrupteur 7");
    lcd.setCursor(0,1);
    lcd.print("...");
    digitalWrite(Dir,HIGH);

    for (int x=0;x<1100;x++){
      digitalWrite(Pas,HIGH);
      delayMicroseconds(500);
      digitalWrite(Pas,LOW);
      delay(4);
    }
    digitalWrite(Dir,LOW);
    appuyer();
    lcdFastoche();
    for (int x=0;x<1100;x++){
      digitalWrite(Pas,HIGH);
      delayMicroseconds(500);
      digitalWrite(Pas,LOW);
      delay(4);
    }
    delay(1000);
    setledBase();
    delay(3000);
  }

}

void appuyer(){
  servotrappe.write(180);
  delay(2000);
  servotrappe.write(0);
}
void setledBase(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   Alors.. tu  ");
  lcd.setCursor(0,1);
  lcd.print("n'appuies plus ?");
}
void lcdFastoche(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Je t'avais dit");
  lcd.setCursor(0,1);
  lcd.print("Fastoche");
}

// Constants
const int Batt = A1;    // Напряжение на делителе с АКБ при её напряжении в 19.9: 2.34
const int Switch = A0;  // Напряжения на ползунке по порядку: 0, 1.6, 3.3, 3.8
const int Charge = A2;  //Аналоговвые значения меняются от 0 до 1023 относительно напряжения от 0 до 5 Вольт

const int Led1 = 3; // Светодиод 1-ого режима
const int Led2 = 4; // Светодиод 2-ого режима
const int Led3 = 2; // Светодиод 3-ого режима
const int Led4 = 5; // Светодиод зарядки
const int En_Power = 6; // Разрешение дежурного питания 5В
const int En_Motor = 9; //Убедитесь, что выбранный пин поддерживает PWM
const int En_Charge = 10; //Убедитесь, что выбранный пин поддерживает PWM

// Variables
unsigned long timing; // Переменная для хранения точки отсчета
int BattValue = 0;
int SwValue = 0;
int ChValue = 0;
int i = 0; 

int Led1State = HIGH;  
int Led2State = HIGH;  
int Led3State = HIGH;  
int Led14State = HIGH;  


void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(En_Power, OUTPUT);
  pinMode(En_Motor, OUTPUT);
  pinMode(En_Charge, OUTPUT);

  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH);
  digitalWrite(Led4, HIGH);
}

void loop() {

  BattValue = analogRead(Batt);
  SwValue = analogRead(Switch);
  ChValue = analogRead(Charge);

  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH);
  digitalWrite(Led4, HIGH);

  digitalWrite(En_Power, HIGH);
  digitalWrite(En_Charge, LOW);
  
  if (ChValue > 500 && ChValue < 800 ) {
    if (BattValue > 400 && BattValue < 420) {
      if (millis() - timing > 1000){ // Вместо 10000 подставьте нужное вам значение паузы 
        timing = millis(); 
        if (Led1State == HIGH) {
         Led1State = LOW;
        } else {
         Led1State = HIGH;
        }
      digitalWrite(Led1, Led1State);
      }
      analogWrite(En_Charge, 10);
      delay(100);
      digitalWrite(En_Charge, LOW);
      delay(400);
    } else if (BattValue > 420 && BattValue < 450) {
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      delay(500);
      digitalWrite(Led2, HIGH);
      delay(500);
      analogWrite(En_Charge, 10);
      delay(100);
      digitalWrite(En_Charge, LOW);
      delay(500);       
    } else if (BattValue > 450 && BattValue < 480) {
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, LOW);
      delay(500);
      digitalWrite(Led3, HIGH);
      delay(500);
      analogWrite(En_Charge, 10);
      delay(100);
      digitalWrite(En_Charge, LOW);
      delay(600);
    } else digitalWrite(Led4, LOW);
  } else if (ChValue > 10 && ChValue < 500) {
    digitalWrite(Led4, LOW);
    delay(200);
    digitalWrite(Led4, HIGH);
    delay(200);
  } else {
    if (BattValue > 400) {
      if (SwValue > 150 && SwValue < 380) {
        digitalWrite(Led1, LOW);
        digitalWrite(Led2, HIGH);
        digitalWrite(Led3, HIGH);
        analogWrite(En_Motor, 80);
        delay(5);
      } else if (SwValue > 450 && SwValue < 750) {
        digitalWrite(Led2, LOW);
        digitalWrite(Led1, HIGH);
        digitalWrite(Led3, HIGH);
        analogWrite(En_Motor, 140);
        delay(5);
      } else if (SwValue > 780 && SwValue < 1000) {
        digitalWrite(Led3, LOW);
        digitalWrite(Led1, HIGH);
        digitalWrite(Led2, HIGH);
        analogWrite(En_Motor, 240);
        delay(5);
      } else {
        digitalWrite(En_Motor, LOW);
        digitalWrite(En_Power, LOW);
      }
      delay(10);
      } else if (BattValue < 50 && ChValue < 1) { 
        while (i <= 3) {
        i = i + 1;
        digitalWrite(Led4, LOW);
        delay(500);
        digitalWrite(Led4, HIGH);
        delay(500);
      }  
      digitalWrite(En_Power, LOW);
      delay(100);
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      }
  }  
}

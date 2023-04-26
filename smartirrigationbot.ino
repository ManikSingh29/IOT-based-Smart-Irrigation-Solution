#include <Servo.h>
int motor1pin1 = 10;
int motor1pin2 = 11;

int motor2pin1 = 12;
int motor2pin2 = 13;
int AO = A0;
#define M1_Speed = 2
#define M2_Speed = 2
int sensorValue;
int limit = 300;
int sensorPin = A0; //Declaring analog pin 0 for Soil Moisture Sensor

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(A0, OUTPUT);
  myservo.attach(9);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:   
  for(int i=0; i<=5; i++)
  {digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

 }
  myservo.write(60);
    delay(1000);
  for(int i=0; i<=5; i++)
  {digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  }
  myservo.write(70);
  delay(1000);
  
  // for(int i=0; i<=5; i++)
  // {digitalWrite(motor1pin1, LOW);
  // digitalWrite(motor1pin2, HIGH);
   
  // digitalWrite(motor2pin1, LOW);
  // digitalWrite(motor2pin2, HIGH); 
  // }
  // delay(1000);

  // for(int i=0; i<=5; i++)
  // {digitalWrite(motor1pin1, LOW);
  // digitalWrite(motor1pin2, LOW);

  // digitalWrite(motor2pin1, LOW);
  // digitalWrite(motor2pin2, LOW);
  // }
  // delay(3000);
  //  myservo.writeMicroseconds(0);
  // delay(1000);
  // myservo.writeMicroseconds(180);
  // delay(1000);
  sensorValue = analogRead(sensorPin); 
    Serial.println("Analog Value : ");
    Serial.println(sensorValue);
  // myservo.writeMicroseconds(2000);
  // delay(1000);
  // myservo.writeMicroseconds(2250);
  // delay(1000);

}
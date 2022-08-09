#include <Servo.h>             //Import all the functions related to servo motors
#include <NewPing.h>        //Import all the functions related to UV Distace sensor

//Declaring arduino pins for motors 

const int LeftMotorForward = 5;
const int LeftMotorBackward = 4;
const int RightMotorForward = 3;
const int RightMotorBackward = 2;
const int sensormotorIN1 = 6;
const int sensormotorIN2 = 7;

//sensor pins
int trig_pin = A3; //Declaring analog pin 3 for trig of UV sensor
int echo_pin = A2 ;//Declaring analog pin 2 for echo of UV sensor
int sensorPin = A0; //Declaring analog pin 0 for Soil Moisture Sensor

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

//for soil moisture sensor
int sensorValue;  
int limit = 300; 

NewPing sonar(trig_pin, echo_pin, maximum_distance); // Calling sensor function
Servo servo_motor;                                  //Naming Servo motor

void setup(){
  Serial.begin(9600);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  servo_motor.attach(11); //our servo pin

  servo_motor.write(90);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  pinMode(13, OUTPUT);
}

void loop(){
  int input=0;
if(Serial.available()>0)
{
  input=Serial.read();
  Serial.write(input);
}
if(input==1){
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20){
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
    delay(15000);
    moveStop();
    digitalWrite(sensormotorIN1,HIGH);
    delay(4000);
    digitalWrite(sensormotorIN1,LOW);
    sensorValue = analogRead(sensorPin); 
    Serial.println("Analog Value : ");
    Serial.println(sensorValue);
 
    if (sensorValue<limit) {
    digitalWrite(13, HIGH); 
    Serial.print("Pump State: OFF");
    }
    else if(sensorValue >=300 && sensorValue<650)
    {
    digitalWrite(13, LOW); 
    Serial.print("Pump State: ON");
     }
     else
     {
      digitalWrite(13, HIGH); 
    Serial.println("Pump State: OFF");
 }
 delay(1000);
  }
    distance = readPing();
}
else
{
  moveStop();
}
  
}

int lookRight(){  
  servo_motor.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 
  
  
}

void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

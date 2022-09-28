const int LeftMotorForward = 5;
const int LeftMotorBackward = 4;
const int RightMotorForward = 3;
const int RightMotorBackward = 2;

void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  Serial.begin(9600);
 
  }

void loop(){
  char state;
  if(Serial.available()>1)
  {state=Serial.read();
  Serial.println(state);
  }
 if(state =='1')
 moveForward();
 else if(state=='2')
 moveBackward();
  else if(state=='3')
 turnRight();
else if(state=='4')
 turnLeft();

else
moveStop();
}
void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){


    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  
}

void moveBackward(){

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





//void setup() {
//  // put your setup code here, to run once:
//
//  pinMode(9,OUTPUT);
//  pinMode(10,OUTPUT);
//  Serial.begin(9600);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  char a='z';
//
//  if(Serial.available()>1)
//  {
//    a=Serial.read();
//    Serial.println(a);
//  }
//  
//    if(a=='1')
//{digitalWrite(9, LOW);
//digitalWrite(10, HIGH);
//}
//else if(a=='2')
//{digitalWrite(10, LOW);
//digitalWrite(9, HIGH);
//}
//else
//{digitalWrite(10, LOW);
//digitalWrite(9, LOW);
//}
//}

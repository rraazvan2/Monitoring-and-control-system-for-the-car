#include <Wire.h>
#include <AFMotor.h>
#include <Servo.h>
AF_DCMotor motor1(1, MOTOR34_64KHZ); // create motor #3, 64KHz pwm
AF_DCMotor motor2(2, MOTOR34_64KHZ); // create motor #3, 64KHz pwm
AF_DCMotor motor3(3, MOTOR34_64KHZ); // create motor #3, 64KHz pwm
AF_DCMotor motor4(4, MOTOR34_64KHZ); // create motor #3, 64KHz pwm
Servo name_servo;

int servo_position = 0;
int i = 0;

#define SLAVE_ADDR 9

#define R16IN16 38 
#define R16IN15 41
#define R16IN14 40
#define R16IN13 39
#define R16IN12 44
#define R16IN11 42
#define R16IN10 46
#define R16IN9  47
#define R16IN1 34
#define R16IN3 35
#define R16IN4 36
#define R16IN5 37
#define R16IN6 43
#define R16IN7 48
#define R16IN8 45

#define TR16IN1615 A6
#define TR16IN1413 A7
#define TR16IN1211 A9
#define TR16IN109  A8

#define ASV1 23
#define ISV1 27

#define ASV2 22
#define ISV2 24

#define ASV3 29
#define ISV3 26

#define ASV4 31
#define ISV4 28

#define ASV5 30
#define ISV5 36

#define ASV6 36
#define ISV6 34

#define ASV7 32

#define ASV8 33
#define ISV8 53

#define buzzer A10

int actiune;

void setup() {
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDR);
  Wire.onReceive(receiveEvent);

  pinMode(TR16IN1615, OUTPUT);
  pinMode(TR16IN1413, OUTPUT);
  pinMode(TR16IN1211, OUTPUT);
  pinMode(TR16IN109, OUTPUT);

  pinMode(R16IN16, OUTPUT);
  pinMode(R16IN15, OUTPUT);
  pinMode(R16IN14, OUTPUT);
  pinMode(R16IN13, OUTPUT);
  pinMode(R16IN12, OUTPUT);
  pinMode(R16IN11, OUTPUT);
  pinMode(R16IN10, OUTPUT);
  pinMode(R16IN9, OUTPUT);
  pinMode(R16IN8, OUTPUT);
  pinMode(R16IN7, OUTPUT);
  pinMode(R16IN6, OUTPUT);
  pinMode(R16IN5, OUTPUT);
  pinMode(R16IN4, OUTPUT);
  pinMode(R16IN3, OUTPUT);
  pinMode(R16IN1, OUTPUT);

  pinMode(ASV1, OUTPUT);
  pinMode(ASV2, OUTPUT);
  pinMode(ASV3, OUTPUT);
  pinMode(ASV4, OUTPUT);
  pinMode(ASV5, OUTPUT);
  pinMode(ASV6, OUTPUT);
  pinMode(ASV7, OUTPUT);
  pinMode(ASV8, OUTPUT);

  pinMode(ISV1, INPUT);
  pinMode(ISV2, INPUT);
  pinMode(ISV3, INPUT);
  pinMode(ISV4, INPUT);
  pinMode(ISV5, INPUT);
  pinMode(ISV6, INPUT);
  pinMode(ISV8, INPUT);

  pinMode(buzzer, OUTPUT);

  name_servo.attach(10);
  //name_servo.writeMicroseconds(1500);

  
}

void receiveEvent(){
  actiune = Wire.read();
  Serial.println(actiune);
}

void loop() {
  switch (actiune){
    case 0:

  digitalWrite(R16IN16, HIGH);
  digitalWrite(R16IN15, HIGH);
  digitalWrite(R16IN14, HIGH);
  digitalWrite(R16IN13, HIGH);
  digitalWrite(R16IN12, HIGH);
  digitalWrite(R16IN11, HIGH);
  digitalWrite(R16IN10, HIGH);
  digitalWrite(R16IN9, HIGH);
  digitalWrite(R16IN8, HIGH);
  digitalWrite(R16IN7, HIGH);
  digitalWrite(R16IN6, HIGH);
  digitalWrite(R16IN5, HIGH);
  digitalWrite(R16IN4, HIGH);
  digitalWrite(R16IN3, HIGH);
  digitalWrite(R16IN1, HIGH);
 
  
    break;

    case 1:
   
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  //Motor1
  motor1.run(FORWARD);
  delay(1000);
  motor1.run(RELEASE);
  delay(500);
  //Motor2
  motor2.run(FORWARD);
  delay(1000);
  motor2.run(RELEASE);
  delay(500);
  //Motor3
  motor3.run(FORWARD);
  delay(1000);
  motor3.run(RELEASE);
  delay(500);
  //Motor4
  motor4.run(BACKWARD);
  delay(1000);
  motor4.run(RELEASE);
  
  digitalWrite(ASV1, HIGH);
  digitalWrite(ASV2, HIGH);
  digitalWrite(ASV3, HIGH);
  digitalWrite(ASV4, HIGH);
  digitalWrite(ASV5, HIGH);
  digitalWrite(ASV6, HIGH);
  digitalWrite(ASV7, HIGH);
  digitalWrite(ASV8, HIGH);
  digitalWrite(R16IN7, HIGH);
  digitalWrite(R16IN8, HIGH);

    break;

    case 2:
    
  digitalWrite(ASV1, LOW);
  digitalWrite(ASV2, LOW);
  digitalWrite(ASV3, LOW);
  digitalWrite(ASV4, LOW);
  digitalWrite(ASV5, LOW);
  digitalWrite(ASV6, LOW);
  digitalWrite(ASV7, LOW);
  digitalWrite(ASV8, LOW);
  digitalWrite(R16IN7, LOW);
  digitalWrite(R16IN8, LOW);

  noTone(buzzer);

  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  //Motor1
  motor1.run(BACKWARD);
  delay(1000);
  motor1.run(RELEASE);
  //Motor2
  motor2.run(BACKWARD);
  delay(1000);
  motor2.run(RELEASE);
  //Motor3
  motor3.run(BACKWARD);
  delay(1000);
  motor3.run(RELEASE);
  //Motor4
  motor4.run(FORWARD);
  delay(1000);
  motor4.run(RELEASE);
  
    break;

  case 5: 

  digitalWrite(R16IN14, LOW);
  digitalWrite(R16IN13, LOW);
  digitalWrite(TR16IN1615, 100);
  digitalWrite(R16IN16, HIGH);
  digitalWrite(R16IN15, HIGH);
  
  break;

  case 6: 
  
  digitalWrite(R16IN16, LOW);
  digitalWrite(R16IN15, LOW);
  digitalWrite(TR16IN1413, 100);
  digitalWrite(R16IN14, HIGH);
  digitalWrite(R16IN13, HIGH);

  break;

  case 7: 
  
  digitalWrite(R16IN12, LOW);
  digitalWrite(R16IN11, LOW);
  digitalWrite(TR16IN1211, 255);
  digitalWrite(R16IN10, HIGH);
  digitalWrite(R16IN9, HIGH);

  break;

  case 8: 

  digitalWrite(R16IN10, LOW);
  digitalWrite(R16IN9, LOW);
  digitalWrite(TR16IN109, 255);
  digitalWrite(R16IN12, HIGH);
  digitalWrite(R16IN11, HIGH);

  break;

  case 9:

  digitalWrite(R16IN16, LOW);
  digitalWrite(R16IN15, LOW);
  digitalWrite(R16IN12, LOW);
  digitalWrite(R16IN11, LOW);

  digitalWrite(R16IN14, HIGH);
  digitalWrite(R16IN13, HIGH);
  digitalWrite(R16IN10, HIGH);
  digitalWrite(R16IN9, HIGH);

  break;

  case 10: 

  digitalWrite(R16IN14, LOW);
  digitalWrite(R16IN13, LOW);
  digitalWrite(R16IN10, LOW);
  digitalWrite(R16IN9, LOW);

  digitalWrite(R16IN16, HIGH);
  digitalWrite(R16IN15, HIGH);
  digitalWrite(R16IN12, HIGH);
  digitalWrite(R16IN11, HIGH);

  break;

  case 11: 

  digitalWrite(R16IN6, LOW);

  break;
  
  case 12:

  digitalWrite(R16IN6, HIGH);

  break;

  case 13: 

  
digitalWrite(R16IN7, LOW);
  digitalWrite(R16IN8, LOW);
  break;

  case 14: 

  
  digitalWrite(R16IN7, HIGH);
  digitalWrite(R16IN8, HIGH);

  break;

  case 15: 

  digitalWrite(ASV1, LOW);
  digitalWrite(ASV2, LOW);
  digitalWrite(ASV3, LOW);
  digitalWrite(ASV4, LOW);
  digitalWrite(ASV5, LOW);
  digitalWrite(ASV6, LOW);
  digitalWrite(ASV7, LOW);
  digitalWrite(ASV8, LOW);

  noTone(buzzer);
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  //Motor1
  motor1.run(FORWARD);
  delay(400);
  motor1.run(RELEASE);
  delay(1000);
  //Motor2
  motor2.run(FORWARD);
  delay(400);
  motor2.run(RELEASE);
  delay(1000);
  //Motor3
  motor3.run(FORWARD);
  delay(400);
  motor3.run(RELEASE);
  delay(1000);
  //Motor4
  motor4.run(FORWARD);
  delay(400);
  motor4.run(RELEASE);

  break;

  case 160:

  digitalWrite(R16IN16, HIGH);
  digitalWrite(R16IN15, HIGH);
  digitalWrite(R16IN14, HIGH);
  digitalWrite(R16IN13, HIGH);
  digitalWrite(R16IN12, HIGH);
  digitalWrite(R16IN11, HIGH);
  digitalWrite(R16IN10, HIGH);

  break;

  
  }
if (actiune == 3){
  
  for (servo_position=110; servo_position >= 0; servo_position -=1){


   name_servo.write(servo_position);  
    delay(10);

  }

}


if (actiune == 4) {
     
 for (servo_position = 0; servo_position <=110; servo_position +=1){

    name_servo.write(servo_position);
    delay(1);
 
  }
  }

  long measurement =  vibration();
  long measurement1 = vibration();
  long measurement2 = vibration();
  long measurement3 = vibration();
  long measurement4 = vibration();
  long measurement5 = vibration();
  long measurement6 = vibration();

  if (measurement > 50){

  tone(buzzer, 1000);

 
  }
   if (measurement1 > 50){

  tone(buzzer, 1000);


  }
   if (measurement2 > 50){

  tone(buzzer, 1000);

  }
   if (measurement3 > 50){

  tone(buzzer, 1000);

  }
   if (measurement4 > 50){

  tone(buzzer, 1000);

  }
   if (measurement5 > 50){

  tone(buzzer, 1000);

  }
   if (measurement6 > 50){

  tone(buzzer, 1000);

  }

}
long vibration() {

  long measurement = pulseIn (ISV1, HIGH);
  return measurement;

  long measurement1 = pulseIn (ISV2, HIGH);
  return measurement1;

  long measurement2 = pulseIn (ISV3, HIGH);
  return measurement2;

  long measurement3 = pulseIn (ISV4, HIGH);
  return measurement3;

  long measurement4 = pulseIn (ISV5, HIGH);
  return measurement4;

  long measurement5 = pulseIn (ISV6, HIGH);
  return measurement5;

  long measurement6 = pulseIn (ISV8, HIGH);
  return measurement6;
  
}

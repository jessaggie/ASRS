#include <Encoder.h>
#include <Wire.h>
#define MOTOR_IN1 9
#define MOTOR_IN2 10
Encoder myEnc(2, 3);

void setup() {
  Serial.begin(9600);

  Serial.println("forwards");
  
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
}

void loop() {

//    double newPos = myEnc.read();   //reads from encoder
//    Serial.println((newPos/1440)*64.246);   //prints encoder readings converted to mm traveled

  analogWrite(MOTOR_IN1, 255);   //straight forward
  digitalWrite(MOTOR_IN2, LOW);   ////straight forward

  //methods of movement
  //you can use both analog write or digital write. 
  //analog write is a pwm signal and is driven with the command:
  //  analogWrite(MOTOR_IN(insert motor number here), (range from 0 to 255));  
  //255 is 100% while 0 is 0%
  //digital write can also be used with the command:
  //digitalWrite(MOTOR_IN(insert motor number here), (1 or 0 or HIGH or LOW));


  
}

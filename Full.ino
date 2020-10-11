#include <Encoder.h>            //initializes
#include <Wire.h>               //initializes
#include <Adafruit_INA219.h>    //initializes

Adafruit_INA219 ina219;         //initializes

#define MOTOR_IN1 9             //initializes
#define MOTOR_IN2 10            //initializes

Encoder myEnc(2, 3);          //function call

void setup() {          //setup: do not touch and do not delete
   Serial.begin(9600);    //sets baud rate to 9600
    while (!Serial) {delay(1);}     //setup for current sensor
   uint32_t currentFrequency;
  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }}
  pinMode(MOTOR_IN1, OUTPUT);       //sets motor declaration method
  pinMode(MOTOR_IN2, OUTPUT);   
  Serial.println("Do not forget to set the current threshold. Run the debug to find value when resistance is placed on pipe");

}

float highest = 0;              //debug variable for tracking the current
float boreDepth = 0;            //export varible to see bore depth
float currentThreshold = 2120;    //set this after debugging
void loop() {
  
  digitalWrite(MOTOR_IN2, LOW);     //sets in2 low (neccessary for fwd driving)
  analogWrite(MOTOR_IN1, 255);      //sets in1 high, and assings pwm value of 100%
  float current_mA = ina219.getCurrent_mA();




  ///debugging////////

  //see current display
//  Serial.println(current_mA);

      //find highest current values
//  if (abs(current_mA) > highest){
//    highest = abs(current_mA);}
//    Serial.println(highest);

    //find current values above 2100
//  if (abs(current_mA) >2100){
//     Serial.println("above 2100, : ");
//    Serial.println(abs(current_mA));
//  }
  //////////////////////
  

  
  double newPos = myEnc.read();   //reads from encoder
  double distanceTraveled = (newPos/1440)*64.246;  //distance traveled
//Divides by number of ticks and multiplies by the circumference of the pinion gear to get linear distance from 1 rotation. 
//    Serial.println(distanceTraveled);
if (distanceTraveled > boreDepth){    //record max bore depth 
    boreDepth = distanceTraveled;
//    Serial.println(boreDepth);
    }

  
  if (abs(current_mA) > currentThreshold){    //if current exceeds the threshold, the pipe has reached the end of the bore
    while (((myEnc.read())/1440*64.246)>0){   //While distance traveled is greater than 0
     
     digitalWrite(MOTOR_IN1, LOW);   //reverse, sets pin 1 low, 
     digitalWrite(MOTOR_IN2, HIGH);   //full reverse, sets pin 2 high
    
     Serial.print("The boreDepth is: ");    //displays bore depth
     Serial.print(boreDepth);
     Serial.println("mm"); }

      
     }}

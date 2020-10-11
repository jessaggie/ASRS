#define MOTOR_IN1 9
#define MOTOR_IN2 10

void setup() {
  Serial.begin(9600);
  
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(MOTOR_IN1, 1);   //straight forward
  digitalWrite(MOTOR_IN2, 1);   ////straight forward
  
  Serial.println("all is good, all is quiet");
  delay(2000);
  
  
}

#define MOTOR_IN1 9
#define MOTOR_IN2 10

void setup() {
  Serial.begin(9600);

  Serial.println("DRV8871 test");
  
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
}

void loop() {

  digitalWrite(MOTOR_IN1, 0);   //backwards
  digitalWrite(MOTOR_IN2, 1);   //backwards

  
  
}

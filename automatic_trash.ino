#include <Servo.h>   //servo library
Servo servo;   
int trigPin = 5;
int echoPin = 6;
int servoPin = 8;
int dist;
long duration;
void setup() {
  Serial.begin(9600);
  servo.attach(servoPin); 
  pinMode(4, OUTPUT);
  digitalWrite(4, 1);
  pinMode(7, OUTPUT);
  digitalWrite(7, 0);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {
  int distance = measure();
  Serial.println(distance);
  delay(500);
  if ( distance<20 ){
    servo.write(90);
    delay(5000);
    servo.write(0);
  }
  
  
}
int measure() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  dist = (duration / 2) / 29.1;  //obtain distance
  return dist;
}

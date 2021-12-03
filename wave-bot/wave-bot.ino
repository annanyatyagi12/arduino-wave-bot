#include <Servo.h>
Servo myservo; // create servo object to control a servo

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int i = 0;
int trigPin = 3;  
int echoPin = 2; 

void setup() {
  myservo.attach(9);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // Serial Communication is starting with 9600 of baudrate speed

}
void loop() {

    
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * (0.034 / 2); // Speed of sound wave divided by 2 (go and back)
  
  //Serial.println(duration);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  
  //myservo.write(90); //this needs to be after distance calculation
  
  //todo: make this go between 0 and 90
  
  if (distance < 10){
    for (i=0; i<=180; i++){
        //Serial.println(i);
        myservo.write(i);
        delay(5);
    	}
	}
    
  
}

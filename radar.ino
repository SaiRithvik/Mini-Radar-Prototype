#include <SharpIR.h>

// Includes the Servo library
#include <Servo.h>

// Defines Rad Pin 
//const int radPin = 11;
// Variables for the duration and the distance
long duration;
int dis;
Servo myServo; // Creates a servo object for controlling the servo motor
SharpIR sensor(SharpIR::GP2Y0A41SK0F, A0 );
void setup() {
  //pinMode(radPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(12); // Defines on which pin is the servo motor attached
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  dis = calculateDistance(); // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(dis); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
 for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  dis = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(dis);
  Serial.print(".");
  }
}
// Function for calculating the distance measured by the IR sensor
int calculateDistance(){ 
  dis = sensor.getDistance();
  return dis;
}

/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int servo_pin ;

bool isSweep = true;
char myData[10];

void setup() {
  
  Serial.begin(9600);
  // pin 2 = Lift servo
  // pin 3 = LEFT servo
  // pin 4 = RIGHT servo
  servo_pin = 3;
  myservo.attach(servo_pin);  // attaches the servo on pin 9 to the servo object
  myservo.write(180);
  
  Serial.println(" Servo loop sweep 0 - 180");
  delay(1000);
  
}

void loop() {
  
  byte n = Serial.available();
  if( n!= 0)
  {
    byte m = Serial.readBytesUntil('\n', myData, 10);//receive and save all charcaters except '\n'
    myData[m] = '\0'; //insert null character in the array at the end of the last character of the string
   // Serial.print(myData);  //show received string
    if( strcmp(myData , "1")== 1){
        isSweep = true;
       Serial.println("Servo loop sweep 0 - 180");
    }else{
         isSweep = false;
         myservo.write(180);
  
        Serial.println("STOP! Servo angle = 180");
        
    }
  }else{
  
  if( isSweep){
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  }
  }
}

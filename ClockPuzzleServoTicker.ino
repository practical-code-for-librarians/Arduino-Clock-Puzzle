/*  
  Simple example of using elapsedMillis library
  
  This example does othing more than blinking a LED... but the difference 
  here to just using delay(1000) to control the delay between blinks is that 
  you can do more in the loop - like get user input, check buttons, get sensor
  input and other tasks that take time - while you wait for the next time the 
  LED is to change state. All you need to do is add it before or after the 
  'if' statement that controls the check of the time elapsed. 
  
  This example code is in the public domain.
*/

#include <elapsedMillis.h>
#include <SoftwareSerial.h>
#include <Servo.h>
elapsedMillis timeElapsed; //declare global if you don't want it reset every time loop runs

// Pin 13 has an LED connected on most Arduino boards.
int led = 13;

// delay in milliseconds between blinks of the LED
unsigned int interval = 20;

// state of the LED = LOW is off, HIGH is on
boolean ledState = LOW;

int clockA = 5;          // Set these to the pin numbers you have attached the clock wires
int clockB = 6;          // to.  Order is not important.
 
int tickPin = clockA;    // This keeps track of which clock pin should be fired next.

int trigger=0;
SoftwareSerial SoftSerial(10, 11); // RX, TX
Servo servoDoor;

void setup() 
{                
  // initialize the digital pin as an output.
  //pinMode(led, OUTPUT);     
  Serial.begin(9600);
  SoftSerial.begin(9600);
  pinMode(clockA, OUTPUT);
  pinMode(clockB, OUTPUT);
 
  digitalWrite(clockA, LOW);
  digitalWrite(clockB, LOW);
  servoDoor.attach(9);
  turnRight(); 
}

void doTick() {
 
  // Energize the electromagnet in the correct direction.
  digitalWrite(tickPin, HIGH);
  delay(10);
  digitalWrite(tickPin, LOW);  
  
 
  // Switch the direction so it will fire in the opposite way next time.
  if (tickPin == clockA)
  {
    tickPin = clockB;
    //Serial.println("B");
  } else {
    tickPin = clockA;
    //Serial.println("A");
  }
} 

void turnRight() {
  servoDoor.write(180);
}
void turnLeft() {
  servoDoor.write(0);
}

void loop()
{

  

  if (SoftSerial.available()) {
    trigger = SoftSerial.read();
  }else{
    //Serial.println("NO RDY");
  }

 if (trigger==12) {
    Serial.println("servo open door");
    turnLeft();
    Serial.println("servo close door");
    delay(6000);
    turnRight();
    delay(1000);
  
 }
   
  if (timeElapsed > interval && trigger==123) 
  {				
      //ledState = !ledState;         // toggle the state from HIGH to LOW to HIGH to LOW ... 
      //digitalWrite(led, ledState);
      doTick();      
      timeElapsed = 0;              // reset the counter to 0 so the counting starts over...
  }
}

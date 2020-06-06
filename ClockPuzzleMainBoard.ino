#include <Servo.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

Servo myservo;
int pos = 0;

const int servoMinDegrees = 20; // the limits to servo movement
const int servoMaxDegrees = 150;
const int servoPin = 9; // the pin number for the servo signal
int servoPosition = 90;     // the current angle of the servo - starting at 90.
int servoSlowInterval = 100; // millisecs between servo moves
int servoFastInterval = 10;
int servoInterval = servoSlowInterval; // initial millisecs between servo moves
int servoDegrees = 2;       // amount servo moves at each step 
                            //    will be changed to negative value for movement in the other direction

unsigned long currentMillis = 0;    // stores the value of millis() in each iteration of loop()
unsigned long previousServoMillis = 0; // the time when the servo was last moved
const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
const int buttonPinGround = 13; 

SoftwareSerial SoftSerial(10, 11); // RX, TX
void setup() 
{ 
 Serial.begin(9600);
  SoftSerial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPinGround, OUTPUT);
  myservo.attach(9);
  //myservo.write(servoPosition);
  Serial.println("inital");
  digitalWrite(buttonPinGround, LOW);
  delay(500);  
  digitalWrite(buttonPinGround, HIGH);
  lcd.begin(20,4);
  //lcd.clear();
  //    lcd.setCursor(0,0); //Start at character 4 on line 0
  //    lcd.print("Penfield Library");
  //    lcd.setCursor(0,1);
  lcd.noBacklight();
  lcd.clear();
      lcd.setCursor(0,0); //Start at character 4 on line 0
      lcd.print("Penfield Library");
      lcd.setCursor(0,1);
      lcd.print("Clue:");
      lcd.setCursor(0,2);
      lcd.print("McCrobie");
      lcd.setCursor(0,3);
      lcd.print("Title");
} 

 



void loop() {

  //currentMillis = millis();

   buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
      
    
  } else {

      SoftSerial.write(123);
      Serial.println("servo");
      //servoSweep();
      Serial.println("MP3");
      digitalWrite(buttonPinGround, LOW);
      delay(500);      
      digitalWrite(buttonPinGround, HIGH);
      delay(10000);
      SoftSerial.write(12);
      lcd.backlight();    
      delay(5000);
      lcd.noBacklight();
      SoftSerial.write(1234);
       //myservo.write(90);
      //servoSweep();
  }
}



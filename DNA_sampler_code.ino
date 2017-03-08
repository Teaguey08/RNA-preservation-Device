#include <Wire.h>
#include <Adafruit_MotorShield.h> //include motor shield driver
#include "utility/Adafruit_PWMServoDriver.h" //include servo driver
#include <Servo.h> //include servo

int buttonPin1 = 8 ;// button 1 is linked to pin 9
int pos = 0; // start servo in position 0

bool runState = false; //start in eything off i.e: no buttons pushed

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Select which 'port' M1, M2, M3 or M4. So include motors you want
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
Adafruit_DCMotor *myotherMotor = AFMS.getMotor(2);
Servo myservo; //adds servo 

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");
  pinMode (buttonPin1, INPUT_PULLUP);
  myservo.attach(10); //servo is connected to Pin 10

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  myMotor->setSpeed(90); // set speed in % 
  myotherMotor->setSpeed(90); // set speed in % 
  myMotor->run(FORWARD); // turn on motor
  myMotor->run(RELEASE);// turn off motor
}

void loop() {
  if (digitalRead(buttonPin1) == HIGH)   //if start button is not pressed
  {
    runState = false;      //Do not run stepper
  }
  
  if (digitalRead(buttonPin1) == LOW)   //if start button is pressed
  {
    runState = true;    //start running stepper
  }
  
  if (runState)  //if Button 1 is pushed start running
  {
    myMotor->run(FORWARD); 
    myMotor->setSpeed(100);
    delay (30000);            //Pause 30000 m/s *(30 seconds)
    myMotor->run(RELEASE);
    delay (10);              //Pause 10 m/s
    for (pos = 180; pos >= 0; pos -= 1)  // goes from 180 degrees to 0 degrees
    myservo.write(pos);               // tell servo to go to position in variable 'pos'
    delay(15);  
    myotherMotor->run(FORWARD);
    myotherMotor->setSpeed(100);
    delay (10000);                //Pause 10000 m/s *(10 seconds)
    myotherMotor->run(RELEASE);
    delay (1000);
  }
}
 

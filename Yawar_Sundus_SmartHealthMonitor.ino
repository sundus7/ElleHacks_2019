#include <Servo.h>
Servo motor
int val;
byte userinput;
long i =0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(15);
  motor.attach(9);//attaches the servo on pin 9
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() == 0){}
  Serial.print("Please enter the UV index: \n");
  i = Serial.parseInt();
  if (i > 3){
    Serial.print("Opening the curtains\n");
    motor.write(180);
    delay(15000); //simulating 15 minutes of sunslight its not 15 minutes for the demo ofcourse
    motor.write(0);
  }
  else if(i<3)Serial.print("Closing the curtains\n");
}

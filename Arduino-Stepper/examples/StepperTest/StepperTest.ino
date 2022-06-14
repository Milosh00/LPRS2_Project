// Adafruit Motor shield library

#include <AFMotor.h>

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor1(200, 1);
AF_Stepper motor2(200, 2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  motor1.setSpeed(10);  			    // 10 rpm 
  motor2.setSpeed(10);  			    // 10 rpm   
}

void loop() {

  Serial.println("Single coil steps");
  for(int i=0; i<10; i++)
  {
    motor1.onestep(FORWARD, SINGLE);
    motor2.onestep(FORWARD, SINGLE);
    delay(500);
  }

  delay(1000);

  Serial.println("Interleave coil steps");
  for(int i=0; i<10; i++)
  {
    motor1.onestep(BACKWARD, INTERLEAVE);
    motor2.onestep(BACKWARD, INTERLEAVE);
    delay(500);
  }
  delay(2000);
}

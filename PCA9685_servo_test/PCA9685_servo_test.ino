#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();



#define SERVOMIN  300 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  300 // This is the 'maximum' pulse length count (out of 4096)

#define SERVO_FREQ 10 // Analog servos run at ~50 Hz updates


uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  pwm.setPWM(0,0,90);
  delay(100);
}

void loop(){
  pwm.setPWM(0,5,1);
  delay(2000);
  pwm.setPWM(0,1,5);
  delay(2000);
  /*pwm.setPWM(2,90,95);
  delay(2000);
  pwm.setPWM(3,95,90);
  delay(2000);
  pwm.setPWM(4,95,90);
  delay(2000);

  pwm.setPWM(0,95,90);
  delay(2000);
  pwm.setPWM(1,95,90);
  delay(2000);
  pwm.setPWM(2,95,90);
  delay(2000);
  pwm.setPWM(3,90,95);
  delay(2000);
  pwm.setPWM(4,90,95);
  delay(2000);*/
}

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

const int flexPin = A0;
int flexvalue;
int servoposition;

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)

#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates


void setup() {
  Serial.begin(115200);
  Serial.println("8 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
}

void loop(){
  flexvalue = analogRead(flexPin);         //Read and save analog value from potentiometer
  
  Serial.println(flexvalue);
  
  if (flexvalue < 1021) {
    pwm.setPWM(0,0,300);
    delay(100);
  } else {
    pwm.setPWM(0,0,600);
    delay(100);
  }
  delay(1000);
}

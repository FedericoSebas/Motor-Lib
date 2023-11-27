#include <Arduino.h>
#include "Motor.h"

int curveToPwm(double curve, int maxSpeed) {
  // Map the curve value (-1 to 1) to the PWM range (maxSpeed to 0)
  return round(abs(curve) * maxSpeed);
}

void Motor::forward(){
  ledcWrite(pwmChannel_1,speed);
  ledcWrite(pwmChannel_2,0);
}
void Motor::backward(){
  ledcWrite(pwmChannel_1,0);
  ledcWrite(pwmChannel_2,speed);
}

void Motor::stop(){
  ledcWrite(pwmChannel_1,0);
  ledcWrite(pwmChannel_2,0);
}

void Motors::Left(){
  left.backward();
  right.forward();
}
void Motors::Right(){
  left.forward();
  right.backward();
}
void Motors::Forward(){
  left.forward();
  right.forward();
}
void Motors::Backward(){
  left.backward();
  right.backward();
}
void Motors::Stop(){
  left.stop();
  right.stop();
}
}

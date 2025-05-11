#ifndef SERVO_CONTROL_H_
#define SERVO_CONTROL_H_

#define SERVO_PIN           BIT1           // Using P2.1 for servo control

void servoInit(void);
void servoPWMInit(void);
void servo_set(int angle);

#endif /* SERVO_CONTROL_H_ */

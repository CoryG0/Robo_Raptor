//Code By Bob Davis
//Cory Final

//b = walk backwards
//f = walk forward
//h = raise head
//l = lower head
//w = wiggle tail
//r = roar sound
//m = open mouth
//n = wiggle neck

#include <AFMotor.h>
#include <Servo.h>
// create servo object to control a servo
Servo myservo;
// mororr moves the right leg
// create motor #2, 64KHz pwmf

AF_DCMotor motorr(2, MOTOR12_64KHZ);
// motorl moves the left leg
// create motor #4, 64KHz pwm
AF_DCMotor motorl(4, MOTOR12_64KHZ);
// motorw wiggles the tail, head moves too
// create motor #1, 64KHz pwmb
AF_DCMotor motorw(1, MOTOR12_64KHZ);
// motorh moves the head up and down
// create motor #3, 64KHz pwm
AF_DCMotor motorh(3, MOTOR12_64KHZ);
char INBYTE;
// Set A6 as an output pin for speaker
int SpkrPin = 19;
//Set A5 as neck motor output
int motorn = 18;
int roar;

void setup() {
  motorr.setSpeed(255);     // set the speed to 255/255
  motorl.setSpeed(255);     // set the speed to 255/255
  motorw.setSpeed(255);     // set the speed to 255/255
  motorh.setSpeed(255);     // set the speed to 255/255
  Serial.begin(9600);
  pinMode(SpkrPin, OUTPUT);
  pinMode(motorn, OUTPUT);
  // The servo is on pin 9
  myservo.attach(9);
}

void loop() {
  INBYTE = 0;
  if (Serial.available() > 0) {
    INBYTE = Serial.read();
    Serial.println(INBYTE);
  }
    
  if (INBYTE == 'f') {
    //walk straight forward
    motorw.run(BACKWARD);     // wiggle left
    delay(300);  // pause
    motorr.run(FORWARD);     // right foot forward
    delay(100);  // pause
    motorw.run(FORWARD);     // wiggle right
    delay(100);  // pause
    motorr.run(BACKWARD);    // right foot backward
    delay(100);  // pause
    motorr.run(RELEASE);     // stop right foot
    motorl.run(FORWARD);     // left foot forward
    delay(100);  // pause
    motorw.run(BACKWARD);    // wiggle left
    delay(100);  // pause
    motorl.run(BACKWARD);    // left foot backward
    delay(100);  // pause
    motorl.run(RELEASE);     // stop left foot
    motorr.run(FORWARD);     // right foot forward
    delay(100);  // pause
    motorw.run(FORWARD);     // wiggle right
    delay(100);  // pause
    motorr.run(BACKWARD);    // right foot backward
    delay(100);  // pause
    motorr.run(RELEASE);     // stop right foot
    motorl.run(FORWARD);     // left foot forward
    delay(100);  // pause
    motorw.run(BACKWARD);    // wiggle left
    delay(100);  // pause
    motorl.run(BACKWARD);    // left foot backward
    delay(100);  // pause
    motorl.run(RELEASE);     // stop left foot
    motorw.run(RELEASE);     // stopped
    delay(300);
  }

  if (INBYTE == 'b') {
    // walk straight backward
    motorr.run(FORWARD);     // right foot forward
    delay(100);  // pause
    motorw.run(BACKWARD);     // wiggle left
    delay(100);  // pause
    motorr.run(BACKWARD);    // right foot backward
    delay(100);  // pause
    motorr.run(RELEASE);     // stop right foot
    motorl.run(FORWARD);     // left foot forward
    delay(100);  // pause
    motorw.run(FORWARD);     // wiggle right
    delay(100);  // pause
    motorl.run(BACKWARD);    // left foot backward
    delay(100);  // pause
    motorl.run(RELEASE);     // stop left foot
    motorr.run(FORWARD);     // right foot forward
    delay(100);  // pause
    motorw.run(BACKWARD);     // wiggle left
    delay(100);  // pause
    motorr.run(BACKWARD);    // right foot backward
    delay(100);  // pause
    motorr.run(RELEASE);     // stop right foot
    motorl.run(FORWARD);     // left foot forward
    delay(100);  // pause
    motorw.run(FORWARD);     // wiggle right
    delay(100);  // pause
    motorl.run(BACKWARD);    // left foot backward
    delay(300);  // pause
    motorl.run(RELEASE);     // stop left foot
    motorw.run(RELEASE);     // stopped
    delay(300);
  }

  if (INBYTE == 'h') {
    //raise head
    motorh.run(FORWARD);     // raise head
    delay(800);
   // motorh.run(RELEASE);     // stopped
   // delay(300);
  }
  
  if (INBYTE == 'l') {
    //lower head
    motorh.run(BACKWARD);     // raise head
    delay(300);
    //motorh.run(RELEASE);     // stopped
    //delay(300);
  }

  if (INBYTE == 'w') {
    //wiggle tail
    motorw.run(FORWARD);     // wiggle right
    delay(300);
    motorw.run(RELEASE);     // stopped
    delay(300);
    motorw.run(BACKWARD);     // wiggle left
    delay(300);
    motorw.run(RELEASE);     // stopped
    delay(300);
  }

  if (INBYTE == 'r') {
    // roar
    for (roar = 200; roar > 0; roar--) {
      digitalWrite(SpkrPin, HIGH);   // sets the speaker on
      delay(random(10));        // waits for a fraction of a second
      digitalWrite(SpkrPin, LOW);    // sets the speaker off
      delay(random(10));        // waits for a fraction of a second
    }
  }
}


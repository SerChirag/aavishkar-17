#include <NewPing.h>
#define TRIGGER_PIN  53   // Arduino pin 2 tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     51   // Arduino pin 3 tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 150 // Maximum distance we want to ping for
//mASTER is 12
unsigned long state = 0;
//int buttonState = 0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  //pinMode(8, OUTPUT);
  //pinMode(11, OUTPUT);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
  //Serial.begin(9600);
  //digitalWrite(8,LOW);
  //digitalWrite(11,HIGH);
}
void loop() {
/* if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
}*/
//unsigned long a = 65999;
 // Reading the button
 int cm = sonar.ping_cm();
 Serial.println(cm);
delay(100);
/*Serial.println(state);
Serial.write(a); // Sends '1' to the master to turn on LED
delay(100);
for(int i = 1; i <= 255; i++){
  Serial.write(i);
  delay(100);
}*/
}

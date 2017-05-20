#include <string.h>
#include "config.h"
#include "sonars.h"
#include "functions.h"
void setup() {
   pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  analogWrite(A0, 0);
  pinMode(pwmlf ,OUTPUT);
  pinMode(pwmlb ,OUTPUT);
  pinMode(pwmrf ,OUTPUT);
  pinMode(pwmrb ,OUTPUT);
  pinMode(lf1 ,OUTPUT);
  pinMode(lf2 ,OUTPUT);
  pinMode(lb1 ,OUTPUT);
  pinMode(lb2 ,OUTPUT);
  pinMode(rf1 ,OUTPUT);
  pinMode(rf2 ,OUTPUT);
  pinMode(rb1 ,OUTPUT);
  pinMode(rb2 ,OUTPUT);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}
int readremote();
void collision_prevent(){
    timefix();
    int situation;
  if (forward>0)  situation = frontCheck();
  else if (forward<0) situation = backCheck();
  if (situation==0) {Serial.println("Braking...");Steer(-40,0);return;}
  //else if (situation==1) {Serial.println("Slowing down...");/*Steer(-30,0);*/return;}
  Steer(forward, turn);
  }

void loop() {
  unsigned long start = millis();
  int state = readremote();
  switch (state){
      //case 0:parking_assistant();break;
      case 1:collision_prevent();break;
      case 2:Serial.println("car at REST"); Steer(0,0);break;
    }
  unsigned long now = millis();
  for(unsigned long i =0; i<((now - start)/40); i++)
    {Serial.print("CLEARING BUFFER ");Serial.println(i);
      if(Serial.available()>0){
        char c = Serial.read();
        while(c!='\n') if(Serial.available()>0)c=Serial.read();
      }
    }
}
int readremote()
{
  if (Serial.available() > 0){ // Checks whether data is comming from the remote
      char c = Serial.read(); // Reads the data from the serial port
      if(c!='\n') data += c;//accept input
      else if (c=='\n'){
        unsigned long remote = data.toInt();
        
        data = "";
        turn = remote % 1000;
        remote = remote / 1000;
        remote%10 == 1? turn = turn * -1 : turn = turn;
        remote = remote/10;
        /************************
        turning = turn;
        /*************************/
        forward = remote % 1000;
        remote = remote / 1000;
        remote%10 == 1? forward = forward * -1 : forward = forward;
        remote = remote/10;
        parkingstate = remote;
        Serial.print("f: ");
  Serial.print(forward);
  Serial.print(" t: ");
  Serial.print(turn);
  Serial.print(" p: ");
  Serial.println(parkingstate);
      }
  }
if (parkingstate == 1) return 0;
else if(forward!=0) return 1;
return 2;
} 


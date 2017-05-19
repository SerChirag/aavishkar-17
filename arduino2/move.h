#include <string.h>


int forward=0, turn=0, left=0, right=0, powl=0, powr=0;
String data ;
void setupMove() {
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


void Steer( int forward, int turn)
{
  if (forward>=0){
  left = forward + turn;
  left = constrain(left, -100, 100);
  right = forward - turn;
  right = constrain(right, -100, 100);
  }
  else{
   left =  forward - turn;
  left = constrain(left, -100, 100);
  right = forward + turn;
  right = constrain(right, -100, 100);
  
  }

  if(left>=0)powl = map(left, 0, 100, 0, 255);
  else powl = map(left, -100, 0, 255, 0);
  analogWrite(pwmlf, powl);
  analogWrite(pwmlb, powl);
  if(left>=0){
  digitalWrite(lf1, HIGH);
  digitalWrite(lf2, LOW);
  digitalWrite(lb1, HIGH);
  digitalWrite(lb2, LOW);
  }
  else{
  digitalWrite(lf1, LOW);
  digitalWrite(lf2, HIGH);
  digitalWrite(lb1, LOW);
  digitalWrite(lb2, HIGH);
  }
  if(right>=0)powr = map(right, 0, 100, 0, 255);
  else powr = map(right, -100, 0, 255, 0);
  analogWrite(pwmrf, powr);
  analogWrite(pwmrb, powr);
  if(right>=0){
  digitalWrite(rf1, HIGH);
  digitalWrite(rf2, LOW);
  digitalWrite(rb1, HIGH);
  digitalWrite(rb2, LOW);
  }
  else{
  digitalWrite(rf1, LOW);
  digitalWrite(rf2, HIGH);
  digitalWrite(rb1, LOW);
  digitalWrite(rb2, HIGH);
  }
  /*Serial.print("f: ");
  Serial.print(forward);
  Serial.print(" t: ");
  Serial.print(turn);
  Serial.print("  l: ");
  Serial.print(left);
  Serial.print(" r: ");
  Serial.print(right);
  */
}


void movementProcess() {

//state = 0;
 if (Serial.available() > 0){ // Checks whether data is comming from the serial port
   // while(Serial.available() >0){
      char c = Serial.read(); // Reads the data from the serial port
      //Serial.print(c);
      if(c!='\n') data += c;
      else if (c=='\n'){
        unsigned long remote = data.toInt();
        
        data = "";
        int turn = remote % 1000;
        remote = remote / 1000;
        remote%10 == 1? turn = turn * -1 : turn = turn;
        remote = remote/10;
        /*************************/
        turning = turn;
        /*************************/
        //Serial.print("r:");
        //Serial.print(remote);
        int forward = remote % 1000;
        remote = remote / 1000;
        remote%10 == 1? forward = forward * -1 : forward = forward;
        remote = remote/10;
        parking = remote;
        /**************************/
        //parking = parkingstate;
        /**************************/
        Steer( forward, turn);
        if(parking != 1 && forward != 0)
        {
          active = false;
        }
        else active = true;
      }
  }
 }



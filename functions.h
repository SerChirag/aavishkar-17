void Steer(int forward, int turn)
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
  Serial.print(" p: ");
  Serial.println(parkingstate);*/
}

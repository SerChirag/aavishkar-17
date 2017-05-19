int mq3_analogPin = A0; // connected to the output pin of MQ3 

void setupAlcohol()
{
  pinMode(mq3_analogPin,INPUT);
  //Serial.begin(9600); // open serial at 9600 bps
}

int alcohol()
{
  // give ample warmup time for readings to stabilize

  int mq3_value = analogRead(mq3_analogPin);
  Serial.println(mq3_value);
  if(mq3_value > 250)
  {
    return 1;
  }
  else
  {
    return 0;
  }

  delay(100); //Just here to slow down the output.
}

#include<SoftwareSerial.h>

SoftwareSerial sms(7,8);
int i;
void setup() {
  // put your setup code here, to run once:
  sms.begin(9600);
  delay(100);
  Serial.begin(9600);
i = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (i == 1) {
  sms.write("AT+CMGF=1\r\n");
  delay(100);
  sms.write("AT+CMGS=\"+918894041783\"\r\n");
  delay(100);
  sms.write("Stay Alert! Best wishes, ACS Lab, IIT Mandi ");
  delay(100);
  sms.write((char)26);
  delay(100);
  i++;
  }
}

#include "config.h"
#include "sms.h"
#include "alcohol.h"
#include "gyro.h"
#include "seven.h"
#include "gear.h"
#include "BCD.h"
#include "move.h"
#include "functions.h"


  void setup() 
  {
//    setupSonar();
    setupMove();
    setupGyro();
    setupSeven();
    setupAlcohol();
    setupGSM();
    setupBeep();
  }

  int count = 0;
  
  void loop() 
  {
      /*updateGyro();
      if(alcohol())
      {
          beep(1);
      }
      else
      {*/
         unsigned long int t1 = millis(),t2;
         if(!BCDloop())
          {
              Serial.println("collision is imminent");
              brake();
              count =0;
              t2 = millis() - t1;
          }
          else
          {
            while (Serial.available() && Serial.read());
            t2 = millis() - t1;
            for(int i=0 ; i<(count==0?10:5) ; i++)
            {
              movementProcess();
              delay(10);
            }
            count++;
          }
          Serial.println(t2);
          
     // }

    /* BCDloop();
     delay(50);*/
  }

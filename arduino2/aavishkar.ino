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
  
  void loop() 
  {
      /*updateGyro();
      if(alcohol())
      {
          beep(1);
      }
      else
      {*/
         if(!BCDloop())
          {
              Serial.println("collision is imminent");
              brake();
          }
          else
          {
            movementProcess();
          }
     // }

    /* BCDloop();
     delay(50);*/
  }

  
  /*
   *            C
   *         _________
   *        |         |       
   *      B |         | D
   *        |    A    |
   *         _________
   *        |         |
   *      E |         | G
   *        |         |
   *         _________  
   *            F      *p
   */

   int ledA = 31; //g
   int ledB = 33; //f
   int ledC = 35; //a
   int ledD = 37; //b
   
   int ledE = 39; //e
   int ledF = 41; //d
   int ledG = 43; //c
   int ledP = 45; //p

   int segmentVal = 0;

  void setupSeven()
  {
    pinMode(ledA , OUTPUT);
    pinMode(ledB , OUTPUT);
    pinMode(ledC , OUTPUT);
    pinMode(ledD , OUTPUT);
    pinMode(ledE , OUTPUT);
    pinMode(ledF , OUTPUT);
    pinMode(ledG , OUTPUT);
    pinMode(ledP , OUTPUT);
    //Serial.begin(115200);
  }
  void ini()
  {
      digitalWrite( ledA , HIGH );
      digitalWrite( ledB , HIGH );
      digitalWrite( ledC , HIGH );
      digitalWrite( ledD , HIGH );
      digitalWrite( ledE , HIGH );
      digitalWrite( ledF , HIGH );
      digitalWrite( ledG , HIGH );
      digitalWrite( ledP , HIGH );
  }

  /*void loop()
  {
    ini();
    //digitalWrite( ledG , LOW );
    for(int i = 0; i<10 ; i++)
    {
      sevenSegment(i);
      delay(1000);
      ini();
    }
  }
  */
  
  void sevenSegment(int n)
    {
        switch(n)
        {
          case 1 : digitalWrite( ledD , segmentVal );
                   digitalWrite( ledG , segmentVal );
                   break;
          case 2 : digitalWrite( ledA , segmentVal );
                   digitalWrite( ledC , segmentVal );
                   digitalWrite( ledD , segmentVal );
                   digitalWrite( ledE , segmentVal );
                   digitalWrite( ledF , segmentVal );
                   break;
          case 3 : digitalWrite( ledA , segmentVal );
                   digitalWrite( ledC , segmentVal );
                   digitalWrite( ledD , segmentVal );
                   digitalWrite( ledF , segmentVal );
                   digitalWrite( ledG , segmentVal );
                   break;
          case 4 : digitalWrite( ledA , segmentVal );
                   digitalWrite( ledB , segmentVal );
                   digitalWrite( ledD , segmentVal );
                   digitalWrite( ledG , segmentVal );
                   break;
          case -1: digitalWrite( ledP , segmentVal );
                   break;  
        }
    }


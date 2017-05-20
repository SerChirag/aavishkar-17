#include <NewPing.h>

unsigned long currentMillis = 0, prevMillis = 0, deltaTime = 0;
float RVSThreshold = 20.0;
const int frontThreshold =60 , frontMax = 100;
const int backThreshold = 8, backMax = 20;
//NewPing s1(12, 11, 100);
NewPing s2(29, 25, frontMax);
//NewPing s3(10, 9, 100);
//NewPing s4(10,9, 100);
//NewPing s5(A12, A5, 100);
NewPing s6(A2, A3, backMax);
//NewPing s7(A9, A8, 100);
//NewPing s8(12, 11, 100);
float sonar2Prev = 0, sonar2=0;
float getRV(float d, float dPrev)
{
  if(d == 100 || dPrev == 100) return 0;
  else return (dPrev - d) * 1000/deltaTime;
}
void timefix()
{prevMillis = currentMillis;
  currentMillis = millis();
  deltaTime = currentMillis - prevMillis;
}

int frontCheck(){
  sonar2Prev = sonar2;
  sonar2 = s2.ping_cm();
  if(sonar2 == 0) sonar2 = frontMax;
  
  if(sonar2 < frontMax)
  {
    if(sonar2 < frontThreshold) return 0;
    else{
      float rv = getRV(sonar2, sonar2Prev);
      if(rv > RVSThreshold)return 1;
    }
  }
  return 2;
}

  
  

int backCheck() {return 2;}


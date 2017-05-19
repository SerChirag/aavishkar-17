

/*******************
 * move.h
 */

int pwmlf=3;
int lf1=26;
int lf2=28;

int pwmlb=4;
int lb1=22;
int lb2=24;

int pwmrf=6;
int rf1=48;
int rf2=50;

int pwmrb=5;
int rb1=46;
int rb2=44;
/*********************/


/*********************/
//GYRO

  int gyroVal[10];
  int k=0;
  float gyroSet =63.3;



  bool parking = false, active = true , pf = 0, turning = true;

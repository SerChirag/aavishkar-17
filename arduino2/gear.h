
  void updateGyro()
  {
    gyroVal[k] = loopGyro();
    k++;
    if(k==10)
    {
      k = 0;
    }
  }

  double avg()
  {
    double avg = 0;
    int i = 0;
    for( i = 0; i<10 ; i++)
    {
      avg += gyroVal[i];
    }
    return (avg/10.0);
  }

  void gear()
  {
    float gv = avg();
    gv = abs(gv - gyroSet);
    
    if(gv < 8)
    {
      sevenSegment(4); 
    }
    else if(gv < 16)
      {
        sevenSegment(3); 
      }
      else if(gv < 24)
      {
        sevenSegment(2); 
      }
      else if(gv < 30)
      {
        sevenSegment(1); 
      }
  }


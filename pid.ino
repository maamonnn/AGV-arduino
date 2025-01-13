#include "pid.h"


// Fungsi untuk mendefinisikan nilai eror
int PID::errConfig(int es1, int es2, int es3, int es4, int es5){  
    int lastErr = 0;
    if(es1 == 0){
        return -6;
    }else if (es2 == 0){
        return -1;
    }else if (es3 == 0){
        return 0;
    }else if (es4 == 0){
        return 1;
    }else if(es1 == 0 && es2 == 0 && es3 == 0 && es4 == 0 && es5 == 0){
      return LastErr;
    }else{
        return 6;
    }    
}

// Fungsi untuk menghitung nilai PID
float PID::Speedcalculate(int Err){
  int now, old;
  int interval = 10;
  now = micros();
  if(now-old >= interval){
    float Kp = 3;
    float Ki = 0.05; 
    float Kd = 1;
    float KP = Kp*Err;
    Derr = LastErr - Err;
    LastErr = Err;
    Ierr += Err;
    return KP + Ki*Ierr*interval + Kd*(Derr/interval);
  }
 }



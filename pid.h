//
//  pid.h
//  Program
//
//  Created by Ferdian Adham on 03/09/24.
//

#ifndef pid_h
#define pid_h

class PID{
    private:
    float Err, Derr, Ierr;
    float LastErr =0;
    const int interval = 10;

    public:
    int errConfig(int es1, int es2, int es3, int es4, int es5);
    float Speedcalculate(int Err);

};

#endif /* pid_h */

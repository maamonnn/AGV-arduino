#ifndef control_h
#define control_h
#include <Servo.h>

class control
{
  private:
    int initialSpeed = 15;
    Servo manipulator1;
    Servo manipulator2;
    int servo, servo2;
  public:
    control(int servo_1, int servo_2);
    void setup();
    float rightSpeed(float speed);
    float leftSpeed(float speed);
    void maju(int kanan, int kiri);
    void kanan(int kanan, int kiri);
    void kiri(int kanan, int kiri);
    void hop(int kanan, int kiri);
    void angkat();
    void turun();
};




#endif
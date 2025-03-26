#include "control.h"

// Constructor untuk menginisiasi nilai pin servo
control::control(int servo_1, int servo_2):servo(servo_1), servo2(servo_2){}
  
// Fungsi untuk melakukan setup servo
void control::setup(){
  manipulator1.attach(servo);
  manipulator2.attach(servo2);
  manipulator1.write(120);
  manipulator2.write(120);
}

// Menentukan kecepatan pada motor kanan
float control::rightSpeed(float speed){
  return initialSpeed - speed;
}


// Menentukan kecepatan pada motor kiri
float control::leftSpeed(float speed){
  return initialSpeed + speed;
}

// Fungsi untuk gerak maju
void control::maju(int kanan, int kiri){
  analogWrite (eNA, kiri);
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
  analogWrite (eNB, kanan);
  //Serial.print("maju bro");
  //Serial.print("\n");
}


// Fungsi untuk belok kanan tajam
void control::kanan(int kanan, int kiri){
 analogWrite (eNA, kiri);
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
  analogWrite (eNB, kanan);
  //Serial.print("kanan bro");
  //Serial.print("\n");
}

// Fungsi untuk belok kiri tajam
void control::kiri(int kanan, int kiri){
 analogWrite (eNA, kiri);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
  analogWrite (eNB, kanan);
  //Serial.print("kiri bro");
  //Serial.print("\n"); 
}

// Fungsi untuk berhenti
void control::berhenti(int kanan, int kiri){
  analogWrite (eNA, kanan);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
  analogWrite (eNB, kiri);
}

// Fungsi untuk mengangkat troli
void control::angkat(){
  manipulator1.write(0);
  manipulator2.write(0);
  delay(500);
  manipulator1.write(40);
  manipulator2.write(40);
  delay(500);
  manipulator1.write(80);
  manipulator2.write(80);
  delay(500);
  manipulator1.write(120);
  manipulator2.write(120);
}


// Fungsi untuk menurunkan troli
void control::turun(){
  manipulator1.write(120);
  manipulator2.write(120);
  delay(500);
  manipulator1.write(80);
  manipulator2.write(80);
  delay(500);
  manipulator1.write(40);
  manipulator2.write(40);
  delay(500);
  manipulator1.write(0);
  manipulator2.write(0);
}

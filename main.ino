#include "pid.h"
#include "control.h"
#include <Servo.h>

//Enable
#define eNA 12
#define eNB 13

//Sensor
#define s0 2
#define s1 3
#define s2 4
#define s3 5
#define s4 7

//Motor
#define motor1 8
#define motor2 9
#define motor3 10
#define motor4 11

//Servo
const int servoPin = 6;
const int servoPin2 = A2;

//Infrared
#define infra A5

//Ultrasonik
#define echo A4
#define trig A3

PID kontrol;
Servo myservo;
control gerak(servoPin, servoPin2);

int a = 0;
void setup(){
  pinMode(s0, INPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);

  pinMode(eNA, OUTPUT);
  pinMode(eNB, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  
  pinMode(infra, INPUT);

  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  gerak.setup();
  Serial.begin(9600);

}

void loop(){
  int sens1 = digitalRead(s0);
  int sens2 = digitalRead(s1);
  int sens3 = digitalRead(s2);
  int sens4 = digitalRead(s3);
  int sens5 = digitalRead(s4);
  int analog_values = analogRead(infra);
  int eror = kontrol.errConfig(sens1, sens2, sens3, sens4, sens5);
  float kec = kontrol.Speedcalculate(eror);
  float kanan = gerak.rightSpeed(kec);
  float kiri = gerak.leftSpeed(kec);
  
  float syarat = jarak();

  Serial.print(syarat);
  Serial.print("\n");

  if(syarat < 10){
    if(a < 1){
      delay(1000);
      gerak.berhenti(0,0);
      gerak.angkat();
      Serial.println("gg");
      a += 2;
    }
    if(analog_values < 500){
      gerak.berhenti(0,0);
      delay(1000);
    }
    
    if(eror == -6){
      gerak.kiri(kanan, 0);
    }else if(eror == 6){
      gerak.kanan(kanan, 100);
    }else if(eror == 0){
      gerak.maju(100, 100);
    }else if(eror == -1){
      gerak.maju(kanan, kiri);
    }else if(eror == 1){
      gerak.maju(kanan, kiri);
    }else if (eror == 0){
      gerak.maju(kanan, kiri);
    }

    if(sens1 == 0 && sens2 == 0 && sens3 == 0 && sens4 == 0 && sens5 == 0){
      do{
        gerak.hop(0,0);
        delay(1000);
        gerak.turun();
      }while(true);
    }
  }else{
    if(analog_values < 500){
      gerak.hop(0,0);
      delay(1000);
    }

    if(eror == -6){
      gerak.kiri(kanan, 0);
    }else if(eror == 6){
      gerak.kanan(kanan, 100);
    }else if(eror == 0){
      gerak.maju(100, 100);
    }else if(eror == -1){
      gerak.maju(kanan, kiri);
    }else if(eror == 1){
      gerak.maju(kanan, kiri);
    }else if (eror == 0){
      gerak.maju(kanan, kiri);
    }
  }
  
}


// Fungsi untuk mendeteksi objek troli
float jarak() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  Serial.print("Duration: ");
  Serial.println(duration);

  float jarak = (duration * 0.034) / 2;
  return jarak;
}

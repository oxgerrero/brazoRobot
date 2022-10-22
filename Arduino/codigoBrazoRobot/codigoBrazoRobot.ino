#include <Servo.h>
Servo Base;
Servo Hombro;
Servo Codo;
Servo Pinza;
char option = ' ';

//base
int c = 70;
//hombro
int d = 100;
//codo
int e = 130;
//pinzas
int f = 30;
//desplazamiento
int desp=5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Base.attach(3);
  Hombro.attach(5);
  Codo.attach(6);
  Pinza.attach(10);
  iniciarBrazo();
}
void iniciarBrazo(){
  c = 70;
  d = 100;
  e = 130;
  f = 30;
  Base.write(c);
  Hombro.write(d);
  Codo.write(e);
  Pinza.write(f);

}
void loop() {
  if(Serial.available() != 0){
    option = Serial.read();
    if(option == 'a'){
      if(((c+desp)>0) && ((c+desp)<180)){
        c += desp;
        Base.write(c);
        Serial.print("Base    ");
        Serial.println(c);
      }
    }else if(option == 'b'){
      if(((c-desp)>0) && ((c-desp)<180)){
        c -= desp;
        Base.write(c);
        Serial.print("Base    ");
        Serial.println(c);
      }
      //Hombro
    }else if(option == 'c'){
      if(((d+desp)>30) && ((d+desp)<160)){
        d += 7;
        Hombro.write(d);
        Serial.print("Hombro    ");
        Serial.println(d);
      }
    }else if(option == 'd'){
      if(((d-desp)>30) && ((d-desp)<160)){
        d -= desp;
        Hombro.write(d);
        Serial.print("Hombro    ");
        Serial.println(d);
      }
      //Codo
    }else if(option == 'e'){
      if(((e+desp)>60) && ((e+desp)<160)){
        e += desp;
        Codo.write(e);
        Serial.print("Codo    ");
        Serial.println(e);
      }
    }else if(option == 'f'){
      if(((e-desp)>60) && ((e-desp)<160)){
        e -= desp;
        Codo.write(e);
        Serial.print("Codo    ");
        Serial.println(e);
      }
      //Pinza
    }else if(option == 'g'){
      if(((f+desp)>30) && ((f+desp)<77)){
        f += desp;
        Pinza.write(f);
        Serial.print("Pinza    ");
        Serial.println(f);
      }
    }else if(option == 'h'){
      if(((f-desp)>30) && ((f-desp)<77)){
        f -= desp;
        Pinza.write(f);
        Serial.print("Pinza    ");
        Serial.println(f);
      }
    }else if(option=='z'){
      iniciarBrazo();
    }
  }
  delay(100);
}

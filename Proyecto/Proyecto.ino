#include <Servo.h>//Libreria
Servo servoDerecho; //Crea Objeto Clase servoDerecho y servoIzquierdo
Servo servoIzquierdo;

void setup() // Subrutina de configuracion
{
  servoDerecho.attach(7); //configuracion pines
  servoIzquierdo.attach(8);
  Serial.begin (9600); //Comuicacion Pc Arduino
}

char orden; // Para Caracteres

void loop() 
{
  if(Serial.available()>0)
  {
    orden=Serial.read();
    Serial.println(orden);
    switch(orden)//Sentenci switch instruccion para decisiones multiples
    {
      case 'w': case 'W': //movimiento hacia adelante.
      servoDerecho.write(0); //Angulo definido por el argumento () al servo Dc
      servoIzquierdo.write(180);
      break;
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

      case 's': case'S':
      servoDerecho.write(180); //movimiento hacia atras.
      servoIzquierdo.write(0);
      break;

      case 'd': case 'D': //movimiento hacia la derecha.
      servoDerecho.write(0);
      servoIzquierdo.write(90);
      break;

      case 'a': case 'A': //movimiento hacia la izquierda.
      servoDerecho.write(90);
      servoIzquierdo.write(0);
      break;

      case 'p': case 'P': //detiene el robot.
      servoDerecho.write(90);
      servoIzquierdo.write(90);
      break;
    }
  }
}

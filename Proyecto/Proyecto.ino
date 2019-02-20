










void setup() {
  
}



char  orden;
void loop() 
{
  
  
}









#include <SoftwareSerial.h> // Libreria Bt
#include <Servo.h>//Libreria
Servo servoDerecho; //Crea Objeto Clase servoDerecho y servoIzquierdo
Servo servoIzquierdo;
#define TX 3;
#define RX 2;
SoftwareSerial BT(RX,TX);
void setup() // Subrutina de configuracion
{
  Serial.begin(9600); //Velocidad Comuicacion serial USB pin 0 y 1
  BT.begin(9600);// Velocidad del puerto serial por software pin 2 y 3
  servoDerecho.attach(7); //configuracion pines
  servoIzquierdo.attach(8);

  
}

char orden; // Para Caracteres

void loop() 
{
  if(BT.available()>0) //¿Dato disponible en puerto serial BT?
  {
    orden=BT.read(); //lectura del puerto serial BT
    BT.println(orden);// Transmision por el puerto serial al monitor arduino
    switch(orden)//Sentencia switch instruccion para decisiones multiples
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

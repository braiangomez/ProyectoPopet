
#include <SoftwareSerial.h> // Libreria Bt
#include <Servo.h>//Libreria
Servo servoDerecho; //Crea Objeto Clase servoDerecho y servoIzquierdo
Servo servoIzquierdo;
#define TX (3)
#define RX (2)
#define TX 3 //Sin ;
#define RX 2
SoftwareSerial BT(RX,TX);
void setup() // Subrutina de configuracion
{
  Serial.begin(9600); //Velocidad Comuicacion serial USB pin 0 y 1
  servoDerecho.attach(7); //configuracion pines
  servoIzquierdo.attach(8);
  BT.begin(9600);// Velocidad del puerto serial por software pin 2 y 3
}
char orden,resp;


void loop() 
{
  
  if(Serial.available()>0) //¿Dato disponible en puerto serial BT?
  {
    orden=BT.read(); //lectura del puerto serial BT
    Serial.println(orden);// Transmision por el puerto serial al monitor arduino
  }
  if (BT.available()>0){
    orden=BT.read();
    BT.println(orden);
    Serial.println(orden);
  

  
    switch(orden)//Sentencia switch instruccion para decisiones multiples
    {
      case 'w': //movimiento hacia adelante.
      servoDerecho.write(0); //Angulo definido por el argumento () al servo Dc
      servoIzquierdo.write(180);
      delay(100);
      break;

      case 's':
      servoDerecho.write(180); //movimiento hacia atras.
      servoIzquierdo.write(0);
      delay(100);
      break;

      case 'd': //movimiento hacia la derecha.
      servoDerecho.write(0);
      servoIzquierdo.write(90);
      delay(100);
      break;

      case 'a': //movimiento hacia la izquierda.
      servoDerecho.write(90);
      servoIzquierdo.write(0);
      delay(100);  
      break;

      case 'p': //detiene el robot.
      servoDerecho.write(90);
      servoIzquierdo.write(90);
      delay(100);
      break;

      case 'h'://Celebracion
      do{
      servoDerecho.write(0);
      servoIzquierdo.write(90);
      delay(100);
      servoDerecho.write(90);
      servoIzquierdo.write(0);
      delay(100);
      }
     while(resp!=h);
      break;
      
    }
  } else
  {
servoDerecho.write(90);
      servoIzquierdo.write(90);
    
  } 
}

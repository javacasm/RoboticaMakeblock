#include "MeOrion.h"
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "Wire.h"

MeBluetooth bluetooth(5);  //- Usamos el puerto 5 marcado con azul
MeDCMotor motorDriver1(M1); //- Un motor conectado en el puerto M1

Me7SegmentDisplay disp(PORT_3);

void setup()
{
    bluetooth.begin(38400);
    Serial.begin(9600);
}

int velocidad = 100;
int sentido = 1;  // Sentido de giro 1 o -1

void loop()
{
    char inDat;   
    //Serial.println("No data");
    if(bluetooth.available()>0)
    {   
      disp.display(bluetooth.available());
      delay(1000);
        //- caracter recibido por bluetooth convertido a mayúsculas
        inDat = bluetooth.read();

        disp.display(inDat);
        delay(1000);
        Serial.println((int)(inDat));
        switch(inDat){
          case 'L':   //- Izquierda
            sentido=1;
            run_motor();
            break;
          case 'R':   //- Derecha
            sentido=-1;
            run_motor();
            break;
          case '0':   //- Parada del motor
            velocidad=0;
            run_motor();
            break;
          case '1':   //- Velocidad lenta
            velocidad=100;
            run_motor();
            break;
          case '2':
            velocidad=200;  //- Velocidad rápida
            run_motor();
          break;
          default:break;
        
        }
    }
}


//- Le decimos al motor cómo debe girar en base a la velocidad establecida por bluetooth
void run_motor(){
  motorDriver1.run( sentido*velocidad); 
}

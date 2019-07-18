Usaremos la app creada y el m'ovil para controlar el robot
Usaremos botones y el acelerometro

Usamos la app [BlueTerm](https://play.google.com/store/apps/details?id=es.pymasde.blueterm&hl=es) para probar 

### Código

        #include "Makeblock.h"
        #include "Arduino.h"
        #include "SoftwareSerial.h"
        #include "Wire.h"

        MeBluetooth bluetooth(4);  //- Usamos el puerto 4 marcado con azul
        MeDCMotor motorDriver1(M1); //- Un motor conectado en el puerto M1

        void setup()
        {
            bluetooth.begin(9600);
        }

        int velocidad = 100;
        int sentido = 1;	// Sentido de giro 1 o -1

        void loop()
        {
            char inDat;		
            
            if(bluetooth.available())
            {   
                //- caracter recibido por bluetooth convertido a mayúsculas
                inDat = toUpperCase(bluetooth.read());
                
                switch(inDat){
                  case 'L':		//- Izquierda
                    sentido=1;
                    run_motor();
                    break;
                  case 'R':		//- Derecha
                    sentido=-1;
                    run_motor();
                    break;
                  case '0':		//- Parada del motor
                    velocidad=0;
                    run_motor();
                    break;
                  case '1':		//- Velocidad lenta
                    velocidad=100;
                    run_motor();
                    break;
                  case '2':
                    velocidad=200;	//- Velocidad rápida
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




[Ejemplo](https://www.makeblock.es/tutoriales/bluetooth_arduino_android/)

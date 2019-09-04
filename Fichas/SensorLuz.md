## Sensor de Luz (LDR)

Dado que no existe un bloque que lea directamente entradas analógicas, usaremos el bloque de lectura de joystick

El valor de X será el del Puerto 1 y el valor Y el del Puerto 2

Los valores pueden variar entre -490 y y 490, con lo que si le sumamos 490 tendremos valore entre 0 y 1000 (aproximadamente)

Vamos a hacer un ejemplo sencillo donde mostremos el valor leído en el display de 7 segmentos

![SensorLuz_7Segmentos](../images/SensorLuz_7Segmentos.png)

[Código](../Ejemplos/SensorLuz_LDR.sb2)

![Protoboard](../images/ProtoboardInside.jpg)

![Montaje LDR](../images/LDR_bb.png)

Ni el sensor de luz ni la resistencia tiene polaridad

![LDR_bb.png](../images/LDR_bb.png)

Es un montaje electrónico muy usado que se denomina divisor de tensión

![LDR_bb.png](../images/LDR_bb.png)


![Montaje 2xLDR](../images/2xLDR_bb.png)
    
![Esquematico 2xLDR](../images/2xLDR_esquematico.png)


Ejemplos/Dibujando_2xSensorLuz_LDR.sb2

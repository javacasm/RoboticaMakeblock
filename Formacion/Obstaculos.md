## Esquivar obstáculos

Una prueba típica consiste en esquivar obstáculos que encontramos en nuestra trayectoria

Podemos hacerlo de diferentes maneras según la complejidad del programa que queramos abordar

### Forma sencilla: calibrar los tiempos

Sólo tenemos que hacer los giros necesarios, calibrando el tiempo de cada paso hasta superar el obstáculo y volver a nuestra ruta

![EsquivaObstaculo.sb2](../images/EsquivaObstaculo.sb2) 

[EsquivaObstaculo.sb2](../Ejemplos/EsquivaObstaculo.sb2)

#### Mejora: programa capaz de aparcar
Se trata de crear los giros de la maniobra y calibrar los tiempos hasta conseguirlo.

Se puede mejorar haciendo que el robot busque aparcamiento y del tamaño necesario


### Forma más compleja

Una vez que detectamos un obstáculo, vamos girando pibotando y volvemos a mediendo la distancia al obstáculo hasta que veamos que ya no lo detectamos y medimos el giro que hemos hecho (por tiempo)

En ese caso avanzamos y giramos en sentido contrario hasta volver a la línea que traímos y volvemos a la posición recta volviendo a girar.



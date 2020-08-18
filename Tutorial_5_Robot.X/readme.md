# Robot diferencial

El robot lo compre en mercado libre y es iagual a la imagen

![Imagen de Robot](https://http2.mlstatic.com/chasis-carro-circular-kit-2-llantas-rueda-loca-robot-arduino-D_NQ_NP_960785-MLM32015906297_082019-F.webp?v=4&s=100)

En la parte de arriba se encuentra lo que es la batería de Lipo de 7.4 v, donde se conecta a una tarjeta que utiliza un regulador de 7.4 a 5v, para después ya conectar un cable
usb modificado para realizar la conexión de poder a la tarjeta de MPLAB Xpress. También ahí mismo se realizó la conexión de la entrada del puente H para alimentar los motores 
esta conexión es antes de del regulador.

<a href="https://ibb.co/xFSQQ5D"><img src="https://i.ibb.co/bbgnndP/IMG-20200818-134036083.jpg" alt="IMG-20200818-134036083" border="0"></a>

En la parte de abajo podemos ver que se encuentran los encoder de 20ppr con los sensores reflectivos.

<a href="https://ibb.co/hKFf0rX"><img src="https://i.ibb.co/Bg2Nkv4/IMG-20200818-134101558.jpg" alt="IMG-20200818-134101558" border="0"></a>

En la parte del medio, contiene lo que es el puente H para los motores y los encoder que se alimentan de 3.3 v.

<a href="https://ibb.co/mB7Y6GX"><img src="https://i.ibb.co/X4TdSb3/IMG-20200818-134116385.jpg" alt="IMG-20200818-134116385" border="0"></a>

## Consideraciones:

1.- La alimentacion que viene de una bateria LIPO de 7.4 v, no se puede conectar directamente a la tarjeta de PIC16F18877 ya que supere el limte de 5.5 v que puede operar,
mi sugerencia es que utilicen un regulador aparte de 7.4 v a 5 v y apartir de ahi ya puedan conectar seguro la tarjeta.

## Observaciones:

El robot no va tan derecho como me lo imaginaba, porque el chasis del robot no es tan estable ya que las ruedas estan exactamente en el centro y esto hace que tengan mucho juego
las ruedas locas. 
Tambien observe que utilizando los motores de plastico de color amarillo tienen mucho que ver que los engranes internos sean de plastico, seria recomendable utilizar motores con
engranes metalicos para mejorar tanto la velocidad y el control de ellos.

## Tipos de chasis

![Imagen de Robot](https://ae01.alicdn.com/kf/HTB1dzCoQXXXXXbsXpXXq6xXFXXX3/Elecrow-4WD-RC-Smart-Car-Chassis-with-S3003-Metal-Servo-Bearing-Kit-for-Arduino-Platform-DIY.jpg?v=4&s=100)

Recomiendo estos tipos de chasis para el proposito de ir en linea recta porque son mas estables, mas si le agregamos el PID que hemos visto ira excelente.

![Imagen de Robot](http://www.madnesselectronics.com/wp-content/uploads/2016/01/4wdsimple_1.jpg?v=4&s=100)

Este tipo de chasis esta muy bueno, pero yo lo veo complicado realizar la programacion de los encoders y para manejar los 4 motores, creo que seria una buena opcion si no se aplica algun PID.

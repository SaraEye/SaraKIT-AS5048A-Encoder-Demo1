# SaraKIT_Basics

Using Raspberry PI with SaraKIT, AS5048A Encoder with Brushless Motor Controllers (BLDC)

This demo shows how to use one of the encoders included in the SaraKIT (AS5048A) based on the Raspberry PI CM4 to control another gimbal in a synchronous manner.
By turning the gimbal in which the encoder is, I rotate the second gimbal in the same way.
Of course, you can use the AS5048A decoder itself by connecting it via PWM to one of the two connectors on the SaraKIT board.

sample video: 
![AS5048AEncoderDemo1](https://user-images.githubusercontent.com/35704910/170585031-f8715b1c-56d1-4b52-828e-1114f20b7a2e.gif)

run:
>make
>./gimbals

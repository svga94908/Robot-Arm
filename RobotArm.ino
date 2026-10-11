#include <Servo.h>                           //importiert die Library "Servo"

Servo servoClaw;                            // initialisiert Servo objects um den Servo zu kontrollieren
Servo servoBottom;
Servo servoJoint1;
Servo servoJoint2;

// ------------------------------------------ Joystick Variablen

int xKeyJoystick = A1;                      // initialisiert Pins, an denen vertikale und horizontale Pins des Joysticks angeschlossen sind
int yKeyJoystick = A2;
int xPosJoystick;
int yPosJoystick;
int servoPin1 = 5;                          // und Signaplpins am Servo
int servoPin2 = 6;
int initialPosition1 = 70;
int initialPosition2 = 70;

//------------------------------------------ Potentiometer

int potPinClaw = A0;
int potPinBottom = A3;

int valueClaw;                              // Variablen um die Werte der Analog Pins zu lesen
int valueBottom;


void setup() {

// ----------------------------------------- Joystick

  servoJoint1.attach (servoPin1);             // sagt Arduino wo die Servo Pins angeschlossen sind und bewegt Servos in Ausgangsposition (90°)
  servoJoint2.attach (servoPin2);
  servoJoint1.write (initialPosition1);
  servoJoint2.write (initialPosition2);
  pinMode (xKeyJoystick, INPUT);              // definiert vertikale und horizontale Pins des Joystick Moduls als Input
  pinMode (yKeyJoystick, INPUT);

// ----------------------------------------- Potentiometer

  servoClaw.attach (10);
  servoBottom.attach (3);
  

  
}


void loop () {

// ----------------------------------------- Joystick

  xPosJoystick = analogRead (xKeyJoystick);           // liest die Werte für x und y im Joystick Modul und speichert sie in Variablen
  yPosJoystick = analogRead (yKeyJoystick);
  
  if (xPosJoystick < 300) {                           // Bedingung, dass Servo sich nach rechts bewegt, wenn x-Wert des Joystick Moduls < 300
    if (initialPosition1 < 10) {
    }
    else {
      initialPosition1 = initialPosition1 - 20;      
      servoJoint1.write (initialPosition1);
      delay(100);
    }
  }

  if (xPosJoystick > 700) {                          // wenn x-Wert des Joystick Moduls > 700 -> Servo nach links
    if (initialPosition1 > 180) {                   
    } 
    else {
      initialPosition1 = initialPosition1 + 20;
      servoJoint1.write (initialPosition1);
      delay (100);
    }
  }

  if (yPosJoystick < 300) {                           // Bedingung, dass Servo sich nach rechts bewegt, wenn y-Wert des Joystick Moduls < 300
    if (initialPosition2 < 10) {
    }
    else {
      initialPosition2 = initialPosition2 - 20;      
      servoJoint2.write (initialPosition2);
      delay(100);
    }
  }

  if (yPosJoystick > 700) {                           // wenn y-Wert des Joystick Moduls > 700 -> Servo nach links
    if (initialPosition2 > 180) {                   
    } 
    else {
      initialPosition2 = initialPosition2 + 20;
      servoJoint2.write (initialPosition2);
      delay (100);
    }
  }
  
//------------------------------------------ Potentiometer
                                                      
  valueClaw = analogRead (potPinClaw);                // liest Wert des Potentiometers (zwischen 0 und 1023)
  valueClaw = map(valueClaw, 0, 1023, 0, 180);        // skaliert Werte, um sie mit Servo zu verwenden (auf zwischen 0 und 180)
  servoClaw.write(valueClaw);                         // setzt Position Servo auf skalierten Wert
  delay(15);                                          // wartet bis Servo zur Position gelangt
  
  valueBottom = analogRead (potPinBottom);
  valueBottom = map(valueBottom, 0, 1023, 0, 180);
  servoBottom.write(valueBottom);
  delay(15);
  
  
}

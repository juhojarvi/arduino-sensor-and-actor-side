
#include <Servo.h>
Servo myservo;

int motorCtrl = 10;
int incomingByte = 0;
int fanTurnOn = 49;
int fanTurnOff = 48;
int windowOpen = 50;
int windowClose = 51;

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        myservo.attach(9);
        pinMode(motorCtrl,OUTPUT);
}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                if(incomingByte == fanTurnOn){
                  digitalWrite(motorCtrl,HIGH);
                  Console.println("Fan has been turned on.");
                }else if(incomingByte == fanTurnOff){
                  digitalWrite(motorCtrl,LOW);
                  Console.println("Fan has been turned off.");
                }else if(incomingByte == windowOpen){
                  myservo.write(180);
                  Console.println("Window has been opened.");
                }else if(incomingByte == windowClose){
                  myservo.write(-180);
                  Console.println("Window has been closed.");
                }
        }
}

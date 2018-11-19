  #define PinCLK 2                   // Used for generating interrupts using CLK signal
#define PinDT 3                    // Used for reading DT signal                  // Used for the push button switch
#define motorPinAttach_1 6
#define motorPinAttach_2 7
                            //ENCODER:
long count = 0; 
volatile int A,B;  
byte state, statep;
                             //SERVO:
int virtualPosition = 0;
#include <Servo.h>
  Servo Ser_M1; 
  Servo Ser_M2;  
                             //ULTRASONIC:
const int trigPin = 19;
const int echoPin = 18;
long duration;
int distance = 0;
int distance0 = 0;
bool stoop=0;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(20);
  Serial.println("ready");
  pinMode(PinCLK,INPUT);
  pinMode(PinDT,INPUT);
  attachInterrupt (digitalPinToInterrupt(PinCLK),Achange,CHANGE);
  attachInterrupt (digitalPinToInterrupt(PinDT),Bchange,CHANGE);
  degreePos_2(87);
  degreePos_1(50);
  delay(500);
  degreePos_1(0);
  degreePos_2(0);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
}
void loop() {
  getstring();
  }






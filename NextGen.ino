#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define RightMotorSpeed 5
#define RightMotorDir 0
//#define RightMotorEnb 12
#define LeftMotorSpeed 4
#define LeftMotorDir 2
//#define LeftMotorEna 14

char auth[] = "5aad6a8015be4e19aa52a84096aeb852";
char ssid[] = "OnePlus 6T";
char pass[] = "9876543211";

void setup()
{
   Serial.begin(9600);
   Blynk.begin(auth, ssid, pass);

   //pinMode(RightMotorEnb, OUTPUT);
   pinMode(RightMotorSpeed, OUTPUT);
   pinMode(RightMotorDir, OUTPUT);
   //pinMode(LeftMotorEna, OUTPUT);
   pinMode(LeftMotorSpeed, OUTPUT);
   pinMode(LeftMotorDir, OUTPUT);
}

void loop() 
{
 Blynk.run();
}

void halt()
{  
   //digitalWrite(RightMotorEnb, HIGH);
   //digitalWrite(LeftMotorEna, HIGH);
   digitalWrite(RightMotorSpeed, LOW);
   digitalWrite(LeftMotorSpeed, LOW);
   
}

void forward()
{  
   //digitalWrite(RightMotorEnb, HIGH);
   //digitalWrite(LeftMotorEna, HIGH);
   digitalWrite(RightMotorDir, HIGH);
   digitalWrite(LeftMotorDir, HIGH);
   digitalWrite(RightMotorSpeed, HIGH);
   digitalWrite(LeftMotorSpeed, HIGH);
}

void reverse()
{  
   //digitalWrite(RightMotorEnb, HIGH);
   //digitalWrite(LeftMotorEna, HIGH);
   digitalWrite(RightMotorDir, HIGH);
   digitalWrite(LeftMotorDir, HIGH);
   digitalWrite(RightMotorSpeed, LOW);
   digitalWrite(LeftMotorSpeed, LOW);
}

void right()
{  
   //digitalWrite(RightMotorEnb, HIGH);
   //digitalWrite(LeftMotorEna, HIGH);
   digitalWrite(RightMotorDir, LOW);
   digitalWrite(LeftMotorDir, HIGH);
   digitalWrite(RightMotorSpeed, LOW);
   digitalWrite(LeftMotorSpeed, HIGH);
}

void left()
{  
   //digitalWrite(RightMotorEnb, HIGH);
   //digitalWrite(LeftMotorEna, HIGH);
   digitalWrite(RightMotorDir, HIGH);
   digitalWrite(LeftMotorDir, LOW);
   digitalWrite(RightMotorSpeed, HIGH);
   digitalWrite(LeftMotorSpeed, LOW);
}

BLYNK_WRITE(V0)
{
   if (param[0])
   forward();
   else
   halt();
}

BLYNK_WRITE(V1)
{
   if (param[0])
   reverse();
   else
   halt();
}

BLYNK_WRITE(V2)
{
   if (param[0])
   right();
   else
   halt();
}

BLYNK_WRITE(V3)
{
   if (param[0])
   left();
   else
   halt();
}

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Servo.h>

// Set these to run example.
#define FIREBASE_HOST "flex-21eb4.firebaseio.com"
#define FIREBASE_AUTH "H7CAso2prjI6RpeZgeGuJSUHKsruZGz8ysjLlnDZ"
#define WIFI_SSID "Ding ding ding"
#define WIFI_PASSWORD "23456789"

int potPin = A0;
//int potPin1 = A0;
Servo servo_1; 
//Servo servo_2;
int value;
//int value1;
void setup() {
  Serial.begin(9600);
  servo_1.attach(5);
  //servo_2.attach(0);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop(){
  int value = analogRead(potPin);
  //int value1 = analogRead(potPin1);
  value = Firebase.getInt("value");
  //value1 = Firebase.getInt("value1");
  value = map(value, 0, 1137, 10, 160);
  //value1 = map(value1, 0, 1137, 10, 160);
  Serial.println(value);
  //Serial.print("Pot2:");
  //Serial.println(value1);
  if(Firebase.getInt("value") >= 0 && Firebase.getInt("value") < 10){
    servo_1.attach(5);
    servo_1.write(10);
    delay(500);
    servo_1.detach();
  }
  /*if(Firebase.getInt("value1") >= 0 && Firebase.getInt("value1") < 10){
    servo_2.attach(0);
    servo_2.write(10);
    delay(500);
    servo_2.detach();
  }*/
  else if(Firebase.getInt("value") > 10 && Firebase.getInt("value") <= 256){
    servo_1.attach(5);
    servo_1.write(45);
    delay(500);
    servo_1.detach();
  }
  /*else if(Firebase.getInt("value1") > 10 && Firebase.getInt("value1") <= 256){
    servo_2.attach(0);
    servo_2.write(45);
    delay(500);
    servo_2.detach();
   }*/
  else if(Firebase.getInt("value") > 256 && Firebase.getInt("value") <= 512){
     servo_1.attach(5);
     servo_1.write(90);
     delay(500);
     servo_1.detach();
   }
  /*else if(Firebase.getInt("value1") > 256 && Firebase.getInt("value1") <= 512){
     servo_2.attach(0);
     servo_2.write(90);
     delay(500);
     servo_2.detach();
   }*/
  else if(Firebase.getInt("value") > 512 && Firebase.getInt("value") <= 768){
     servo_1.attach(5);
     servo_1.write(135);
     delay(500);
     servo_1.detach();
   }
  /*else if(Firebase.getInt("value1") > 512 && Firebase.getInt("value1") <= 768){
     servo_2.attach(0);
     servo_2.write(135);
     delay(500);
     servo_2.detach();
  }*/
  else if(Firebase.getInt("value") > 768 && Firebase.getInt("value") <= 1137){
     servo_1.attach(5);
     servo_1.write(160);
     delay(500);
     servo_1.detach();
   }
  /* else if(Firebase.getInt("value1") > 768 && Firebase.getInt("value1") <= 1137){
     servo_2.attach(0);
     servo_2.write(160);
     delay(500);
     servo_2.detach();
   }*/
   
  if (Firebase.failed()) {
      Serial.println(Firebase.error());  
      return;
  }
  delay(500);
}

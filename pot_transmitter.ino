#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "flex-21eb4.firebaseio.com"
#define FIREBASE_AUTH "H7CAso2prjI6RpeZgeGuJSUHKsruZGz8ysjLlnDZ"
#define WIFI_SSID "Ding ding ding"
#define WIFI_PASSWORD "23456789"

//int potPin = A0;
int potPin1 = A0;
//int value;
int value1;
void setup() {
  Serial.begin(9600);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop(){
   
  //int value = analogRead(potPin);
  int value1 = analogRead(potPin1);
  //value = map(value, 0, 90, 0, 100);
  value1 = map(value1, 0, 90, 0, 100);
  //Firebase.setInt("value",value);
  Firebase.setInt("value1",value1);
  //Serial.println(value);
  Serial.println(value1);
  if (Firebase.failed()) {
    Serial.println(Firebase.error());  
    return;
  }
  delay(500);
}

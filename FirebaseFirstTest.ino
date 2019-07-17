//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
 #include "DHT.h"

#define DHTPIN 13     // what digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11

// Set these to run example.
#define FIREBASE_HOST "statiometeo-b6cea.firebaseio.com"
#define FIREBASE_AUTH "HzKOJapkkiimBSNs55L6fBKSXVB5oBGIzcqZRcdQ"
#define WIFI_SSID "Silicon Valley"
#define WIFI_PASSWORD "#VyTeamNoLimit#"

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  Serial.println("DHTxx test!");

  dht.begin();
  
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

void loop() {
    // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();


  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");

  /*
  // set temperature
  Firebase.setFloat("Temperature", t);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /Temperature failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // set humidity
  Firebase.setFloat("Humidity", h);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /humidity failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);*/

  String temperature = Firebase.pushFloat("Temperature", t);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /Temperature failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  Serial.println(temperature);
  
  // set humidity
  String humidity = Firebase.pushFloat("Humidity", h);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /humidity failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  Serial.println(humidity);
  
  /*
  // get temperature 
  Serial.print("Temperature: ");
  Serial.println(Firebase.getFloat("Temperature"));
  delay(1000);

 // get humidity 
  Serial.print("Humidity: ");
  Serial.println(Firebase.getFloat("Humidity"));
  delay(1000);*/


  // remove value
  /*Firebase.remove("number");
  delay(1000);*/

  // append a new value to /logs
  /*String name = Firebase.pushInt("logs", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /logs/");
  Serial.println(name);
  delay(1000);*/

}

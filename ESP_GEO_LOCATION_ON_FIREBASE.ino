#ifdef ARDUINO_ARCH_SAMD
#include <WiFi101.h>
#elif defined ARDUINO_ARCH_ESP8266
#include <ESP8266WiFi.h>
#elif defined ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#error Wrong platform
#endif 

#include <WifiLocation.h>

#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "fir-practice-fa9d4.firebaseio.com"
#define FIREBASE_AUTH "GQFjpLhMCvn8Wx0s85agQPi8hLIAZFLuhEXaVuGa"

const char* googleApiKey = "AIzaSyDZAfjn_GETAYc-zyfeU-qigFfuKEq2HxY";
const char* ssid = "hotspot";
const char* passwd = "naman1234";

WifiLocation location(googleApiKey);
float lat = 0.0;
float lon = 0.0;

void setup() {
    Serial.begin(115200);
    // Connect to WPA/WPA2 network
#ifdef ARDUINO_ARCH_ESP32
    WiFi.mode(WIFI_MODE_STA);
#endif
#ifdef ARDUINO_ARCH_ESP8266
    WiFi.mode(WIFI_STA);
#endif
    WiFi.begin(ssid, passwd);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(ssid);
        // wait 5 seconds for connection:
        Serial.print("Status = ");
        Serial.println(WiFi.status());
        delay(500);
    }
    location_t loc = location.getGeoFromWiFi();

    Serial.println("Location request data");
    Serial.println(location.getSurroundingWiFiJson());
    lat = loc.lat;
    lon = loc.lon;
    Serial.println("Latitude: " + String(lat));
    Serial.println("Longitude: " + String(lon));
    Serial.println("Accuracy: " + String(loc.accuracy));

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {

  Serial.println("postin on firebase");

  // update value
  Firebase.setFloat("latitude", lat);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // update value
  Firebase.setFloat("longitude", lon);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // set string value
  Firebase.setString("message", "latitude laongitude posting");
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

}


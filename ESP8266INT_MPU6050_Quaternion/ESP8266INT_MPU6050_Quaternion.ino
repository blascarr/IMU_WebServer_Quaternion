#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

//#define INTERRUPT_PIN 8 

#include <Arduino_JSON.h>
#include "webpage.h"

MPU6050 mpu;
//#define SERIALDEBUG

const char *ssid = "SSID";
const char *password = "PASSWORD";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Create an Event Source on /events
AsyncEventSource events("/events");

// Json Variable to Hold Sensor Readings
JSONVar readings;

// Timer variables
unsigned long timestamp = 0;
unsigned long duration = 300;

#include "IMU_Controller.h"
#include "WiFi_Controller.h"


// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {
  
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    Serial.begin(115200);
    while (!Serial); 

    initWiFi();
    initWebServer();
    initIMU();
}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
    // if programming failed, don't try to do anything
    #ifdef INTERRUPT_PIN
      if (!dmpReady) return;
    #endif
    
    updateIMU();
    
    if (millis() - timestamp > duration) {
      timestamp = millis();
      events.send(getGyroReadings().c_str(), "gyro_readings", millis());
      #ifdef SERIALDEBUG
        serialReadings();
      #endif
    }
}

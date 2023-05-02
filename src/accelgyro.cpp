#include "accelgyro.h"
MPU6050 accelgyro;


void InitializeAccelGyro()
  {
    Wire.begin(I2C_SDA, I2C_SCL);

    // initialize device
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
    Serial.println("PID tuning Each Dot = 100 readings");
  
    accelgyro.CalibrateAccel(6);
    accelgyro.CalibrateGyro(6);
  } // Initialize


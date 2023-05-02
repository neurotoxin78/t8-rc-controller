#include "main.h"
#include "sntp.h"
#include "tasks.h"
#include <Arduino.h>
#include <WiFi.h>
#include "AsyncUDP.h"
#include "GyverMotor.h"
#include "accelgyro.h"
#include "parser.h"


#define I2C_FREQUENCY 100000

IPAddress client_ip;
const char *udpAddress = "192.168.4.1";
const int udpPort = 50000;
AsyncUDP udp;

GMotor motor1(DRIVER2WIRE, GPIO_NUM_16, GPIO_NUM_18, HIGH);
static const char *TAG = "esp32s2";
const char *ssid = "RC-AP";
const char *password = "Mxbb2Col";

void setup()
{
  Serial.begin(115200);
  delay(500);
  pinMode(LED, OUTPUT);
  // InitializeAccelGyro();
  // motor1.setMode(BACKWARD);
  // motor1.setSpeed(64);
  createTasks();

  CreateAP();
  delay(1000);
  if (udp.listen(udpPort))
  {
    udp.onPacket(packetParser);
  }
}

void loop()
{
  vTaskDelay(pdMS_TO_TICKS(1000));
}

void CreateAP()
{
  WiFi.mode(WIFI_STA);
  WiFi.softAP(ssid, password);
}

#include "WiFi.h"
#define LED GPIO_NUM_21
#define WIFI_SSID "Neurotoxin2"
#define WIFI_PASSWORD "Mxbb2Col"
#include <Wire.h>
#define I2C_SDA GPIO_NUM_9
#define I2C_SCL GPIO_NUM_8



void WiFiEvent(WiFiEvent_t event);
void CreateAP();

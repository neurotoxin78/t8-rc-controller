#include "Wire.h"
#include "MPU6050.h"
#include "main.h"

extern MPU6050 accelgyro;
void SetAveraging(int NewN);
extern void AccelGyro();
extern void InitializeAccelGyro();
extern void GetSmoothed();

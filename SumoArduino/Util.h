#pragma once
#include <Arduino.h>

#if DEBUG
#define InitializeSerial(i) Serial.begin(i)
#define Print(t) Serial.print(t)
#define Println(t) Serial.println(t)
#else
#define InitializeSerial(i)
#define Print(t)
#define Println(t)
#endif
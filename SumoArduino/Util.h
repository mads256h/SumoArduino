#pragma once
#include <Arduino.h>

#if 1
#define Print(t) Serial.print(t)
#define Println(t) Serial.println(t)
#else
#define Print(t)
#define Println(t)
#endif
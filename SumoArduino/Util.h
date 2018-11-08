#pragma once
#include <Arduino.h>

#if DEBUG
#define Print(t) Serial.print(t)
#define Println(t) Serial.println(t)
#else
#define Print(t)
#define Println(t)
#endif
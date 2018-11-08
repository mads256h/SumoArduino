// Name:    Util.h
// Created: 23/10/2018 08:50
// Edited:  08/11/2018 17:31
// Author:  Mads
// Purpose: Defines utility macros and functions.
// Made by Gruppe 5: Mads Bluhme, Frederik Schultz & Mads Beyer Mogensen


#pragma once
#include <Arduino.h>

#if DEBUG
#define INITIALIZE_SERIAL(i) Serial.begin(i)
#define PRINT(t) Serial.print(t)
#define PRINTLN(t) Serial.println(t)
#else
#define INITIALIZE_SERIAL(i)
#define PRINT(t)
#define PRINTLN(t)
#endif

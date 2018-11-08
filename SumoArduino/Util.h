/*
 Name:		Util.h
 Created:	8/11/2018 16:50:39
 Edited:	8/11/2018 16:51:42
 Author:	Mads
 Purpose:	Defines utility macros and functions.
*/

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
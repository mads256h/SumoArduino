// Name:    Pins.h
// Created: 08/11/2018 10:03
// Edited:  08/11/2018 17:27
// Author:  Mads
// Purpose: Defines pin constants.
// Made by Gruppe 5: Mads Bluhme, Frederik Schultz & Mads Beyer Mogensen


#pragma once
#include <Arduino.h>

//Namespace that encapsulates the pins used in the program
namespace Pins
{
	//Sensor pins

	constexpr uint8_t SERVO = 4;
	constexpr uint8_t ECHO = 5;
	constexpr uint8_t TRIGGER = 6;


	//Trip pins

	constexpr uint8_t MOTOR1_TRIP = 2;
	constexpr uint8_t MOTOR2_TRIP = 3;


	//Infrared sensors

	constexpr uint8_t INFRA_TOP_LEFT = A2;
	constexpr uint8_t INFRA_TOP_RIGHT = A1;
	constexpr uint8_t INFRA_BOTTOM = A0;


	//Motor pins

	constexpr uint8_t MOTORA_CONTROL1 = 8;
	constexpr uint8_t MOTORA_CONTROL2 = 9;

	constexpr uint8_t MOTORB_CONTROL1 = 10;
	constexpr uint8_t MOTORB_CONTROL2 = 11;
}

/*
 Name:		Pins.h
 Created:	8/11/2018 16:50:10
 Edited:	8/11/2018 16:52:07
 Author:	Mads
 Purpose:	Defines pin constants.
*/

#pragma once

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


	//Motor pins

	constexpr uint8_t MOTORA_CONTROL1 = 8;
	constexpr uint8_t MOTORA_CONTROL2 = 9;

	constexpr uint8_t MOTORB_CONTROL1 = 10;
	constexpr uint8_t MOTORB_CONTROL2 = 11;
	
}
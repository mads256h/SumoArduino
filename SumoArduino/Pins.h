#pragma once

//Namespace that encapsulates the pins used in the program
namespace Pins
{
	//Sensor pins

	constexpr uint8_t SERVO = 3;
	constexpr uint8_t ECHO = 4;
	constexpr uint8_t TRIGGER = 5;


	//Trip pins

	constexpr uint8_t MOTOR1_TRIP = 2;
	constexpr uint8_t MOTOR2_TRIP = 3;


	//Motor pins

	constexpr uint8_t MOTORA_CONTROL1 = 0;
	constexpr uint8_t MOTORA_CONTROL2 = 0;

	constexpr uint8_t MOTORB_CONTROL1 = 0;
	constexpr uint8_t MOTORB_CONTROL2 = 0;
	
}
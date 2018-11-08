/*
 Name:		SensorController.h
 Created:	8/11/2018 16:46:33
 Author:	Mads
 Purpose:	Interface definition for the sensor controller.
*/
#pragma once

#include <Arduino.h>
#include <Servo.h>
#include "MotorController.h"

//Class that controls the sensor and feeds instructions
//to the MotorController.
class SensorController
{
private:
	//Pin for the servo motor.
	const uint8_t ServoPin;

	//Echo and trigger pins for the sonic distance sensor.
	const uint8_t EchoPin;
	const uint8_t TrigPin;

	//Servo controller library class
	Servo servo;

	//Our own motor controller class.
	const MotorController* Motor;


	//Interrupt function for the first motor.
	static void MotorATripInterrupt();
	//Interrupt function for the second motor.
	static void MotorBTripInterrupt();

public:
	//How many times motor A trip has triggered.
	volatile static uint32_t MotorATripCounter;
	//How many times motor B trip has triggered.
	volatile static uint32_t MotorBTripCounter;

	//Do we turn the ultrasonic sensor clockwise?
	bool ClockWise;

	//The current angle of the sensor.
	uint8_t Angle;

	//Constructs a SensorController object it takes servo
	//and ultra sonic sensor pins.
	SensorController(const uint8_t servoPin, const uint8_t echoPin, const uint8_t trigPin);

	//We need to have a begin function to be called in setup,
	//because the constructor runs before any other code and
	//we depend on setup code in the hidden main function to
	//setup interrupts and ports. It takes a MotorController
	//pointer.
	void Begin(const MotorController* const motor);

	//Read a distance from the ultrasonic sensor. This
	//value is not in any unit, but it is linear.
	uint32_t ReadDistance(const unsigned long timeout = 20000UL) const;

	//The sensor loop. Place this in the loop function.
	void Loop();

};


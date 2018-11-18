// Name:    SensorController.h
// Created: 09/10/2018 09:27
// Edited:  08/11/2018 17:26
// Author:  Mads
// Purpose: Interface definition for the sensor controller.
// Made by Gruppe 5: Mads Bluhme, Frederik Schultz & Mads Beyer Mogensen


#pragma once

#include <Arduino.h>
#include <Servo.h>
#include "MotorController.h"

//Class that controls the sensor and feeds instructions
//to the MotorController.
class SensorController
{
private:
	//Constants
	constexpr static uint8_t MinAngle = 60;
	constexpr static uint8_t MaxAngle = 180 - MinAngle;

	constexpr static uint8_t MinForwardAngle = 85;
	constexpr static uint8_t MaxForwardAngle = 180 - MinForwardAngle;

	constexpr static uint8_t AngleStep = 5;

	constexpr static int16_t MaxBlackValue = 10;

	//Pin for the servo motor.
	const uint8_t _servoPin;

	//Echo and trigger pins for the sonic distance sensor.
	const uint8_t _echoPin;
	const uint8_t _trigPin;

	//Servo controller library class
	Servo _servo;

	//Our own motor controller class.
	const MotorController* _motor;


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

	//The amount of times the sensor has completed a turn without seeing anything
	uint8_t Sweeps;

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


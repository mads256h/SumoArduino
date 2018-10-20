#pragma once

#include <Arduino.h>
#include <Servo.h>
#include "MotorController.h"


class SensorController
{
private:
	//Pin for the servo motor.
	const uint8_t ServoPin;

	//Echo and trigger pins for the sonic distance sensor.
	const uint8_t EchoPin;
	const uint8_t TrigPin;

	//Servo controller library class
	Servo ServoController;

	//Our own motor controller class.
	const MotorController* Motor;

	volatile static uint32_t Motor1TripCounter;
	volatile static uint32_t Motor2TripCounter;

	static void Motor1TripInterrupt();
	static void Motor2TripInterrupt();

public:
	bool ClockWise;
	uint8_t Angle;

	SensorController(const uint8_t servoPin, const uint8_t echoPin, const uint8_t trigPin);

	void Begin(const MotorController* const motor);

	uint32_t ReadDistance() const;

	void Loop();

};


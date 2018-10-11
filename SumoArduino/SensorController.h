#pragma once

#include <Arduino.h>
#include <Servo.h>
#include "MotorController.h"

//#include <Ultrasonic-2.1.0/src/Ultrasonic.h>

class SensorController
{
private:
	uint8_t ServoPin;
	uint8_t EchoPin;
	uint8_t TrigPin;

	Servo ServoController;
	const MotorController* Motor;

public:
	bool ClockWise;
	uint8_t Angle;

	SensorController(const uint8_t servoPin, const uint8_t echoPin, const uint8_t trigPin);

	void Begin(const MotorController* const motor);

	uint32_t ReadDistance() const;

	void Loop();

};


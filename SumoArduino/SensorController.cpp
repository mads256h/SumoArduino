// Name:    SensorController.cpp
// Created: 09/10/2018 09:27
// Edited:  08/11/2018 17:27
// Author:  Mads
// Purpose: Interface implementation for the sensor controller.
// Made by Gruppe 5: Mads Bluhme, Frederik Schultz & Mads Beyer Mogensen



#include "SensorController.h"
#include <Servo.h>
#include "Util.h"
#include "Pins.h"


void SensorController::MotorATripInterrupt()
{
	MotorATripCounter++;
}

void SensorController::MotorBTripInterrupt()
{
	MotorBTripCounter++;
}

SensorController::SensorController(const uint8_t servoPin, const uint8_t echoPin, const uint8_t trigPin)
	: _servoPin(servoPin), _echoPin(echoPin), _trigPin(trigPin), _servo(Servo()), _motor(nullptr), ClockWise(false), Angle(0)
{ }

void SensorController::Begin(const MotorController* const motor)
{
	pinMode(_servoPin, OUTPUT);
	pinMode(_echoPin, INPUT);
	pinMode(_trigPin, OUTPUT);
	_servo.attach(_servoPin);
	_motor = motor;

	pinMode(Pins::MOTOR1_TRIP, INPUT);
	pinMode(Pins::MOTOR2_TRIP, INPUT);

	attachInterrupt(digitalPinToInterrupt(Pins::MOTOR1_TRIP), MotorATripInterrupt, CHANGE);
	attachInterrupt(digitalPinToInterrupt(Pins::MOTOR2_TRIP), MotorBTripInterrupt, CHANGE);
}

uint32_t SensorController::ReadDistance(const unsigned long timeout) const
{
	digitalWrite(_trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(_trigPin, LOW);

	return pulseIn(_echoPin, HIGH, timeout);
}

void SensorController::Loop()
{
	if (analogRead(Pins::INFRA_BOTTOM) < MaxBlackValue)
	{
		_motor->Forward();
		return;
	}
	if (analogRead(Pins::INFRA_TOP_LEFT) < MaxBlackValue || analogRead(Pins::INFRA_TOP_RIGHT) < MaxBlackValue)
	{
		_motor->Backwards();
		return;
	}

	if (Angle < MinAngle)
	{
		ClockWise = false;
		Sweeps++;
	}

	if (Angle > MaxAngle)
	{
		ClockWise = true;
		Sweeps++;
	}

	if (Sweeps >= 3)
	{
		_motor->Rotate(90);
		Sweeps = 0;
		Angle = 90;
	}

	_servo.write(Angle);


	const auto distance = ReadDistance();
	if (distance < 2800 && distance != 0)
	{
		Sweeps = 0;
		if (Angle < MaxForwardAngle && Angle > MinForwardAngle)
		{
			_motor->Forward();
			delay(60);
		}
		else
		{
			_motor->Rotate(Angle - 90);
			Angle = 90;
		}

		return;
	}
	_motor->Brake();
	delay(60);


	if (ClockWise)
		Angle -= AngleStep;
	else
		Angle += AngleStep;

}

volatile uint32_t SensorController::MotorATripCounter = 0;
volatile uint32_t SensorController::MotorBTripCounter = 0;
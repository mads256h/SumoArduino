/*
 Name:		MotorController.cpp
 Created:	8/11/2018 16:48:32
 Edited:	8/11/2018 17:01:23
 Author:	Mads
 Purpose:	Interface implementation for the motor controller.
*/

#include "MotorController.h"


MotorController::MotorController(const uint8_t a01Pin, const uint8_t a02Pin, const uint8_t b01Pin, const uint8_t b02Pin)
	: _motorAControl1Pin(a01Pin), _motorAControl2Pin(a02Pin), _motorBControl1Pin(b01Pin), _motorBControl2Pin(b02Pin)
{ }

void MotorController::Begin() const
{
	pinMode(_motorAControl1Pin, OUTPUT);
	pinMode(_motorAControl2Pin, OUTPUT);
	pinMode(_motorBControl1Pin, OUTPUT);
	pinMode(_motorBControl2Pin, OUTPUT);

	Brake();
}

void MotorController::Start() const
{
	Forward();
	delay(250);
	Brake();
	delay(175);
	Rotate(180);
	Brake();
}

void MotorController::Freewheel() const
{
	digitalWrite(_motorAControl1Pin, LOW);
	digitalWrite(_motorAControl2Pin, LOW);
	digitalWrite(_motorBControl1Pin, LOW);
	digitalWrite(_motorBControl2Pin, LOW);
}

void MotorController::Brake() const
{
	digitalWrite(_motorAControl1Pin, HIGH);
	digitalWrite(_motorAControl2Pin, HIGH);
	digitalWrite(_motorBControl1Pin, HIGH);
	digitalWrite(_motorBControl2Pin, HIGH);
}

void MotorController::Forward() const
{
	digitalWrite(_motorAControl1Pin, HIGH);
	digitalWrite(_motorAControl2Pin, LOW);
	digitalWrite(_motorBControl1Pin, HIGH);
	digitalWrite(_motorBControl2Pin, LOW);
}

void MotorController::TurnLeft() const
{
	digitalWrite(_motorAControl1Pin, HIGH);
	digitalWrite(_motorAControl2Pin, LOW);
	digitalWrite(_motorBControl1Pin, HIGH);
	digitalWrite(_motorBControl2Pin, HIGH);
}

void MotorController::TurnRight() const
{
	digitalWrite(_motorAControl1Pin, HIGH);
	digitalWrite(_motorAControl2Pin, HIGH);
	digitalWrite(_motorBControl1Pin, HIGH);
	digitalWrite(_motorBControl2Pin, LOW);
}

void MotorController::Backwards() const
{
	digitalWrite(_motorAControl1Pin, LOW);
	digitalWrite(_motorAControl2Pin, HIGH);
	digitalWrite(_motorBControl1Pin, LOW);
	digitalWrite(_motorBControl2Pin, HIGH);
}

void MotorController::Rotate(const int16_t angle) const
{
	if (angle > 0)
	{
		digitalWrite(_motorAControl1Pin, LOW);
		digitalWrite(_motorAControl2Pin, HIGH);
		digitalWrite(_motorBControl1Pin, HIGH);
		digitalWrite(_motorBControl2Pin, LOW);
		delay(17.123 * pow(angle, 0.6494));
		Brake();
	}
	else
	{
		digitalWrite(_motorAControl1Pin, HIGH);
		digitalWrite(_motorAControl2Pin, LOW);
		digitalWrite(_motorBControl1Pin, LOW);
		digitalWrite(_motorBControl2Pin, HIGH);
		delay(17.123 * pow(abs(angle), 0.6494));
		Brake();
	}
}

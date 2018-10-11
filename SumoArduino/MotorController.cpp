#include "MotorController.h"


MotorController::MotorController(const uint8_t _A01Pin, const uint8_t _A02Pin, const uint8_t _B01Pin, const uint8_t _B02Pin)
{
	A01Pin = _A01Pin;
	A02Pin = _A02Pin;
	B01Pin = _B01Pin;
	B02Pin = _B02Pin;
}

void MotorController::Begin() const
{
	pinMode(A01Pin, OUTPUT);
	pinMode(A02Pin, OUTPUT);
	pinMode(B01Pin, OUTPUT);
	pinMode(B02Pin, OUTPUT);

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
	digitalWrite(A01Pin, LOW);
	digitalWrite(A02Pin, LOW);
	digitalWrite(B01Pin, LOW);
	digitalWrite(B02Pin, LOW);
}

void MotorController::Brake() const
{
	digitalWrite(A01Pin, HIGH);
	digitalWrite(A02Pin, HIGH);
	digitalWrite(B01Pin, HIGH);
	digitalWrite(B02Pin, HIGH);
}

void MotorController::Forward() const
{
	digitalWrite(A01Pin, HIGH);
	digitalWrite(A02Pin, LOW);
	digitalWrite(B01Pin, HIGH);
	digitalWrite(B02Pin, LOW);
}

void MotorController::TurnLeft() const
{
	digitalWrite(A01Pin, HIGH);
	digitalWrite(A02Pin, LOW);
	digitalWrite(B01Pin, HIGH);
	digitalWrite(B02Pin, HIGH);
}

void MotorController::TurnRight() const
{
	digitalWrite(A01Pin, HIGH);
	digitalWrite(A02Pin, HIGH);
	digitalWrite(B01Pin, HIGH);
	digitalWrite(B02Pin, LOW);
}

void MotorController::Backwards() const
{
	digitalWrite(A01Pin, LOW);
	digitalWrite(A02Pin, HIGH);
	digitalWrite(B01Pin, LOW);
	digitalWrite(B02Pin, HIGH);
}

void MotorController::Rotate(const int16_t angle) const
{
	if (angle > 0)
	{
		digitalWrite(A01Pin, LOW);
		digitalWrite(A02Pin, HIGH);
		digitalWrite(B01Pin, HIGH);
		digitalWrite(B02Pin, LOW);
		delay(17.123 * pow(angle, 0.6494));
		Brake();
	}
	else
	{
		digitalWrite(A01Pin, HIGH);
		digitalWrite(A02Pin, LOW);
		digitalWrite(B01Pin, LOW);
		digitalWrite(B02Pin, HIGH);
		delay(17.123 * pow(abs(angle), 0.6494));
		Brake();
	}
}

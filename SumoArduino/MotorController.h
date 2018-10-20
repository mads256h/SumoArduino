#pragma once
#include <Arduino.h>

class MotorController
{
private:
	const uint8_t A01Pin;
	const uint8_t A02Pin;
	const uint8_t B01Pin;
	const uint8_t B02Pin;

public:

	MotorController(const uint8_t a01Pin, const uint8_t a02Pin, const uint8_t b01Pin, const uint8_t b02Pin);

	void Begin() const;

	void Start() const;

	void Freewheel() const;

	void Brake() const;

	void Forward() const;

	void TurnLeft() const;

	void TurnRight() const;

	void Backwards() const;


	void Rotate(const int16_t angle) const;
};


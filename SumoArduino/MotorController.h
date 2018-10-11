#pragma once
#include <Arduino.h>

class MotorController
{
private:
	uint8_t A01Pin;
	uint8_t A02Pin;
	uint8_t B01Pin;
	uint8_t B02Pin;

public:
	static const uint16_t DELAY_15_CONSTANT = 100;
	static const uint16_t DELAY_45_CONSTANT = 200;
	static const uint16_t DELAY_90_CONSTANT = 320;
	static const uint16_t DELAY_180_CONSTANT = 500;

	MotorController(const uint8_t _A01Pin, const uint8_t _A02Pin, const uint8_t _B01Pin, const uint8_t _B02Pin);

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


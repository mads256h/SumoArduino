#include "SensorController.h"


SensorController::SensorController(const uint8_t servoPin, const uint8_t echoPin, const uint8_t trigPin)
{
	ServoPin = servoPin;
	EchoPin = echoPin;
	TrigPin = trigPin;
	ServoController = Servo();
	Motor = nullptr;
	ClockWise = false;
	Angle = 0;
}

void SensorController::Begin(const MotorController* const  motor)
{
	pinMode(ServoPin, OUTPUT);
	pinMode(EchoPin, INPUT);
	pinMode(TrigPin, OUTPUT);
	ServoController.attach(ServoPin);
	Motor = motor;
}

uint32_t SensorController::ReadDistance() const
{
	digitalWrite(TrigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(TrigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(TrigPin, LOW);

	return pulseIn(EchoPin, HIGH, 20000UL);
}

void SensorController::Loop()
{
	if (Angle < 10)
		ClockWise = false;

	if (Angle > 170)
		ClockWise = true;

	ServoController.write(Angle);


	const auto distance = ReadDistance();
	//Serial.println(distance);
	if (distance < 2800 && distance != 0)
	{
		if (Angle < 100 && Angle > 80)
		{
			Motor->Forward();
			delay(60);
		}
		else
		{
			Motor->Rotate(Angle - 90);
			Angle = 90;
		}

		return;
	}
	Motor->Brake();
	delay(60);


	if (!ClockWise)
		Angle += 10;

	if (ClockWise)
		Angle-= 10;

}


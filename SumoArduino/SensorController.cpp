#include "SensorController.h"
#include <Servo.h>
#include "Util.h"


void SensorController::Motor1TripInterrupt()
{
	Motor1TripCounter++;
	//Println("Motor1");
}

void SensorController::Motor2TripInterrupt()
{
	Motor2TripCounter++;
}

SensorController::SensorController(const uint8_t servoPin, const uint8_t echoPin, const uint8_t trigPin)
	: ServoPin(servoPin), EchoPin(echoPin), TrigPin(trigPin), ServoController(Servo()), Motor(nullptr), ClockWise(false), Angle(0)
{ }

void SensorController::Begin(const MotorController* const motor)
{
	pinMode(ServoPin, OUTPUT);
	pinMode(EchoPin, INPUT);
	pinMode(TrigPin, OUTPUT);
	ServoController.attach(ServoPin);
	Motor = motor;

	pinMode(2, INPUT);
	pinMode(3, INPUT);

	attachInterrupt(digitalPinToInterrupt(2), Motor1TripInterrupt, CHANGE);
	attachInterrupt(digitalPinToInterrupt(3), Motor2TripInterrupt, CHANGE);
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
		Angle -= 10;

}

volatile uint32_t SensorController::Motor1TripCounter = 0;
volatile uint32_t SensorController::Motor2TripCounter = 0;
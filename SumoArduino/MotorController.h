/*
 Name:		MotorController.h
 Created:	8/11/2018 16:48:00
 Edited:	8/11/2018 17:01:42
 Author:	Mads
 Purpose:	Interface definition for the motor controller.
*/

#pragma once
#include <Arduino.h>

//Class that is responsible for controlling the motor
class MotorController
{
private:
	const uint8_t _motorAControl1Pin;
	const uint8_t _motorAControl2Pin;
	const uint8_t _motorBControl1Pin;
	const uint8_t _motorBControl2Pin;

public:

	//Constructs a MotorController object. It takes two pins
	//per motor.
	MotorController(const uint8_t motorAControl1Pin, const uint8_t motorAControl2Pin, const uint8_t motorBControl1Pin, const uint8_t motorBControl2Pin);

	//We need to have a begin function to be called in setup,
	//because the constructor runs before any other code and
	//we depend on setup code in the hidden main function to
	//setup interrupts and ports.
	void Begin() const;


	//Starts the startup sequence that drives the sumo robot
	//to the border of the track and turns to face the other
	//robot.
	void Start() const;

	//Sets the motors to freewheel.
	void Freewheel() const;

	//Brake the motors.
	void Brake() const;

	//Turn the motors forward.
	void Forward() const;

	//Turn the left motor on and brake the right one.
	void TurnLeft() const;

	//Turn the right motor on and brake the left one.
	void TurnRight() const;

	//Turn the motors backwards.
	void Backwards() const;

	//Rotate the vehicle by an angle.
	void Rotate(const int16_t angle) const;
};


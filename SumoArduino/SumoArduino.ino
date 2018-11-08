// Name:    SumoArduino.ino
// Created: 01/11/2018 14:15
// Edited:  08/11/2018 17:27
// Author:  Mads
// Purpose: Program entrypoint.
// Made by Gruppe 5: Mads Bluhme, Frederik Schultz & Mads Beyer Mogensen

#define DEBUG 1

// ReSharper disable once CppUnusedIncludeDirective
#include <Servo.h> //Not used here, but deep library search fails if its not included.
#include <SensorController.h>
#include <MotorController.h>
#include "Util.h"
#include "Pins.h"



SensorController sensorController(Pins::SERVO, Pins::ECHO, Pins::TRIGGER);


// the setup function runs once when you press reset or power the board
void setup() {
	const MotorController* const motorController = 
		new MotorController(Pins::MOTORA_CONTROL1, Pins::MOTORA_CONTROL2, Pins::MOTORB_CONTROL1, Pins::MOTORB_CONTROL2);

	INITIALIZE_SERIAL(115200);
	PRINTLN("Begin program");
	sensorController.Begin(motorController);
	motorController->Begin();
	//motorController.Rotate(MotorController::DELAY_15_CONSTANT, false);
	motorController->Start();
}

// the loop function runs over and over again until power down or reset
void loop() {
	PRINTLN(SensorController::MotorATripCounter);
	PRINTLN(SensorController::MotorBTripCounter);
	//Serial.println(digitalRead(2));
	//Serial.println(digitalRead(3));
	//controller.Loop();
	
}

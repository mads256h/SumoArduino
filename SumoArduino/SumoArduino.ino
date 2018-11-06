//_DEBUG is for visual studio vMicro only. So we define it here if it does not exist
#ifndef _VMICRO_INTELLISENSE
#define _DEBUG 0
#endif

#include <SensorController.h>
#include <MotorController.h>
#include "Util.h"

/*
 Name:		SumoArduino.ino
 Created:	9/25/2018 7:37:38 PM
 Author:	Mads
*/

//Pins that support pwm: 3, 5, 6, 9, 10, 11
//We need four pins for the motors.

constexpr uint8_t Motor1Pin1 = 6;
constexpr uint8_t Motor1Pin2 = 9;

constexpr uint8_t Motor2Pin1 = 10;
constexpr uint8_t Motor2Pin2 = 11;

//We need 6 pins for the 3 sensors: 2*3
//Available pins: 0, 1, 2, 3, 4, 5, 7, 8, 12, 13

SensorController controller(3, 4, 5);


// the setup function runs once when you press reset or power the board
void setup() {
	const MotorController* const motorController = new MotorController(9, 8, 10, 11);

#if 1
	Serial.begin(115200);
#endif
	Println("Begin program");
	controller.Begin(motorController);
	motorController->Begin();
	//motorController.Rotate(MotorController::DELAY_15_CONSTANT, false);
	motorController->Start();
}

// the loop function runs over and over again until power down or reset
void loop() {
	Println(SensorController::Motor1TripCounter);
	Println(SensorController::Motor2TripCounter);
	//Serial.println(digitalRead(2));
	//Serial.println(digitalRead(3));
	//controller.Loop();
	
}

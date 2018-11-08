//When DEBUG is 1 the Arduino sends serial data using the Print macros.
//When its 0 the Print macros are just noops.
#define DEBUG 1

#include <Servo.h>
#include <SensorController.h>
#include <MotorController.h>
#include "Util.h"

/*
 Name:		SumoArduino.ino
 Created:	9/25/2018 7:37:38 PM
 Author:	Mads
*/


SensorController controller(3, 4, 5);


// the setup function runs once when you press reset or power the board
void setup() {
	const MotorController* const motorController = new MotorController(9, 8, 10, 11);

	InitializeSerial(115200);
	Println("Begin program");
	controller.Begin(motorController);
	motorController->Begin();
	//motorController.Rotate(MotorController::DELAY_15_CONSTANT, false);
	motorController->Start();
}

// the loop function runs over and over again until power down or reset
void loop() {
	Println(SensorController::MotorATripCounter);
	Println(SensorController::MotorBTripCounter);
	//Serial.println(digitalRead(2));
	//Serial.println(digitalRead(3));
	//controller.Loop();
	
}

#include <iostream>
using namespace std;
#include "car.h"

Car::Car()
{

}
Car::Car(char *name, int fuel, int speed)
{
	setID(name);
	setFuel(fuel);
	setSpeed(speed);
	Car();
}

void Car::ShowState()
{
	//printf("%s\n", gamerID);
	cout << gamerID << endl;
	cout << "연료량 : " << fuelGauge << "%" << endl;
	cout << "현재 속도 : " << currentSpeed << "km/s" << endl << endl;
}

void Car::Accel()
{
	if (fuelGauge < Accel_Fuel)
		return;
	else
		fuelGauge -= Accel_Fuel;
	if (currentSpeed + 10 >= MaxSpeed)
	{
		currentSpeed = MaxSpeed;
		return;
	}
	currentSpeed += Accel_Speed;
}

void Car::Break()
{
	if (currentSpeed < Break_Speed)
	{
		currentSpeed = 0;
		return;
	}
	currentSpeed -= Break_Speed;
}

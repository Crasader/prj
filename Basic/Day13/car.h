#pragma once
#include <string>

class Car
{
private:
	int MaxSpeed = 100;
	int Accel_Fuel = 2;
	int Accel_Speed = 10;
	int Break_Speed = 10;

private:
	std::string gamerID;
	int fuelGauge;
	int currentSpeed;

public:
	void ShowState();
	void Accel();
	void Break();

	void setID(std::string name)
	{
		gamerID = name;
	}
	void setFuel(int fuel)
	{
		fuelGauge = fuel;
	}
	void setSpeed(int speed)
	{
		currentSpeed = speed;
	}

public:
	Car::Car();
	Car::Car(char *name, int fuel, int speed);
};

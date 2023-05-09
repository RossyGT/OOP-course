#include "FuelTank.h"
#include "insufficient_fuel_error.h"
#include <cstring>
#pragma warning(disable: 4996)


FuelTank::FuelTank()
	: capacity(8), currentFullness(8)
{

}

FuelTank::FuelTank(unsigned capacity)
{
	setCapacity(capacity);
}

unsigned FuelTank::getCapacity() const
{
	return capacity;
}

void FuelTank::fill(double amount)
{
	if (currentFullness + amount >= capacity)
	{
		currentFullness = capacity;
	}
	currentFullness += amount;
}

unsigned FuelTank::getCurrentFullness() const
{
	return currentFullness;
}

void FuelTank::use(double amount)
{
	if (currentFullness -= amount < 0)
	{
		throw insufficient_fuel_error("using more fuel than is available");
	}
	currentFullness -= amount;
}
void  FuelTank::setCapacity(unsigned capacity)
{
	this->capacity = capacity;
	currentFullness = this->capacity;
}
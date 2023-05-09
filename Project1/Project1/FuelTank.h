#pragma once
#include "CarPart.h"

class FuelTank 
{
public: 
	FuelTank();
	FuelTank(unsigned capacity);

	unsigned getCapacity() const;
	unsigned getCurrentFullness() const;
	void setCapacity(unsigned capacity);

	void use(double amount); // -
	void fill(double amount); // +

private:
	unsigned capacity;
	unsigned currentFullness;
};


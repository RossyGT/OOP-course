#pragma once
#include "CarPart.h"
#include <iostream>

class Accumulator : public CarPart
{
public:
	Accumulator();
	Accumulator(const char* idPart, const char* manufacture, const char* desc, int capacity, const  char* batteryId);

	void setBatteryId(const char* batteryId);
	friend std::ostream& operator<<(std::ostream& os, const Accumulator& acc);
private:
	int capacity;
	char batteryId[15];
};


#include "Accumulator.h"
#include <stdexcept>
#include <cstring>
#pragma warning(disable: 4996)
Accumulator::Accumulator()
	: CarPart(), capacity(0)
{
	setBatteryId("Unknown");

}

Accumulator::Accumulator(const char* idPart, const char* manufacture, const char* desc, int capacity, const char* batteryId)
	: CarPart(idPart, manufacture, desc), capacity(capacity)
{
	setBatteryId(batteryId);
}

void Accumulator::setBatteryId(const char* batteryId)
{
	if (!batteryId)
	{
		throw std::exception("Nullptr for batteryId!");
	}
	strcpy(this->batteryId, batteryId);
}

std::ostream& operator<<(std::ostream& os, const Accumulator& acc)
{
	os << (const CarPart&)acc << " - " << acc.capacity << " Ah" << std::endl;
	return os;
}

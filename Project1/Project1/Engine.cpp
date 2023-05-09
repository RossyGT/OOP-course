#include "Engine.h"
#include <stdexcept>

Engine::Engine()
	: CarPart(), hoursepower(100)
{
}

Engine::Engine(const char* idPart, const char* manufacture, const char* desc, int hoursepower)
	: CarPart(idPart, manufacture, desc) 
{
	setHoursepower(hoursepower);
}

void Engine::setHoursepower(int hoursepower)
{
	if (hoursepower<0)
	{
		throw std::exception("Hoursepower <0 ");
	}
	this->hoursepower = hoursepower;
}

const int Engine::getHoursePower() const
{
	return hoursepower;
}

std::ostream& operator<<(std::ostream& os, const Engine& eg)
{
	os << (const CarPart&)eg << " - " << eg.hoursepower << "hp" << std::endl;
	return os;
}

#include "Tire.h"
#include <stdexcept>
#include <cstring>

#pragma warning(disable: 4996)
Tire::Tire()
	: CarPart(), width(155), profile(30), diameter(13)
{
	
}

Tire::Tire(const char* idPart, const char* manufacture, const char* desc, int width, int profile, int diameter)
	:CarPart(idPart,manufacture,desc)
{
	setWidth(width);
	setProfile(profile);
	setDiameter(diameter);
}

void Tire::setWidth(int width)
{
	if (width<=155 && width>=365)
	{
		throw std::out_of_range("Number must be in range between 155 and 365");
	}
	this->width = width;
}

void Tire::setProfile(int profile)
{
	if (profile <= 30 && profile >= 80)
	{
		throw std::out_of_range("Profile must be in range between 30 and 80");
	}
	this->profile = profile;
}

void Tire::setDiameter(int diameter)
{
	if (diameter <= 13 && diameter >= 21)
	{
		throw std::out_of_range("Diameter must be in range between 13 and 21");
	}
	this->diameter = diameter;
}

std::ostream& operator<<(std::ostream& os, const Tire& tr)
{
	os << (const CarPart&)tr << " - " << tr.width << "/" << tr.profile << "R" << tr.diameter << std::endl;
	return os;
}

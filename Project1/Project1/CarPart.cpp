#include "CarPart.h"
#include <stdexcept>
#include <cstring>
#pragma warning(disable: 4996)

CarPart::CarPart()
	: idPart(nullptr), manufacture(nullptr), description(nullptr)
{
	setIdPart("Unknown");
	setDescription("Unknown");
	setManufacture("Unknown");
}

CarPart::CarPart(const char* idPart, const char* manufacture, const char* desc)
{
	setIdPart(idPart);
	setManufacture(manufacture);
	setDescription(desc);
}

CarPart::CarPart(const CarPart& other)
{
	copyFrom(other);
}

CarPart& CarPart::operator=(const CarPart& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

CarPart::CarPart(CarPart&& other) noexcept
{
	moveFrom(std::move(other));
}

CarPart& CarPart::operator=(CarPart&& other) noexcept
{
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other)); 
	}
	return *this;
}

const char* CarPart::getIdPart() const
{
	return idPart;
}

const char* CarPart::getManufacture() const
{
	return manufacture;
}

const char* CarPart::getDescription() const
{
	return description;
}

void CarPart::setIdPart(const char* idPart)
{
	if (!idPart) // idPart == nullptr
	{
		throw std::exception("Nullptr for idPart!");
	}
	this->idPart = new char[strlen(idPart) + 1];
	strcpy(this->idPart, idPart);

}

void CarPart::setManufacture(const char* manufacture)
{
	if (!manufacture) // manufacture == nullptr
	{
		throw std::exception("Nullptr for manufacture!");
	}
	this->manufacture = new char[strlen(manufacture) + 1];
	strcpy(this->manufacture, manufacture);
}

void CarPart::setDescription(const char* desc)
{
	if (!desc) // desc == nullptr
	{
		throw std::exception("Nullptr for description!");
	}
	this->description = new char[strlen(desc) + 1];
	strcpy(this->description, desc);
}

CarPart::~CarPart()
{
	free();
}

void CarPart::copyFrom(const CarPart& other)
{
	this->idPart = new char[strlen(other.idPart) + 1];
	strcpy(this->idPart, other.idPart);
	this->manufacture = new char[strlen(other.manufacture) + 1];
	strcpy(this->manufacture, other.manufacture);
	this->description = new char[strlen(other.description) + 1];
	strcpy(this->description, other.description);
}

void CarPart::free()
{
	delete[] idPart;
	idPart = nullptr;
	delete[] manufacture;
	manufacture = nullptr;
	delete[] description;
	description = nullptr;
}

void CarPart::moveFrom(CarPart&& other)
{
	this->idPart = other.idPart;
	this->manufacture = other.manufacture;
	this->description = other.description;
	other.idPart = nullptr;
	other.manufacture = nullptr;
	other.description = nullptr;
}

std::ostream& operator<<(std::ostream& os, const CarPart& other)
{
	os << "(" << other.idPart << ") by " << other.manufacture << " - " << other.description;
	return os;
}

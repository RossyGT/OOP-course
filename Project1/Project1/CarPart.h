#pragma once
#include<iostream>
class CarPart
{
public:
	CarPart();
	CarPart(const char* idPart, const char* manufacture, const char* desc);
	// copy operator 
	CarPart(const CarPart& other);
	CarPart& operator=(const CarPart& other);

	//move things for practice
	CarPart(CarPart&& other) noexcept; 
	CarPart& operator=(CarPart&& other) noexcept;

	const char* getIdPart() const;
	const char* getManufacture()const;
	const char* getDescription()const;

	void setIdPart(const char* idPart);
	void setManufacture(const char* manufacture);
	void setDescription(const char* desc);
	friend std::ostream& operator<<(std::ostream& os, const CarPart& other);
	~CarPart();
private:
	char* idPart;// идентификатор
	char* manufacture;// производител
	char* description;// описание

	void copyFrom(const CarPart& other);
	void free();
	void moveFrom(CarPart&& other);
};


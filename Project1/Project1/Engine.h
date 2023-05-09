#pragma once
#include <iostream>
#include "CarPart.h"

class Engine : public CarPart
{
public:
	Engine();
	Engine(const char* idPart, const char* manufacture, const char* desc, int hoursepower);
	//this can be avoided if the type is unsigned
	void setHoursepower(int hoursepower);
	const int getHoursePower()const;
	friend std::ostream& operator<<(std::ostream& os, const Engine& eg);
private:
	int hoursepower;

};


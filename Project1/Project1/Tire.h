#pragma once
#include "CarPart.h"
#include <iostream>
class Tire : public CarPart
{
public:
	Tire();
	Tire(const char* idPart, const char* manufacture, const char* desc, int width, int profile, int diameter);

	void setWidth(int width);
	void setProfile(int profile);
	void setDiameter(int diameter);
	 friend std::ostream& operator<<(std::ostream& os, const Tire& eg);


private:
	int width;
	int profile;
	int diameter;
};


#pragma once
#include <stdexcept>
#include <cstring>
#pragma warning(disable: 4996)
class insufficient_fuel_error : public std::logic_error
{
public:

	insufficient_fuel_error(const char* message)
		:std::logic_error(message)
	{
		
	}
	
};


#include <iostream>
#include "Car.h"
#include "Accumulator.h"
#include "Engine.h"
#include "FuelTank.h"
#include "Tire.h"

int main()
{
	try
	{
		Accumulator accumulator("123", "Bosch", "Mnogo dobri", 200, "300");
		Tire tires[] ={ Tire("334", "Radar", "Stava", 20, 30, 12), Tire("335", "Radar", "Stava", 20, 30, 12), Tire("336", "Radar", "Stava", 20, 30, 12), Tire("337", "Radar", "Stava", 20, 30, 12) };
		//FuelTank fuelTank(23);
		Engine engine("456", "Renault", "ok", 200);
		double passedKM = 20;
		double weight = 330;
		unsigned capacityFuelTank1 = 60;
		unsigned capacityFuelTank2 = 70;
		Car golf(engine, tires, accumulator, passedKM,  weight, capacityFuelTank1);
		golf.drive(40);
		Car audi(engine, tires, accumulator, passedKM, weight, capacityFuelTank2);
		audi.drive(55);

		Car* winner = dragRace(&golf, &audi);


		if (winner != nullptr)
			std::cout << winner->getFuleTank().getCapacity()<<" capacity " <<winner->getFuleTank().getCurrentFullness()<<"curentFullness"<< std::endl;
		else
			std::cout << "Equal" << std::endl;
	}
	catch (const std::logic_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (std::out_of_range& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	/*catch (...)
	{
		
	}*/
}
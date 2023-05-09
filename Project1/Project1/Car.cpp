#include "Car.h"
#include <cmath>
Car::Car(const Engine& engine, const Tire* tires, const Accumulator& accumulator, double passedKM, double weight, unsigned capacity)
	: _engine(engine), _accumulator(accumulator), _passedKM(passedKM), _weight(weight)
{
	setTires(tires);
	setCapacityCar(capacity);

}

void Car::setCapacityCar(const unsigned capacity)
{
	FuelTank result(capacity);
	this->_fuelTank = result;


}

int getTiers(const Tire* tr)
{
	int counter = 0;
	while (tr)
	{
		counter++;
		tr++;
	}
	return counter;
}
void Car::setTires(const Tire* tr)
{
	if (getTiers(tr)!= 4)
	{
		throw std::exception("Òires are different from 4");

	}
	for (int i = 0; i < 4; i++)
	{
		_tires[i] = tr[i];
	}
}

const Engine& Car::getEngine() const
{
	return _engine;
}

const FuelTank& Car::getFuleTank() const
{
	return _fuelTank;
}
unsigned int Logn(unsigned int n, unsigned int r)
{
	return (n > r - 1) ? 1 +
		Logn(n / r, r) : 0;
}
bool Car::drive(double km)
{
	bool flag = false;
	this->_passedKM += km;

	double f = ((Logn(3.6, _engine.getHoursePower()) + Logn(8, this->_weight)) / 100)*_passedKM;

	if (_fuelTank.getCapacity()>f)
	{
		_fuelTank.use(f);
		flag = true;
	}
	return flag;
}

Car* dragRace(Car* car1, Car* car2)
{
	bool resultCar1 = car1->drive(0.4);
	bool resultCar2 = car2->drive(0.4);
	if (resultCar1 && resultCar2)
	{
		double temp1 = car1->getEngine().getHoursePower();
		double temp2 = car2->getEngine().getHoursePower();
		return (temp1 > temp2) ? car1 : car2;
	}
	else if (!(resultCar1 && resultCar2) )
	{
		return nullptr;
	}
	else
	{
		if (resultCar1)
		{
			return car1;
		}
		else
			return car2;
	}
}

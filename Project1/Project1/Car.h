#pragma once
#include "Tire.h"
#include "FuelTank.h"
#include "Accumulator.h"
#include "Engine.h"
class Car 
{
public:
	Car(const Engine& engine, const Tire* tires, const Accumulator& accumulator, double passedKM, double weight, unsigned capacity);
	
	void setCapacityCar(const unsigned capacity);
	void setTires(const Tire* tr);
	const Engine& getEngine()const;
	const FuelTank& getFuleTank()const;
	bool drive(double km);

private:

	FuelTank _fuelTank;
	Engine _engine;
	Tire _tires[4];
	Accumulator _accumulator;
	double _passedKM;
	double _weight;

};
Car* dragRace(Car* car1, Car* car2);

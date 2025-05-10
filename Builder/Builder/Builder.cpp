// Builder.cpp : Seperate construction of complex object from representation, 
// so that same construction process can create different representation .
//

#include "Builder.h"
#include <iostream>
#include <string>

using namespace std;

class Car
{
public:
	std::string engine;
	std::string wheel;
	std::string seat;

public:
	void show()
	{
		std::cout << "Engine - " << engine << std::endl;
		std::cout << "Wheel - " << wheel << std::endl;
		std::cout << "Seat - " << seat << std::endl;
	}
};

/*Define Abstract Builder */

class CarBuilder
{
public:
	virtual ~CarBuilder() = default;
	virtual void buildEngine() = 0;
	virtual void buildWheels() = 0;
	virtual void buildSeats() = 0;
	virtual Car getResult() = 0;
};

class SportsCarBuilder : public CarBuilder {
private:
	Car car;
public:
	void buildEngine() override {
		car.engine = "V8 Engine";
	}

	void buildWheels() override {
		car.wheel = "Sports wheels";
	}

	void buildSeats() override {
		car.seat = "Leather seats";
	}

	Car getResult() override {
		return car;
	}
};

/* Define Director Class*/

class Director
{
public:
	CarBuilder* builder;
	Director(CarBuilder* cb) :builder(cb)
	{

	}
	void construct() {
		builder->buildEngine();
		builder->buildWheels();
		builder->buildSeats();
	}
};

int main()
{
	cout << "Builder Demo." << endl;
	SportsCarBuilder builder;
	Director director(&builder);
	director.construct();
	// Get the result (the car)
	Car car = builder.getResult();
	car.show();
	return 0;
}

// Bridge.cpp :Decouple an abstraction from its implementation so that the two can vary independently..
//

#include "Bridge.h"
using namespace std;

class Switch {

public:
	virtual ~Switch() = default;
	virtual void turnON() = 0;
	virtual void turnOFF() = 0;
};

class ElectricSwitch : public Switch {
public:
	void turnON() override { std::cout << "Electric switch: Machine ON" << std::endl; }
	void turnOFF() override { std::cout << "Electric switch: Machine OFF" << std::endl; }
};

class ManualSwitch : public Switch {
public:
	void turnON() override { std::cout << "Manual switch: Machine ON" << std::endl; }
	void turnOFF() override { std::cout << "Manual switch: Machine OFF" << std::endl; }
};

// Abstraction: Machine
class Machine {
protected:
	Switch* switchMechanism;
public:
	Machine(Switch* switchType) : switchMechanism(switchType) {}
	virtual void switchOn() = 0;
	virtual void switchOff() = 0;
};

// Refined Abstraction: WashingMachine
class WashingMachine : public Machine {
public:
	WashingMachine(Switch* switchType) : Machine(switchType) {}

	void switchOn() override { switchMechanism->turnON(); }
	void switchOff() override { switchMechanism->turnOFF(); }
};

int main() {
	Switch* electricSwitch = new ElectricSwitch();
	Machine* wm = new WashingMachine(electricSwitch);

	wm->switchOn();
	wm->switchOff();

	delete wm;
	delete electricSwitch;

	return 0;
}
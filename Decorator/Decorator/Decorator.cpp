
//The Decorator Design Pattern allows you to add new functionality to an object dynamically without altering its structure
//.It involves a base component, concrete components, and decorators that wrap the base component to extend its behavior.

#include <iostream>
using namespace std;

// Base Component
class Coffee {
public:
    virtual double cost() = 0;
    virtual ~Coffee() {}
};

// Concrete Component
class SimpleCoffee : public Coffee {
public:
    double cost() override {
        return 5.0;  // Simple coffee cost
    }
};

// Decorator Base Class
class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;  // Component to be decorated
public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}
    virtual double cost() = 0;
    virtual ~CoffeeDecorator() { delete coffee; }
};

// Concrete Decorators
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}
    double cost() override {
        return coffee->cost() + 1.5;  // Add milk cost
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* c) : CoffeeDecorator(c) {}
    double cost() override {
        return coffee->cost() + 0.5;  // Add sugar cost
    }
};

int main() {
    Coffee* myCoffee = new SimpleCoffee();
    cout << "Cost of Simple Coffee: $" << myCoffee->cost() << endl;

    myCoffee = new MilkDecorator(myCoffee);
    cout << "Cost of Coffee with Milk: $" << myCoffee->cost() << endl;

    myCoffee = new SugarDecorator(myCoffee);
    cout << "Cost of Coffee with Milk and Sugar: $" << myCoffee->cost() << endl;

    delete myCoffee;
    return 0;
}

// AbstractFact.cpp : Defines the entry point for the application.
//

#include "AbstractFact.h"

using namespace std;

/*
* Abstract Factory - Provide interface for creating a families of related dependent object without specificing cpncreate class
*/

class Shape
{
public:
	Shape() = default;
	virtual void draw() = 0;
};

class Circle :public Shape
{
public:
	void draw() override
	{
		std::cout << "Circle" << std::endl;
	}
};

class Square :public Shape
{
public:
	void draw() override
	{
		std::cout << "Square" << std::endl;
	}
};

class Rectangle :public Shape
{
public:
	void draw() override
	{
		std::cout << "Rectangle" << std::endl;
	}
};

class Eclipse :public Shape
{
public:
	void draw() override
	{
		std::cout << "Eclipse" << std::endl;
	}
};

/*--------------------------------Factory and Abstract Factory--------------*/

class Factory
{
public:
	virtual Shape* CreateCurveInstance() = 0;
	virtual Shape* CreateStraightInstance() = 0;
};

class CurveSimpleShapedFactory :public Factory
{
public:
	Shape* CreateCurveInstance()
	{
		return new Circle;
	}
	Shape* CreateStraightInstance()
	{
		return new Square;
	}
};

class CurveRobustShapeFactory :public Factory
{
public:
	Shape* CreateCurveInstance()
	{
		return new Eclipse;
	}
	Shape* CreateStraightInstance()
	{
		return new Rectangle;
	}
};
int main()
{
	cout << "Abstract Factory Demo." << endl;
	Factory* fact = new CurveSimpleShapedFactory();
	Shape* sh = fact->CreateCurveInstance();
	sh->draw();
	return 0;
}

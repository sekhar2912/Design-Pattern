/*
What is the Prototype Pattern?
The Prototype Pattern is used to create new objects by copying an existing object (a prototype). 
It’s useful when object creation is expensive or complex, and cloning is more efficient.
*/

#include <iostream>
#include <string>

using namespace  std; 

class Shape{
    protected:
    int _id =0;
    public:
    Shape(int id):_id(id){}
    virtual ~Shape() {}
    virtual Shape* clone() const = 0;
    virtual void draw() const = 0;
};

class Circle : public Shape{
    public:
     Circle(int r) : Shape(r) {}
    
    // Copy constructor
    Circle(const Circle& other) : Shape(other._id) {}

    Shape* clone() const override {
        return new Circle(*this); // clone using copy constructor
    }

    void draw() const override {
        cout << "Drawing a circle with radius " << _id << endl;
    }
};

int main()
{
    Shape* original = new Circle(1);
    original->draw();

     // Clone the object
    Shape* clone = original->clone();
    clone->draw();

    delete original;
    delete clone;
    return 0;
}

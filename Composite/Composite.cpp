/*
Purpose: Treat individual objects and compositions (groups of objects) uniformly.

Example: Drawing shapes — a group of shapes (like a picture) behaves like a single shape.
*/

#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Shape{

    public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw()  override {
        cout << "Drawing Circle\n";
    }
};

// Leaf
class Square : public Shape {
public:
    void draw()  override {
        cout << "Drawing Square\n";
    }
};

// Composite

class Composite: public Shape
{
    private:
     vector<unique_ptr<Shape>> shapes;
    public:
      void add(unique_ptr<Shape> s) { shapes.push_back(move(s)); }
      void draw() override
      {
         for (auto& s : shapes) s->draw();
      }
};

int main()
{
    Composite grp;
    grp.add(std::make_unique<Circle>());
     grp.add(std::make_unique<Square>());
     grp.draw();
    return 0;
}
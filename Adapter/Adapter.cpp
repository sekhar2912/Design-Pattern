#include <iostream>
#include <string>
using namespace std;

class Rectangle
{
public:
    virtual void Draw() =0;
};

class LegacyRectanagle 
{

private:
    int coord_1;
    int coord_2;
    int coord_3;
    int coord_4;

public:
    LegacyRectanagle(int x1, int x2, int y1, int y2) : coord_1(x1), coord_2(x2), coord_3(y1), coord_4(y2)
    {
        cout << "LegacyRectangle:  create.  (" << x1 << "," << y1 << ") => ("
             << x2 << "," << y2 << ")" << endl;
    }
    void OLDDraw()
    {
        std::cout << "OLD Draw" << std::endl;
    }
};

class RectangleAdapter:public Rectangle, public LegacyRectanagle
{
public:
    RectangleAdapter(int c1, int c2, int c3, int c4) : LegacyRectanagle(c1, c2, c1 + c3, c2 + c4) {}

    void Draw() override
    {
        cout << "RectangleAdapter: draw." << endl;
        OLDDraw();
    }
};

int main()
{
    Rectangle *r = new RectangleAdapter(120, 200, 60, 40);
    r->Draw();
    return 0;
}
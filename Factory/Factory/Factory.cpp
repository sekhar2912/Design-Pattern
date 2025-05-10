// Factory.cpp : Defines an interface for creating an object but let subclass decide which class to instintiate
//

#include "Factory.h"
#include <vector>

using namespace std;
class Stooge
{
public:
	static Stooge* make_stooge(int choice);
	virtual void slap_stick() = 0;
};

class Larry : public Stooge
{
public:
    void slap_stick()
    {
        cout << "Larry: poke eyes\n";
    }
};
class Moe : public Stooge
{
public:
    void slap_stick()
    {
        cout << "Moe: slap head\n";
    }
};
class Curly : public Stooge
{
public:
    void slap_stick()
    {
        cout << "Curly: suffer abuse\n";
    }
};
Stooge* Stooge::make_stooge(int choice)
{
    Stooge* mStooge = nullptr;
    switch (choice)
    {
    case 1:
        mStooge = new Larry;
        break;
    case 2:
        mStooge = new Moe;
        break;
    case 3:
        mStooge = new Curly;
        break;
    default:
        std::cout << "Invalid \n";
    }
    return mStooge;
}
int main()
{
	cout << "Hello CMake." << endl;
    Stooge* sp = Stooge::make_stooge(1);
    sp->slap_stick();

	return 0;
}

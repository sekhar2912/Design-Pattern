#include <iostream>
#include <vector>

using namespace std;

class Subject
{

    std::vector<class Observer *> views;
    int value;

public:
    void attach(Observer *obs)
    {
        views.push_back(obs);
    }

    void setVal(int val)
    {
        value = val;
        notify();
    }

    void notify();
};

class Observer
{
private:
    Subject *model;
    ;
    int demon;

public:
    Observer(Subject *mo)
    {
        model = mo;
        model->attach(this);
    }
    virtual void update() = 0;
};

class DivObserver : public Observer
{
public:
    DivObserver(Subject *mo) : Observer(mo) {}
    void update()
    {
        std::cout << "DivObserver - Notifier" << std::endl;
    }
};

class ModObserver : public Observer
{
public:
    ModObserver(Subject *mo) : Observer(mo) {}
    void update()
    {
        std::cout << "ModObserver - Notifier" << std::endl;
    }
};

void Subject::notify()
{
    // 5. Publisher broadcasts
    for (int i = 0; i < views.size(); i++)
        views[i]->update();
}

int main()
{
    Subject s;
    DivObserver div{&s};
    ModObserver mod{&s};
    s.setVal(14);
}
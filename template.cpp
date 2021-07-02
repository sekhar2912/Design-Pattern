#include <iostream>

using namespace std;

class worker{
public:
virtual void work_1() = 0;
virtual void work_2() = 0;

void execute()
{
    work_1();
    work_2();
}
};

class Robbot: public worker{

    public:
    Robbot() = default;
    void work_1() override {std::cout << "Roboot -Task1"<< std::endl;}
    void work_2() override {std::cout << "Roboot -Task2"<< std::endl;}
};

class Human: public worker{

    public:
    Human() = default;
    void work_1() override {std::cout << "Human Task 1 "<< std::endl;}
    void work_2() override {std::cout << "Human Task 2 "<< std::endl;}
};

int main()
{
    worker *arr [] = {new Robbot(), new Human()};
    for (int i = 0; i < 2; i++)
  {
    arr[i]->execute();
    cout << '\n';
  }
    return 0;
}
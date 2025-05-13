/*Purpose: Provide a unified and simplified interface to a complex system of subsystems.*/

#include <iostream>
using namespace std;

// Subsystem
class CPU
{
  public:
  void start() { std::cout <<"CPU- Started"<< std::endl;}
};

class Memory
{
public:
void Load() { std::cout <<"Memory- Loaded"<< std::endl;}
};

class HardDrive
{
public:
void Start() { std::cout << "Hard-disl started " << std::endl;}
};

// Facade
class Computer {
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
public:
    void start()
     {
        cpu.start();
        memory.Load();
        hardDrive.Start();
    }
};

int main()
{
    Computer cm;
    cm.start();
    return 0;
}
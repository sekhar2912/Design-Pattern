// Singleton.cpp : Defines the entry point for the application.
//

#include "Singleton.h"
#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
private:
	static Singleton* instance;
	static std::mutex mtx;
	int data;
	Singleton(int d) :data(d) {}

public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton* getInstance(int val)
	{
		if (instance == nullptr)
		{
			std::lock_guard<std::mutex> guard(mtx);
			if (instance == nullptr)
				instance = new Singleton(val);
		}
		return instance;
	}
	void ShowData() { std::cout << data << endl; }
	~Singleton() { delete instance; }

};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

int main()
{
	cout << "Hello CMake." << endl;
	std::thread t1(Singleton::getInstance(1));
	std::thread t2(Singleton::getInstance(2));
	t1.join();
	t2.join();
	return 0;
}

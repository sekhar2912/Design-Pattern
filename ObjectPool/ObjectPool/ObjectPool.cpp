// ObjectPool.cpp : Defines the entry point for the application.
//

#include "ObjectPool.h"
#include <string>
#include <list>
using namespace std;

class Resource
{
private:
	int value{ 0 };

public:
	void reset() { value = 0; }
	int getVal() { return value; }
	void setVal(int val) {  value = val; }
};

class ObjectPool
{
private:
	std::list<Resource*> resources;
public:
	static ObjectPool* instance;
	static ObjectPool* getInstance()
	{
		if (instance == nullptr)
			return new ObjectPool;
		return instance;
	}
	Resource* getResource()
	{
		if (resources.empty())
			return new Resource;
		else
		{
			Resource* resource = resources.front();
			resources.pop_front();
			return resource;
		}
	}
	void returnResource(Resource* object)
	{
		object->reset();
		resources.push_back(object);
	}
};

ObjectPool* ObjectPool::instance = nullptr;
int main()
{
	cout << "Hello CMake." << endl;
	ObjectPool* pool = ObjectPool::getInstance();
	Resource* one;
	Resource* two;
	/* Resources will be created. */
	one = pool->getResource();
	one->setVal(10);
	return 0;
}

#include <iostream>
#include <list>

using namespace std;

class Object{

    private:
     int val;

    public:
    Object():val(0){}
    int getVal(){ return val;}
    void setVal(int num) { val = num;}
    void reset()
        {
            val = 0;
        }

};

class ObjectPool{

    private:
    std::list<Object*> resources;
    static ObjectPool* instance;
    
    public:
    ObjectPool() {}
    static ObjectPool* getInstance(){
        if(instance == nullptr)
        {
            instance = new ObjectPool;
        }
        return instance;
    }

    Object* getResource()
    {
        if (resources.empty())
          return new Object;
        else
        {
            Object* resource = resources.front();
            resources.pop_front();
            return resource;
        }
        
    }

    void returnToPool(Object* res)
    {
             res->reset();
             resources.push_back(res);

    }

};

ObjectPool* ObjectPool::instance = 0;

int main()
{

    ObjectPool* pool = ObjectPool::getInstance();
    Object* one;
    Object* two;
    /* Resources will be created. */
    one = pool->getResource();
    one->setVal(10);
    std::cout << "one = " << one->getVal() << " [" << one << "]" << std::endl;
    two = pool->getResource();
    two->setVal(20);
    std::cout << "two = " << two->getVal() << " [" << two << "]" << std::endl;
    pool->returnToPool(one);
    pool->returnToPool(two);
    /* Resources will be reused.
     * Notice that the value of both resources were reset back to zero.
     */
    one = pool->getResource();
    std::cout << "one = " << one->getVal() << " [" << one << "]" << std::endl;
    two = pool->getResource();
    std::cout << "two = " << two->getVal() << " [" << two << "]" << std::endl;
    return 0;
}
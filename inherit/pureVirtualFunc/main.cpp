#include <iostream>

#define BUFFER_SIZE 32

class Person
{
public:

    Person()
    {
        std::cout<<"构造"<<std::endl;
    }
    ~Person()
    {
        std::cout<<"析构"<<std::endl;
    }
public:
    /* 纯虚函数  */
    virtual int makeMoney() = 0;
    virtual int makeShop()
    {
        std::cout<<"shopping"<<std::endl;
    }
private:
    int m_age;
    
};
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
    virtual int makeMoney()
    {
        std::cout<<"make money"<<std::endl;
    }
    virtual int makeShop()
    {
        std::cout<<"shopping"<<std::endl;
    }
private:
    int m_age;
    
};

class Student : public Person
{
public:
    Student()
    {
        std::cout<<"构造"<<std::endl;
    }
    ~Student()
    {
        std::cout<<"析构"<<std::endl;
    }
public:
    /* 重写makeMoney函数 */
    int makeMoney()
    {
        /* 调用父类的函数 */
        Person::makeMoney();
        std::cout<<"make money -- cut hair"<<std::endl;
    }
    int makeShop()
    {
        std::cout<<"shopping clothes"<<std::endl;
    }

private:
    int m_no;
};

class Teacher : public Person
{
public:
   Teacher()
    {
        std::cout<<"构造"<<std::endl;
    }
    ~Teacher()
    {
        std::cout<<"析构"<<std::endl;
    }
public:
    /* 重写makeMoney函数 用virtual来修饰虚函数 */
    int makeMoney()
    {
        std::cout<<"make money -- on class"<<std::endl;
    }
    int makeShop()
    {
        std::cout<<"shopping home"<<std::endl;
    }

private:
    int m_hair;
};

int main()
{
    Person *per = new Student();
    per->makeMoney();


    per = new Teacher();
    per->makeMoney();


    return 0;
}
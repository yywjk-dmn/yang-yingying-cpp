#include <iostream>
#include <cstring>
#define BUFFER_SIZE 32

class Person
{
public:

    Person()
    {
        std::cout<<"构造"<<std::endl;
    }
    virtual ~Person()
    {
        std::cout<<"析构"<<std::endl;
    }
public:
    virtual int makeMoney()
    {
        std::cout<<"make money"<<std::endl;
    }

private:
    int m_age;
    
};

class Student : public Person
{
public:
    Student(const char * name)
    {
        std::cout<<"构造"<<std::endl;
        #if 0
        m_name = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        #else
        m_name = new char [BUFFER_SIZE];
        #endif
        strncpy(m_name, name, strlen(name) + 1);
    }
    ~Student()
    {
        if (m_name)
        {
            delete []m_name;
        }
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

private:
    int m_no;
    char * m_name;
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


private:
    int m_hair;
};

int main()
{
    // Person *per = new Student();
    // per->makeMoney();

    // per = new Teacher();
    // per->makeMoney();


    return 0;
}
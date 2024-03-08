#include <iostream>

int myHight()
{
    return 70;
}
int myAge()
{
    return 30;
}

class Person
{
public:
    int m_height;
    int m_age;
public:
    Person(int height, int age)
    {
        #if 0
        this->m_height = height;
        this->m_age = age;
        #elif0
        m_height = height;
        m_age = age;
        #else
        m_height = myHight();
        m_age = myAge();
        #endif
    }
    ~Person();
};

class Student
{
public:
    /* 初始化列表 */
    Student(int height, int age) : m_height(height), m_age(age){}
    #if 0
    /* 这个也可以用 */
    Student(int height, int age) : m_height(myHight()), m_age(myAge()){}
    #endif

public:
    int m_age;
    int m_height;
};

int main()
{
    Person person(180, 80);

    std::cout<<"person:age"<<person.m_age<<"person:height"<<person.m_height<<std::endl;


    return 0;
}
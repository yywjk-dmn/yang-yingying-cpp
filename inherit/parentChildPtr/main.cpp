#include <iostream>
#include <stdio.h>

class Person
{
public:
    Person()
    {
        std::cout<<"Person()"<<std::endl;
    }

    void printInfp()
    {
        printf("this:%p\n", this);

        std::cout<<"m_age"<<m_age<<std::endl;
    }
public:
    int m_age;

};

class Student : public Person
{
public:
    Student()
    {
        std::cout<<"Student()"<<std::endl;
    }
    void printfInfo()
    {
        printf("this:%p/n", this);
        std::cout<<"m_age"<<m_age<<"\tm_no"<<m_no<<std::endl;
    }
public:
    int m_no;
};

int main()
{
    Student stu1;
    printf("&stu:%p\n", &stu1);


    return 0;
}
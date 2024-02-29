#include <iostream>
#include "democlass.h"

int Student::getAge()
{
    return m_age;
}

void Student::setAge(int age)
{
    m_age = age;
}

int main()
{
    Student stu;
    stu.setAge(10);
    std::cout<<stu.getAge()<<std::endl;


    return 0;
}
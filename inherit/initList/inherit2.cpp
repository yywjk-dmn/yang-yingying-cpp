#include <iostream>

int g_data;

class Person
{
public:
    int m_age;
public:
    void run()
    {
        std::cout<<"Person::run()"<<std::endl;
    }




private:
};

#if 0
class Student
{
public:
    int m_age;
    int m_no;
public:
    void run()
    {

    }
    void study()
    {

    }


};
#else
/* 继承的语法  私有继承 */
class Student : private Person
{
public:
    int m_no;
public:
    void study()
    {
        std::cout<<"Student::study"<<std::endl;
    }

};


#endif

int main()
{
    Person person;
    int length = sizeof(person);
    std::cout<<"Student::study:"<<length<<std::endl;

    Student stu;
    /* Student可以访问到Person中的成员变量*/
    /* 私有继承娶不到属性 */
    stu.m_age = 22;
    stu.m_no = 1;
    length = sizeof(stu);
    std::cout<<stu.m_age<<","<<stu.m_no<<std::endl;
    std::cout<<"Student::study:"<<length<<std::endl;

    return 0;
}
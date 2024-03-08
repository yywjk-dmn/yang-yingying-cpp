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
/* 继承的语法  Student继承Person */
class Student : public Person
{
public:
    int m_no;
    static int m_room;
public:
    void study()
    {
        std::cout<<"Student::study"<<std::endl;
    }
    void printInfo()
    {
        std::cout<<m_no<<std::endl;

    }
    static void printfInfo()
    {
        /* 在静态方法中 this是对象 所以通过this能拿到的变量或者方法都拿不到 */
    }

};

int Student::m_room = 0;


#endif

int main()
{
    Person person;
    int length = sizeof(person);
    std::cout<<"Student::study:"<<length<<std::endl;

    Student stu;
    /* Student可以访问到Person中的成员变量*/
    stu.m_age = 22;
    stu.m_no = 1;
    length = sizeof(stu);
    std::cout<<stu.m_age<<","<<stu.m_no<<std::endl;
    std::cout<<"Student::study:"<<length<<std::endl;

    /* 静态成员变量可以直接访问 不依赖于对象 */
    Student::m_room = 101;

    return 0;
}
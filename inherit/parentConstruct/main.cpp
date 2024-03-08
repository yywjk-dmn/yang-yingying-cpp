#include <iostream>

class Person
{
private:
    int m_age;
public:
    Person() : Person(0){}
    Person(int age) : m_age(age){}
};

class Student : public Person
{
public:
    int m_no;
public:
    Student();
    Student(int age, int no) :  Person(30), m_no(3)
    {
        /* 私有属性 拿不到父类的age 所以用初始化列表 */

    }
    ~Student();
};

int main()
{
    
    Student stu;

    return 0;
}
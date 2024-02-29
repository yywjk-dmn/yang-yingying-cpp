#ifndef __DEMO_CLASS_H
#define __DEMO_CLASS_H

class Student
{
public:
    int getAge();
    void setAge(int age);
private:
    char m_name[20];
    int m_age;
};


#endif
#include <iostream>

#define BUFFER_SIZE 32

class Person
{
public:
    Person()
    {
        std::cout<<"Person()"<<std::endl;
        m_address = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        if (m_address == nullptr)
        {
            return;
        }
    }

    ~Person()
    {
        std::cout<<"~Person()"<<std::endl;

        if (m_address)
        {
            free(m_address);
            m_address = nullptr;
        }
    }
public:
    int m_age;
    char* m_address;
};

class Student : public Person
{
public:
    int m_no;
    char * m_name;

public:
    Student()
    {
        std::cout<<"Student()"<<std::endl;

        m_name = new char[BUFFER_SIZE];
    }
    ~Student()
    {
        std::cout<<"~Student()"<<std::endl;

        if (m_name)
        {
            delete []m_name;
            m_name = NULL;
        }
    }
};

int main()
{
    
    Student stu;

    return 0;
}
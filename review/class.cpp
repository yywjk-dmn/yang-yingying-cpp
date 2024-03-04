#include <iostream>
#include <stdio.h>

#if 0
struct Student
{
    int age;
    char *name;
};

class Student
{
public:
    char *name;
    int age;

    /* 类可以包含函数 */
    void printS()
    {
        printf("%s的年龄是： %d\n", name, age);
    }

};

void printS(Student &stu)
{
    printf("%s的年龄是： %d\n", stu.name, stu.age);
}

int main()
{
    Student stu1;

    /* C中的用法 */
    stu1.name = "小杨";
    stu1.age = 18;
    printS(stu1);

    /* 类的用法 */
    stu1.name = "小杨";
    stu1.age = 18;
    stu1.printS();

    return 0;
}
#endif

#if 0
class  Student
{
public:
    void setId(int id)
    {
        m_id = id;
    }
    int getId()
    {
        return m_id;
    }

    void setName(char * name)
    {
        m_name = name;
    }
    char * getName()
    {
        return m_name;  
    }

    void display()
    {
        std::cout<<"id = "<<m_id<<", name = "<<m_name<<std::endl;
    }
private:
    int m_id;
    char *m_name;
};

int main()
{
    Student stu;
    stu.setName("小杨");
    stu.setId(15);
    stu.display();

    return 0;
}
#endif

class Student
{
private:
    char *m_name;

public:
    void setname(char * name);
    void setge(int age);

public:
    void setname(float score);
    void show();

private:
    int m_age;
    float m_score;
};


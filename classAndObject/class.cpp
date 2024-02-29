#include <iostream>

class Student
{
public:

    /* 无参构造 */
    Student()
    {
        std::cout<<"构造！";
    }

    /* 有参构造 */
    Student(int age, const std::string &name)
    {
        m_age = age;
        m_name = name;
        std::cout<<"构造！";
    }

    /* 拷贝构造函数 */
    Student(const Student& stu)
    {
        std::cout<<"拷贝构造函数"<<std::endl;
        m_age = stu.m_age;
        m_name = stu.m_name;
    }

    void operator = (const Student& stu)
    {
        std::cout<<"赋值运算符的重载"<<std::endl;
    }
    void setAge(int age);
    int getAge();
    void setName(const std::string& name);
    /* 类内声明 */
    std::string getName();
private:
    int m_age;
    std::string m_name;

};

void Student::setAge(int age)
{
    m_age = age;
}

int Student::getAge()
{
    return m_age;
}

void Student::setName(const std::string &name)
{
    m_name = name;
}

/* 说明这个函数来自于类内 */
std::string Student::getName()
{
    return m_name;
}


int main()
{
    /* 用带参数的构造函数 可以直接初始化一个值 */
    Student stu(1, "zhangsan");
#if 0
    stu.setAge(10);
    stu.setName("zhangsan");
#endif
    std::cout<<stu.getAge()<<std::endl;

    /* 拷贝构造函数的另一种写法 */
    Student s1 = stu;
    Student s1(stu);

    /* 调用赋值运算符的重载函数 */
    Student s2;
    s2 = stu;

    std::cout<<stu.getAge()<<std::endl;

    Student *p = new Student;
    delete p;


    return 0;
}



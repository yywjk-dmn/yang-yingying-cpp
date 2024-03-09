#include <iostream>

class Person
{
public:
    Person()
    {
        std::cout<<"Person()"<<std::endl;
    }
    virtual ~Person()
    {
        std::cout<<"~Person()"<<std::endl;
    }
    void run()
    {
        std::cout<<"run()"<<std::endl;
    }
private:
    int m_age;

};

class Student : public Person
{
public:
    Student()
    {
        std::cout<<"Student()"<<std::endl;
    }
    ~Student()
    {
        std::cout<<"~Student()"<<std::endl;
    }
    void run()
    {
        std::cout<<"run()"<<std::endl;
    }
    void study()
    {
        std::cout<<"study()"<<std::endl;
    }
private:
    int m_score;
};

int main()
{
#if 0 
    Person * p1 = new Person();  /* 自己指向自己 */
    Person * p2 = new Student();  /* 父类指针指向子类 */

    /* 没有安全检测 */
    Student * stu1 = reinterpret_cast<Student *>(p1);
    std::cout<<"stu1:"<<std::endl;
    Student * stu2 = reinterpret_cast<Student *>(p2);
    std::cout<<"stu2:"<<std::endl;
#else
    /* p = 100 或者 p = 0X64 */
    /* 指针是8个字节 int只有4个字节 所以需要将int改为long  */
    int * p = reinterpret_cast<int *>(100);
    std::cout<<"p:"<<p<<std::endl;

    int num = reinterpret_cast<long>(p);
    std::cout<<"num:"<<num<<std::endl;
#endif

    return 0;
}
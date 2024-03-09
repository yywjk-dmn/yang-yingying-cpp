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
    //char * str = "hello world";

#if 0
    char * buffer = const_cast<char *>(str);
#elif 0
    /* 不适用 */
    char * buffer = dynamic_cast<char *>(str);
#else
    /* 非const转成const 运行时没有安全检测 */
    int a = 100;
    const int numa = static_cast<int>(a);
    std::cout<<numa<<std::endl;
#endif



    return 0;
}
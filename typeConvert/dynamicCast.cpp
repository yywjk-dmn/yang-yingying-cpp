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
    Person * p1 = new Student();
    p1->run();
    delete p1;


    Student * stu1 = (Student *)new Person();
    stu1->run();
    delete stu1;

    Person * p1 = new Person();  /* 自己指向自己 */
    Person * p2 = new Student();  /* 父类指针指向子类 */



#if 0
    /* 错误写法 */
    Student * stu1 = p1;
    Student * stu2 = p2;
#elif 0
    Student * stu1 = (Student *)p1;
#else
    /* 子类指针不能指向父类对象 内存问题 */
    Student * stu1 = dynamic_cast<Student *>(p1);
    std::cout<<"stu1:"<<std::endl;
    Student * stu2 = dynamic_cast<Student *>(p2);
    std::cout<<"stu2:"<<std::endl;
#endif

    Student * stu1 = (Student *)p1;
    stu1->run();
    /* 错误使用内存 踩内存 */
    stu1->m_score = 666;
    /* 
        内存泄漏：
        1.野指针
        2.molloc的空间没有得到释放
        3.踩内存 （）
    */

    return 0;
}
#include <iostream>
#include <memory>

class Person
{
public:
    Person()
    {
        std::cout << "Person()" << std::endl;
    }

    ~Person()
    {
        std::cout << "~Person()" << std::endl;
    }

public:
    void run()
    {
        std::cout << "Person run()" << std::endl;
    }
private:
    int m_age;
    char * m_name;
};


/* 模板 */
template <typename T>
class smartPtr
{
public:
    smartPtr(T * obj)
    {
        ptr = obj;
        // cout << "smartPtr()" << endl;
    }

    ~smartPtr()
    {
        delete ptr;
        // cout << "~smartPtr()" << endl;
    }

public:
    T * operator->()
    {
        return ptr;
    }

private:
    T * ptr;
};

int main()
{
#if 0
    /*  {}指的是一个作用域  */
    {
        /* 定义了一个指针 指向一个对象 如果不使用delete的话 就会出现内存泄漏 */
        Person *p2 = new Person[3];

        p2->run();
        /* 只有调用了delete才会调用析构 */
        delete [] p2;
    }
#endif


#if 1
    /* auto_ptr 的使用 原理和意思就是上面的代码 */
    /* 不能进行数组 会报无效的指针 所以弃用 */
    std::auto_ptr<Person> p1(new Person);    // p1 = new Person[]

    // p1->run()    // 1
    // p1.run()     // 2
    p1->run();
#endif


#if 1
    smartPtr<Person> sp(new Person);
    sp->run();
#endif


#if 0
    int * ptr = new int[100];
    delete [] ptr;
#endif

    return 0;
}
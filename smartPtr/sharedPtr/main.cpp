#include <iostream>
using namespace std;
#include <memory>

class Person
{
public:
    Person()
    {
        cout << "Person()" << endl;
    }

    ~Person()
    {
        cout << "~Person()" << endl;
    }

public:
    void run()
    {
        cout << "Person run()" << endl;
    }
private:
    int m_age;
    char * m_name;
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
    /* 不适用数组 会报无效的指针 所以弃用 */
    auto_ptr<Person> p1(new Person);    // p1 = new Person[]

    // p1->run()    // 1
    // p1.run()     // 2
    p1->run();
#endif

#if 0
    shared_ptr<Person> p2(new Person);
    p2->run();
    /* 适用于数组 */
    shared_ptr<Person> p3(new Person[3]{});
#else
    /* use_count引用计数 返回值是该函数引用的次数 */
    {
        shared_ptr<Person> p2;
        shared_ptr<Person> p3;
        {
            shared_ptr<Person> p1(new Person);
            p2 = p1;
            cout<<p1.use_count()<<endl;
        }

        cout<<"2222"<<endl;
    }
    cout<<"333"<<endl;

#endif
    return 0;
}
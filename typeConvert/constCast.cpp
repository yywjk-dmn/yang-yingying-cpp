#include <iostream>

class Person
{
public:
    Person()
    {
        std::cout<<"Pertson()"<<std::endl;
    }
    void run()
    {
        std::cout<<"run()"<<std::endl;
    }
private:
    int m_age;

};

int main()
{

    const char * str = "hello world";
#if 0
    /* C语言写法  强转 没问题 */
    char * buffer = (char *)str;
#else
    /* 将const 属性转换为非const 属性 */
    char * buffer = const_cast<char *>(str);
#endif
    /* 复合数据类型 */
    const Person *p1 = new Person();
#if 0
    /* c语言写法 */
    Person *p2 = (Person *)p1;
#else
    Person * p2 = const_cast<Person *>(p1);
#endif
    p2->run();
    

    return 0;
}
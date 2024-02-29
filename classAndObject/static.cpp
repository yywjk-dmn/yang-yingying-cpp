#include <iostream>

class Test
{
public:
    Test()
    {
        count++;
        std::cout<<"构造函数\n";
    }

    Test(const Test&t)
    {
        std::cout<<"拷贝构造"<<std::endl;
        /* 另外一种写法 */
        //p = new int(*t.p);

    }
    ~Test()
    {
        count--;
        std::cout<<"构造函数\n";
    }
public:
    static int count;
    int a;
};

/* 静态成员变量的初始化 */
int Test::count = 10;

int main()
{
    //std::cout<<Test::c<<std::endl;
    // Test t1;
    // t1.c = 10;
    // Test t2;
    // /* c的值为10  共享 */
    // std::cout<<t2.c<<std::endl;

    /* 一个简单的检查内存泄漏方法  要是输出为0则没有内存泄漏 */
    Test *t1 =new Test();
    Test *t2 =new Test();

    delete t1;
    delete t2;
    std::cout<<Test::count<<std::endl;

    return 0;
}
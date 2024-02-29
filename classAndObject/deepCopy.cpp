#include <iostream>


class Test
{
public:
    Test()
    {
        p = new int;
        std::cout<<"构造函数\n";
    }

    Test(const Test&t)
    {
        std::cout<<"拷贝构造"<<std::endl;
        p = new int;
        *p = *t.p;
        /* 另外一种写法 */
        //p = new int(*t.p);

    }
    ~Test()
    {
        delete p;
        std::cout<<"构造函数\n";
    }
private:
    int *p;
};

Test &func()
{
    /* 延长了生命周期 但是直接返回一个匿名对象 性能反而高 */
    static Test t;
    std::cout<<"------\n"<<std::endl;
    return t;
}
Test func1(Test& t)
{
    /* 传进来一个引用 有一个有名字的内存空间 所以会进行拷贝 */
    return t;
}

int main()
{
    Test t;
    Test t2 = t;

    /* 调用一个构造说明生成了一个对象 */
    /* 匿名对象：生命周期只有一行代码 */
    //Test();

    /* 没有用到拷贝函数  将这块没有名字的内存空间直接分配给对象 */
    Test t = Test();

    /* 相当于返回一个匿名对象 */
    Test t = func();

    /* 产生一个构造 一个拷贝构造 */
    Test t2 = func1(t);



    return 0;
}
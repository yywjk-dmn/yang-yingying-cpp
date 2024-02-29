#include <iostream>

class Test
{
public:
    Test()
    {
        std::cout<<"构造函数\n";
    }
    ~Test()
    {
        std::cout<<"构造函数\n";
    }
};

int main()
{
    Test *t = new Test();
    std::cout<<"-----------\n";
    Test *t1 = (Test *)malloc(sizeof(Test));

    /* 调用析构函数 */
    delete t;
    /* 不调用析构函数 */
    free(t);

    Test *t = new Test[3];
    delete []t;


    return 0;
}
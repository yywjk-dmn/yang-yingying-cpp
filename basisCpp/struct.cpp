#include <iostream>


struct stdTcpStudent
{
    int a;
    int b;
    /* 结构体中可以直接定义函数 */
    void setA(int num)
    {
        a = num;
    }
};

/* 用using来代替typedef来重命名一个结构体的名字 */
using TcpS = stdTcpStudent;

int main()
{
    /* 结构体的名字本身就作为类型 */
    TcpS s;
    s.b = 20;
    s.setA(10);

    std::cout<<s.a<<std::endl;
    std::cout<<s.b<<std::endl;


    return 0;
}
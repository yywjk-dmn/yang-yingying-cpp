#include <iostream>

namespace A
{
    const int num= 10;
}

namespace B
{
    const int num = 20;
}


int main()
{
    /* a的值不可以被改变 是因为在C++里 顺着a去找值 会在符号表里面找到a的值  */
    /* 所以在C++中 a是一个真常量 */
    const int a = 10;
    /* 常量指针 指针指向一个常量 */
    //const int *p = &a;
    /* 指针常量 指针是一个常量 */

    /* p取得是a的地址 会打出20并且给一个存储的空间 但是不会改变a的值 */
    int *p = (int *)&a;
    *p = 20;
    std::cout<<a<<std::endl;
    std::cout<<*p<<std::endl;

    /* define不可以被命名空间约束 会有重名的风险 所以尽量使用const */
    std::cout<<A::num<<std::endl;

    return 0;

}
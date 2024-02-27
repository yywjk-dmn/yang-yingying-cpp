#include <iostream>
/* 代表这个库来自于C语言 */
#include <cstring>
/* C++本身封装的关于字符串的库 */
#include <string>
using namespace std;/* 代表全局使用std的命名空间 但是不建议使用：会出现函数的歧义问题 */

/* 尾插函数 */
/* 命名空间可以放函数，也可以放变量 */
namespace  A
{
    void insertTail()
    {
        std::cout<<"first"<<std::endl;
    }
    int num = 10;
    /* 命名空间的嵌套式使用 */
    namespace B
    {
        int num = 10;
    }
}

namespace B
{
    void insertTail()
    {
        std::cout<<"second"<<std::endl;
    }
    int num = 20;

}


int main ()
{
    /* 调用A命名空间的函数 */
    A::insertTail;

    /* 调用B命名空间 */
    B::insertTail;

    /* 如果想要使用A下面的B下面的num */
    std::cout<<A::B::num<<std::endl;

    /* 使用命名空间 用这种表达方式范围越小越好 最好不要当作全局 */
    using namespace A;
    /* 使用命名空间的另一种表示 */
    std::cout<<A::num<<std::endl;
    return 0;

}
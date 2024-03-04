#include <iostream>

int num = 10;

int main()
{
    int num = 10;
    /* 这一行运用了域解析符'::' 代表输出全局变量 */
    std::cout<<::num<<std::endl;

    std::cout<<num<<std::endl;

    return 0;

}
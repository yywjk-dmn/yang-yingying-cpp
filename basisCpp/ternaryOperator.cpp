#include <iostream>

int main()
{
    int a = 90;
    int b = 100;
    /* 在C++中 三目运算符返回的是变量本身 */
    (a > b ? b : a) += 10;
    std::cout<<b<<std::endl;


    return 0;
}
#include <iostream>

/* 宏定义的常数不能定义类型 也就是说 系统默认是什么类型 就是什么类型 */
#define size 10

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;

}
                        
int main()
{
    std::cout<<add(1, 2)<<std::endl;


    return 0;
}
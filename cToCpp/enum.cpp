#include <iostream>

enum color
{
    white,
    balck,
    orgine
};

enum RGB
{
    red,
    green,
    blue
};
int mian()
{
    /* 是错误的 对类型控制的增强 */
    if (color::balck == RGB::green)
    {
        std::cout<<"equal"<<std::endl;
    }
    return 0;
}
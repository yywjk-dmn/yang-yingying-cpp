#include <iostream>
#include "stdMyString.h"


int main()
{
#if 0
    stdMyString s = "hello world";
    std::cout<<s<<std::endl;
    // stdMyString s1 = s;
    // std::cout<<s1<<std::endl;

    stdMyString s2;
    std::cout<<s2<<std::endl;
    s2[7] = 'p';
    std::cout<<s2<<std::endl;


    stdMyString s3 = "yangyingying";
    /* 为了连续赋值 给函数加了返回值 */
    //s3 = s2 = s;

    stdMyString s4 = s3 - "ying";
    s4 = s4 - "y";
    std::cout<<s4<<std::endl;
    stdMyString s5 = s3 - "j";
    std::cout<<s5<<std::endl;

    std::cin>>s;
    stdMyString S = "100";
    std::cout<<(int)S + 1<<std::endl;

    myStringList list;
    list += "zhangsan";
    list += "lisi";
    list += "yangyingying";
    list += "zhangshuo";

    std::cout<<list<<std::endl;
#endif

    stdMyString s("zhang,yangyingying");
    myStringList list = s.split(",");

    list -= "yang";
    list[1] = "hh";
    std::cout<<list<<std::endl;

    return 0;
}
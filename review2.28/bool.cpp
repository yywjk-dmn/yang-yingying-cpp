#include <iostream>

int main()
{
    int a;
    bool b = true;
    std::cout<<b<<std::endl;

    b = 4;
    a = b;
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;

    b = -4;
    a = b;
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;

    a =10;
    b = a;
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;

    b= 0;
    std::cout<<b<<std::endl;
    
    return 0;

}
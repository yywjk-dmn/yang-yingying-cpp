#include <iostream>


inline int func(int a)
{
    return a + 1;
}



int main()
{

    std::cout<<func(10)<<std::endl;

    return 0;
}
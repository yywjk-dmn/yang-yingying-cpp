#include <iostream>

int main()
{
    const int a = 10;
    /* 不会对const的值进行改变 */
    int *p = (int *)&a;
    *p = 20;

    std::cout<<a<<std::endl;



    return 0;
}
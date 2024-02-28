#include <iostream>

void func()
{
        const int a = 20;
}
void printA(char * str)
{

}
void func()
{
    #define A 10

    /* 撤销宏 */
    //#undef A
}



int main()
{
    const int b = 10;
    //printA(b);
    std::cout<<A<<std::endl;
    return 0;
}
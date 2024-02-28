#include <iostream>

int main()
{
    int a =10;
    int b= 20;

    (a > b ? a : b) = 40;
    printf("b = %d\n", b);


    return 0;
}
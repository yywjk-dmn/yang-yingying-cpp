#include <iostream>

int main()
{
    int a = 10;
    int &b = a;
    printf("a = %d, b= %p\n", &a, &b);

    b = 20;
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
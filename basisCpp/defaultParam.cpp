#include <iostream>
#include <cstring>

/* 默认参数在声明的时候添加  */
int add(int a, int b, int c = 0);
int add(int a, int b, int c)
{
    return a + b + c;
}
bool func(int a, char *errorMsg = NULL)
{
    if (errorMsg != NULL)
        strcpy(errorMsg, "connect error!");
    return false;

}

/* 占位参数 */
int add(int a, int b, int)
{
    return a + b;

}

int main()
{
    func(1);
    add(1, 23, 3);
    std::cout<<add(10, 20)<<std::endl;



    return 0;
}
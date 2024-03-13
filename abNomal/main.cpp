#include <iostream>
#define BUFFER_SIZE 10000


/* 异常声明 */
/* 会出现任何类型的异常 一下肯定会抛出任何类型的异常 */
void func()
{

}
void func2() noexcept(false)
{

}
/* 不会出现任何异常 以下三种都是肯定不会抛出异常 */
void func() throw()
{

}
void func3() noexcept
{

}
void func4() noexcept(true)
{
    
}

/* 只会出现int和double类型的异常 */
// void func() throw(int, double)
// {

// }
void test01()
{
    /* 异常的语法
        try
        {

        }
        catch(...)
        {

        }
        ...是捕捉任意异常
        如果程序出现错误 就不会运行出异常下面的代码
    
    
    */
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
            try
        {
            int * num = new int[0000000];
        }
        catch(...)
        {
            std::cout<<"内存不足"<<std::endl;
        }
    }
    /* 如果异常不被处理 程序就终止了 */
}

int myDivison(int val1, int val2)
{
    if (val2 == 0)
    {
        #if 0
        throw "除数不能为0";
        #else
        throw 666;
        #endif
    }
    return val1 / val2;

}

/* 捕捉异常 */
int main()
{
    try
    {
        /* 主动抛出异常 */
        myDivison(100, 0);
    }
    catch(const char * str)
    {
        std::cout<<"函数主动抛出异常"<<str<<std::endl;
    }
    catch(int code)
    {
        std::cout<<"函数主动抛出异常"<<code<<std::endl;
    }

    
    


    return 0;
}
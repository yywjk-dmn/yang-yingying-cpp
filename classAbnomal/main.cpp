#include <iostream>
#define BUFFER_SIZE 10000

class Exception
{
public:
    virtual std::string what() = 0;
};

class DivideException : public Exception
{
public:
    std::string what()
    {
        std::cout<<"不能除0"<<std::endl;
        return "不能除0";
    }
};
class MemoryFlowException : public Exception
{
public:
    std::string what()
    {
        std::cout<<"内存溢出"<<std::endl;
        return "内存溢出";
    }
};

int divide(int val1, int val2) noexcept(false)
{
    if (val2 == 0)
    {
        throw DivideException();
    }

    return val1 / val2;
}

/* 捕捉异常 */
int main()
{
    try
    {
        /* 主动抛出异常 */
        int val1 = 100;
        int val2 = 5;
        int res = divide(val1, val2);
        std::cout<<res<<std::endl;
    }
    catch(const Exception& e)
    {
        //std::cout<<e.what()<<std::endl;
    }

    
    


    return 0;
}
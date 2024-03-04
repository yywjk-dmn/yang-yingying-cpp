#include <iostream>

class Test
{
public:
    Test(int a):a(a){}
    /* 保护返回值 */
    const int * func()
    {
        return &a;
    }
    /* 保护传入的引用形参 */
    void func2(const int &a)
    {
        
    }

    /* 该函数内不允许对成员变量做修改 */
    void func3() const
    {

    }




private:
    int a;

};

int main()
{
    Test t(10);
    const int *p = t.func();



    return 0;
}
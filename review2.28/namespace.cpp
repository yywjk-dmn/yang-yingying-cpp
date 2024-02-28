#include <iostream>
#include <cstdio>

namespace NamespaseA
{
    int a;
    int add(int a, int b)
    {
        return a + b;
    }
}

namespace NamespaseB
{
    namespace NamespaseC
    {
        struct teacher
        {
            int id;
            char name[20];
        };
    }
    int a;
}

int add(int a, int b)
{
    return a + b + 10;
}

int main()
{
    {
        int ret = NamespaseA::add(2, 4);
        printf("ret = %d\n", ret);
    }

    {
        using namespace NamespaseA;

        int ret = NamespaseA::add(2, 3);
        printf("ret = %d\n", ret);

        /* 使用默认空间的add 也就是外面的 a + b + 10    */
        ret = ::add(2, 3);
        printf("ret = %d\n", ret);
    }

    {
        using namespace NamespaseA;
        a = 10;
        printf("a = %d\n", NamespaseA::a);
    }

    {
        struct NamespaseB::NamespaseC::teacher t1;
        t1.id = 10;
        return 0; 
    }
    return 0;
}
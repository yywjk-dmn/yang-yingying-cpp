#include <iostream>
#include <string>
#include <cstring>


void func(int pVal)
{
    std::cout<<"pVal"<<std::endl;
}
void func(int * pVal)
{
    std::cout<<"*pVal"<<std::endl;
}
int main()
{
#if 0
    /* auto 一种通用类型 */
    int a = 100;
    auto num = 666;
    std::cout<<"num:"<<num<<std::endl;

    auto str = "hello world";
    std::cout<<"str:"<<str<<std::endl;

    auto * pNum = &a;
    std::cout<<"*pNUm:"<<*pNum<<std::endl;
#endif

#if 0
    /* decltype可以获取变量的类型 再去定义一个新的相同类型的变量 */
    int num = 666;
    decltype(num) value = 777;
    std::cout<<num<<std::endl;
    
    string str = "hhhhhh";
    decltype(str) ptr = "imnothappy";
    std::cout<<ptr<<std::endl;

    /* 结合auto */
    auto val = "hahaha";
    decltype(auto) buf = "jjjjj";
    std::cout<<buf<<std::endl;
#endif

#if 0
    /* 因为有重载 所以要用nullptr 二义性 */
    func(NULL);
    func(nullptr);
#endif

#if 1
    /* 数组的长度/数组的第一个的大小  ==   数组有多少个元素 */
    int array1[5] = {11, 22, 33, 44, 55};
    std::cout<<sizeof(array1) / sizeof(array1[0])<<std::endl;
    int array2[] = {11, 22, 33, 44, 55};
    std::cout<<sizeof(array2) / sizeof(array2[0])<<std::endl;
    int array3[] = {11, 22, 33, 44, 55};
    std::cout<<sizeof(array3) / sizeof(array3[0])<<std::endl;

    for (int idx = 0; idx < sizeof(array2) / sizeof(array2[0]); idx++)
    {
        std::cout<<array2[idx]<<std::endl;
    }
    /* item就是array3里面的元素 直接输出就好 */
    for (int item : array3)
    {
        std::cout<<item<<std::endl;
    }
#endif

#if 1


#endif
    return 0;
}
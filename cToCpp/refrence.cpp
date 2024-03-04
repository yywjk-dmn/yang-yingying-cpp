#include <iostream>

#if 0
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp; 
}
#endif

void swap(int &a, int &b)
{
    int temp = 0;
    a = b;
    b = temp;
}

void show(const int &a)
{
    std::cout<<a<<std::endl;

}




int main()
{
    #if 0
    int a = 10;
    int b = 20;
    swap(&a, &b);
    std::cout<<a<<","<<b<<std::endl;

    int a = 10;
    /* 引用定义必须初始化 初始化以后不会改变朝向 不会改变别人的小名 */
    int &b = a;
    int c = 20;
    /* 将c的值给b b就是a 所以改变了a的值 */
    b = c;
    std::cout<<b<<std::endl;
    #endif

    int a = 10;
    int b = 20;
    swap(a, b);
    std::cout<<a<<","<<b<<std::endl;

    int a = 90;
    int &b = a;

    show(10);



    return 0;
}
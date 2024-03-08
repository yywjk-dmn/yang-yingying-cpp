#include <iostream>

class Point
{
public:
    int m_x;
    int m_y;
};

/* 引入模板 可以解决类型不匹配的问题 */
template <typename T>

T add(T val1, T val2)
{
    return val1 + val2;
}

#if 0
float add(float val1, float val2)
{
    return val1 + val2;
}

Point add(Point val1, Point val2)
{
    Point point3;
    /* todo.... */
}
#endif

int main()
{
    int num1 = 100;
    int num2 = 90;
    int sum = add(num1, num2);

    float v1 = 7.5;
    float v2 = 8.9;
    float va = add(v1 , v2);
    std::cout<<va<<std::endl;

    Point point1;
    point1.m_x = 3;
    point1.m_y = 4;

    Point point2;
    point2.m_x = 30;
    point2.m_y = 40;


    return 0;

}
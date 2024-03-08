#include <iostream>
#include "main.hpp"

class Point
{
public:
    //friend std::ostream &operator<<(std::ostream &);
private:
    int m_x;
    int m_y;
public:
    Point(int x, int y) : m_x(x), m_y(y){}
    Point operator+(const Point & p);
};

Point Point::operator+(const Point &p)
{
    return Point(m_x + p.m_x, m_y + p.m_y);
}

int main()
{
    std::cout<<add<int> (10, 20)<<std::endl;
    /* 也可以直接 add(10, 20) */

    std::cout<<add<float> (6.6, 7.8)<<std::endl;

    Point p1(1, 1);
    Point p2(2, 2);
    Point p3 = add<Point> (p1, p2);

  
    return 0;

}



#include <iostream>
#include <cmath>

int gcd(int x, int y)
{
    int max = std::max(x, y);
    int min = std::min(x, y);

    int r = max % min;
    while (r != 0)
    {
        max = min;
        min = r;
        r = max % min;
    }
    return min;

}
class Point
{
public:
    friend double distance(const Point& p1, const Point& p2);
    friend class Line;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;

    }
    void show()
    {
        std::cout<<"("<<x<<","<<y<<")"<<std::endl;
    }
private:
    int x;
    int y;
};

double distance(const Point& p1, const Point& p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

}

class Line
{

public:
    
    Line(double A, double B, double C):A(A), B(B), C(C){}
    Line(const Point& p1, const Point& p2)
    {
        A = p1.y - p2.y;
        B = p2.x - p1.x;
        C = p1.x * p2.y - p1.y * p2.x;

        int r = gcd(gcd(A, B), C);
        std::cout<<r<<std::endl;
        A /= r;
        B /= r;
        C /= r;

     
    }

    double distance(const Point& p)
    {
        double distance = abs(A * p.x + B * p.y + C) / (sqrt(A * A + B * B));
        return 0.0;
    }

    void show()
    {
        if (A == 1 && B != 1)
            std::cout<<A<<"x+"<<B<<"y+"<<C<<"=0"<<std::endl;
        else if (B == 1 && A != 1)
            std::cout<<A<<"x+"<<B<<"y+"<<C<<"c"<<std::endl;
    }
private:
    double A;
    double B;
    double C;

};

class circle
{
private:
    Point p;
    int len;
};


int main()
{
    Point p1(1,1);
    Point p2(2,2);
    Line l(p1, p2);

    std::cout<<distance(p1, p2)<<std::endl;

    std::cout<<1.0 * l.distance(p1)<<std::endl;


}
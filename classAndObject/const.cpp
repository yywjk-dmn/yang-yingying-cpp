#include <iostream>

class Test
{
public:
    Test(int a, int b):m_a(a),b(b)
    {
    }
    void show()
    {
        std::cout<<m_a<<std::endl;
    }
private:
    int b;
    const int m_a;

};

int main()
{



    return 0;
}
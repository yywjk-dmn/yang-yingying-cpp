#include <iostream>

class Interger
{
public:
    explicit Interger(int a)
    {
        std::cout<<"带参构造\n";
        m_a = a;
    }
    ~Interger()
    {
        std::cout<<"无参构造\n";
    }
    int getInterger()
    {
        return m_a;
    }
private:
    int m_a;
};


int mian()
{
    Interger i(10);
    /* i = Interger（20）构造函数的隐式转换  数值会被隐式构造成类的对象 */
    //i = 20;
    std::cout<<i.getInterger()<<std::endl;


    return 0;
}